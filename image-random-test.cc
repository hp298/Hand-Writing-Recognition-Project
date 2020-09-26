//========================================================================
// image-random-test.cc
//========================================================================
// Test program that includes directed tests for Image.

#include "Image.h"
#include "utst.h"
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// test_case_1_simple
//------------------------------------------------------------------------

void test_case_1_simple()
{
  std::printf( "\n%s\n", __func__ );

  const char labels[10] = {'0', '1', '2', '3', '4',
                           '5', '6', '7', '8', '9'};
  // Construct a vector
  size_t iterations = 10;

  for ( size_t i = 0; i < iterations; i++ ) {
    // Choose image dimension from 2 to 41
    size_t dim  = rand() % 40 + 2;
    size_t size = dim * dim;
    int*   data = new int[size];

    // For calculating intensity
    int intensity = 0;

    for ( size_t j = 0; j < size; j++ ) {
      data[j] = rand() % 100;
      intensity += data[j];
    }

    Vector<int> vec( data, size );
    Image       img( vec, dim, dim );

    // Make sure img deepcopies
    vec = Vector<int>();

    // Check vector initialization is correct
    size_t ind = 0;
    for ( size_t j = 0; j < dim; j++ ) {
      for ( size_t k = 0; k < dim; k++ ) {
        UTST_ASSERT_INT_EQ( img.at( k, j ), data[ind] );
        ind++;
      }
    }

    UTST_ASSERT_INT_EQ( img.get_intensity(), intensity );

    int label = rand() % 10;

    // Check get_label and set_label
    UTST_ASSERT_TRUE( img.get_label() == '?' );
    img.set_label( labels[label] );
    UTST_ASSERT_TRUE( img.get_label() == labels[label] );

    delete[] data;
  }
}

//------------------------------------------------------------------------
// test_case_2_copy
//------------------------------------------------------------------------

void test_case_2_copy()
{
  std::printf( "\n%s\n", __func__ );

  const char labels[10] = {'0', '1', '2', '3', '4',
                           '5', '6', '7', '8', '9'};

  // Construct a vector
  size_t iterations = 10;

  for ( size_t i = 0; i < iterations; i++ ) {
    size_t dim       = rand() % 40 + 2;
    size_t size      = dim * dim;
    int*   data      = new int[size];
    int    intensity = 0;

    for ( size_t j = 0; j < size; j++ ) {
      data[j] = rand() % 100;
      intensity += data[j];
    }

    Vector<int> vec( data, size );
    Image       img0( vec, dim, dim );

    // Change the vector
    vec = Vector<int>();

    int label = rand() % 10;

    img0.set_label( labels[label] );

    // Use default assignment operator
    Image img1;
    img1 = img0;

    size_t ind = 0;
    for ( size_t j = 0; j < dim; j++ ) {
      for ( size_t k = 0; k < dim; k++ ) {
        UTST_ASSERT_INT_EQ( img0.at( k, j ), data[ind] );
        UTST_ASSERT_INT_EQ( img1.at( k, j ), data[ind] );
        ind++;
      }
    }

    UTST_ASSERT_INT_EQ( img0.get_intensity(), intensity );
    UTST_ASSERT_INT_EQ( img1.get_intensity(), intensity );

    UTST_ASSERT_TRUE( img0.get_label() == labels[label] );
    UTST_ASSERT_TRUE( img1.get_label() == labels[label] );

    delete[] data;
  }
}

//------------------------------------------------------------------------
// test_case_3_compare
//------------------------------------------------------------------------

