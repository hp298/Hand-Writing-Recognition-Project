//========================================================================
// vector-random-test.h
//========================================================================
// This file contains generic random tests for vectors. All of the
// generic test functions are templated by an "object creation" function
// which should take as a parameter an integer and return a newly created
// object. For integers, the object creation function can just be the
// identity function. For images, the object creation function can create
// a small image and initialize the pixels based on the given integer.

#include "Vector.h"
#include "utst.h"

//------------------------------------------------------------------------
// test_case_push_back_random
//------------------------------------------------------------------------
// A random test case that tests push back.

template < typename T, typename Func >
void test_case_push_back_random( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );
  srand( 0xdeadbeef );

  for ( size_t i = 0; i < 10; i++ ) {

    Vector<T> vec;

    size_t size = rand() % 100;
    T*     data = new T[size];

    printf( "\n - [ -note- ] size = %lu\n", size );

    for ( size_t j = 0; j < size; j++ ) {
      T value = f(rand() % 100000);
      vec.push_back( value );
      data[j] = value;
    }

    UTST_ASSERT_INT_EQ( vec.size(), size );

    // Check vector against array that has same elements

    for ( size_t j = 0; j < size; j++ ) {
      UTST_ASSERT_TRUE( vec.at(j) == data[j] );
      UTST_ASSERT_TRUE( vec[j]    == data[j] );
    }

    delete[] data;
  }
}

//------------------------------------------------------------------------
// test_case_copy_random
//------------------------------------------------------------------------
// A random test case that tests copy constructor and assignment operator.

template < typename T, typename Func >
void test_case_copy_random( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );
  srand( 0xdeadbeef );

  for ( size_t i = 0; i < 10; i++ ) {

    Vector<T> vec0;
    Vector<T> vec1;

    size_t size  = rand() % 100;
    T*     data0 = new T[size];

    printf( "\n - [ -note- ] size = %lu\n", size );

    for ( size_t j = 0; j < size; j++ ) {
      T value = f(rand() % 100000);
      vec0.push_back( value );
      data0[j] = value;
    }

    // Assignment operator

    vec1 = vec0;

    // Copy constructor

    Vector<T> vec2( vec1 );

    // Add more elements to vec0 and vec1

    size_t size1 = rand() % 100;
    T* data1     = new T[size1];

    for ( size_t j = 0; j < size1; j++ ) {
      T value = f(rand() % 100000);
      vec1.push_back( value );
      vec2.push_back( value );
      data1[j] = value;
    }

    UTST_ASSERT_INT_EQ( vec0.size(), size );
    UTST_ASSERT_INT_EQ( vec1.size(), size + size1 );
    UTST_ASSERT_INT_EQ( vec2.size(), size + size1 );

    // Check the copied elements

    for ( size_t j = 0; j < size; j++ ) {
      UTST_ASSERT_TRUE( vec0.at(j) == data0[j] );
      UTST_ASSERT_TRUE( vec1.at(j) == data0[j] );
      UTST_ASSERT_TRUE( vec2.at(j) == data0[j] );
    }

    // Check additional elements for vec0 and vec1

    for ( size_t j = 0; j < size1; j++ ) {
      UTST_ASSERT_TRUE( vec1.at( size + j ) == data1[j] );
      UTST_ASSERT_TRUE( vec2.at( size + j ) == data1[j] );
    }

    delete[] data0;
    delete[] data1;
  }
}

//------------------------------------------------------------------------
// test_case_construct_random
//------------------------------------------------------------------------
// A random test case that tests construct Vector<T> from an array.

template < typename T, typename Func >
void test_case_construct_random( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );
  srand( 0xdeadbeef );

  for ( size_t i = 0; i < 10; i++ ) {

    size_t size = rand() % 100;
    T*     data = new T[size];

    printf( "\n - [ -note- ] size = %lu\n", size );

    for ( size_t j = 0; j < size; j++ )
      data[j] = f(j);

    // Construct the vector from an array
    Vector<T> vec( data, size );

    // Modify the array to test deepcopy
    for ( size_t j = 0; j < size; j++ )
      data[j] = f(size+1);

    // Check that the value inside the vector is not modified
    for ( size_t j = 0; j < size; j++ )
      UTST_ASSERT_TRUE( vec.at(j) == f(j) );

    delete[] data;
  }
}

//------------------------------------------------------------------------
// test_case_find_closest_random
//------------------------------------------------------------------------
// A random test case that tests copy constructor and assignment operator.

template < typename T, typename Func >
void test_case_find_closest_random( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );
  srand( 0xdeadbeef );

  for ( size_t i = 0; i < 10; i++ ) {

    size_t size = rand() % 100;
    T*     data = new T[size];

    printf( "\n - [ -note- ] size = %lu\n", size );

    int offset = rand() % 10 + 10;

    for ( size_t j = 0; j < size; j++ )
      data[j] = f(j*offset);

    Vector<T> vec( data, size );

    // Check the closest value for the multiples of offset plus one
    for ( size_t j = 0; j < size; j++ )
      UTST_ASSERT_TRUE( vec.find_closest( f(j*offset+1) ) == f(j*offset) );

    delete[] data;
  }
}

//------------------------------------------------------------------------
// test_case_general_random
//------------------------------------------------------------------------

template < typename T, typename Func >
void test_case_general_random( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );
  srand( 0xdeadbeef );

  for ( size_t i = 0; i < 10; i++ ) {

    size_t size = rand() % 100;
    T*     data = new T[size];

    printf( "\n - [ -note- ] size = %lu\n", size );

    Vector<T> vec;

    for ( size_t j = 0; j < size; j++ ) {
      data[j] = f(j);
      vec.push_back(f(j));
      UTST_ASSERT_INT_EQ( vec.size(), j+1 );
    }

    // Test at and find, expecting successful
    for ( size_t j = 0; j < size; j++ ) {
      UTST_ASSERT_TRUE( vec.find(f(j)) );
      UTST_ASSERT_TRUE( vec.at(j) == f(j) );
    }

    // Test find, expecting not successful
    for ( size_t j = size; j < 2*size; j++ )
      UTST_ASSERT_FALSE( vec.find(f(j)) );

    // Test find_closest
    for ( size_t j = 0; j < size; j++ )
      UTST_ASSERT_TRUE( vec.find_closest(f(j)) == f(j) );

    // Test find_closets for values beyond 0 to size
    UTST_ASSERT_TRUE( vec.find_closest(f(size)) == f(size-1) );
    UTST_ASSERT_TRUE( vec.find_closest(f(-1))   == f(0)      );

    delete[] data;
  }
}

