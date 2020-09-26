//========================================================================
// vector-image-random-test.cc
//========================================================================
// This file contains random tests for Vector<Image>

#include "Image.h"
#include "Vector.h"
#include "vector-random-test.h"
#include "utst.h"

//------------------------------------------------------------------------
// Object Creation Functions
//------------------------------------------------------------------------
// All of the generic test functions are templated by an "object
// creation" function which should take as a parameter an integer and
// return a newly created object. For an Image, the object creation
// function can set each pixel value based on the given integer.

Image mk_1x1( int value )
{
  int data[] = { value };
  Vector<int> vec( data, 1 );
  return Image( vec, 1, 1 );
}

Image mk_3x3( int value )
{
  int data[] =
    { value-2, value-1, value-2,
      value-1, value,   value-1,
      value-2, value-1, value-2 };

  Vector<int> vec( data, 9 );
  return Image( vec, 3, 3 );
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  printf("\n Testing with 1x1 images \n");

  if ( !__n || ( __n ==  1 ) ) test_case_push_back_random<Image>(1,&mk_1x1);
  if ( !__n || ( __n ==  2 ) ) test_case_copy_random<Image>(2,&mk_1x1);
  if ( !__n || ( __n ==  3 ) ) test_case_construct_random<Image>(3,&mk_1x1);
  if ( !__n || ( __n ==  4 ) ) test_case_find_closest_random<Image>(4,&mk_1x1);
  if ( !__n || ( __n ==  5 ) ) test_case_general_random<Image>(5,&mk_1x1);

  printf("\n\n Testing with 3x3 images \n");

  if ( !__n || ( __n ==  6 ) ) test_case_push_back_random<Image>(6,&mk_3x3);
  if ( !__n || ( __n ==  7 ) ) test_case_copy_random<Image>(7,&mk_3x3);
  if ( !__n || ( __n ==  8 ) ) test_case_construct_random<Image>(8,&mk_3x3);
  if ( !__n || ( __n ==  9 ) ) test_case_find_closest_random<Image>(9,&mk_3x3);
  if ( !__n || ( __n == 10 ) ) test_case_general_random<Image>(10,&mk_3x3);

  printf("\n");
  return 0;
}