void test_case_3_compare()
{
  std::printf( "\n%s\n", __func__ );

  const size_t iterations = 10;

  for ( size_t i = 0; i < iterations; i++ ) {
    // Choose image dimensions from 2 to 41
    size_t dim1 = rand() % 40 + 2;
    size_t dim2 = rand() % 40 + 2;

    size_t num_images = rand() % 10 + 1;
    size_t size       = dim1 * dim2;
    int**  data       = new int*[num_images];
    int*   intensity  = new int[num_images];
    Image* images     = new Image[num_images];

    for ( size_t j = 0; j < num_images; j++ ) {
      data[j] = new int[size];

      // Set intensity for image j to 0
      intensity[j] = 0;

      for ( size_t k = 0; k < size; k++ ) {
        data[j][k] = rand() % 100;
        intensity[j] += data[j][k];
      }

      Vector<int> vec( data[j], size );
      images[j] = Image( vec, dim1, dim2 );

      delete[] data[j];
    }

    // Check vector_compare for random vectors
    for ( size_t j = 0; j < 20; j++ ) {
      int rand_i1 = rand() % num_images;
      int rand_i2 = rand() % num_images;

      // Check all boolean operators
      if ( intensity[rand_i1] == intensity[rand_i2] ) {
        UTST_ASSERT_FALSE( images[rand_i1] < images[rand_i2] );
        UTST_ASSERT_FALSE( images[rand_i1] > images[rand_i2] );
        UTST_ASSERT_TRUE( images[rand_i1] <= images[rand_i2] );
        UTST_ASSERT_TRUE( images[rand_i1] >= images[rand_i2] );
        UTST_ASSERT_TRUE( images[rand_i1] == images[rand_i2] );
      }
      else if ( intensity[rand_i1] > intensity[rand_i2] ) {
        UTST_ASSERT_FALSE( images[rand_i1] < images[rand_i2] );
        UTST_ASSERT_FALSE( images[rand_i1] <= images[rand_i2] );
        UTST_ASSERT_FALSE( images[rand_i1] == images[rand_i2] );
        UTST_ASSERT_TRUE( images[rand_i1] > images[rand_i2] );
        UTST_ASSERT_TRUE( images[rand_i1] >= images[rand_i2] );
      }
      else {
        UTST_ASSERT_FALSE( images[rand_i1] > images[rand_i2] );
        UTST_ASSERT_FALSE( images[rand_i1] >= images[rand_i2] );
        UTST_ASSERT_FALSE( images[rand_i1] == images[rand_i2] );
        UTST_ASSERT_TRUE( images[rand_i1] < images[rand_i2] );
        UTST_ASSERT_TRUE( images[rand_i1] <= images[rand_i2] );
      }
    }

    delete[] images;
    delete[] intensity;
    delete[] data;
  }
}

//------------------------------------------------------------------------
// test_case_4_exceptions
//------------------------------------------------------------------------

void test_case_4_exceptions()
{
  std::printf( "\n%s\n", __func__ );

  const int iterations = 100;

  for ( size_t i = 0; i < iterations; i++ ) {
    // Choose image dimensions from 2 to 41
    size_t dim1 = rand() % 40 + 2;
    size_t dim2 = rand() % 40 + 2;
    size_t size = dim1 * dim2;

    // Initialize vec
    int*      data = new int[size];
    Vector<int> vec( data, size );

    // Try constructing an image that has a size greater than data size
    bool flag = false;
    try {
      Image img( vec, dim1 + 1, dim2 + 1 );
    } catch ( ece2400::InvalidArgument e ) {
      flag = true;
    }
    UTST_ASSERT_TRUE( flag );

    // Choose random dimension that can go over dimension sizes, and
    // test if invalid at throws exception
    size_t rand_dim1 = rand() % ( dim1 * 2 );
    size_t rand_dim2 = rand() % ( dim2 * 2 );
    flag             = false;
    try {
      Image img( vec, dim1, dim2 );
      img.at( rand_dim1, rand_dim2 );
    } catch ( ece2400::OutOfRange e ) {
      flag = true;
    }

    if ( rand_dim1 >= dim1 || rand_dim2 >= dim2 ) {
      UTST_ASSERT_TRUE( flag );
    }
    else {
      UTST_ASSERT_FALSE( flag );
    }

    delete[] data;
  }
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( ( __n == 0 ) || ( __n == 1 ) ) test_case_1_simple();
  if ( ( __n == 0 ) || ( __n == 2 ) ) test_case_2_copy();
  if ( ( __n == 0 ) || ( __n == 3 ) ) test_case_3_compare();
  if ( ( __n == 0 ) || ( __n == 4 ) ) test_case_4_exceptions();

  printf("\n");
  return 0;
}
