//========================================================================
// table-image-directed-test.cc
//========================================================================
// This file contains directed tests for Table<Image>

#include "Image.h"
#include "Table.h"
#include "table-directed-test.h"
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

  if ( !__n || ( __n ==  1 ) ) test_case_simple_add<Image>(1,&mk_1x1);
  if ( !__n || ( __n ==  2 ) ) test_case_2bin_add<Image>(2,&mk_1x1);
  if ( !__n || ( __n ==  3 ) ) test_case_duplicate_add<Image>(3,&mk_1x1);
  if ( !__n || ( __n ==  4 ) ) test_case_empty_bin<Image>(4,&mk_1x1);
  if ( !__n || ( __n ==  5 ) ) test_case_construct_empty<Image>(5,&mk_1x1);
  if ( !__n || ( __n ==  6 ) ) test_case_find_simple<Image>(6,&mk_1x1);
  if ( !__n || ( __n ==  7 ) ) test_case_find_empty<Image>(7,&mk_1x1);
  if ( !__n || ( __n ==  8 ) ) test_case_find_closest<Image>(8,&mk_1x1);
  if ( !__n || ( __n ==  9 ) ) test_case_copy_v1<Image>(9,&mk_1x1);
  if ( !__n || ( __n == 10 ) ) test_case_copy_v2<Image>(10,&mk_1x1);
  if ( !__n || ( __n == 11 ) ) test_case_copy_empty<Image>(11,&mk_1x1);
  if ( !__n || ( __n == 12 ) ) test_case_assignment<Image>(12,&mk_1x1);
  if ( !__n || ( __n == 13 ) ) test_case_assignment_diff_nbins<Image>(13,&mk_1x1);
  if ( !__n || ( __n == 14 ) ) test_case_assignment_to_empty<Image>(14,&mk_1x1);
  if ( !__n || ( __n == 15 ) ) test_case_assignment_from_empty<Image>(15,&mk_1x1);
  if ( !__n || ( __n == 16 ) ) test_case_assignment_empty<Image>(16,&mk_1x1);
  if ( !__n || ( __n == 17 ) ) test_case_assignment_self<Image>(17,&mk_1x1);
  if ( !__n || ( __n == 18 ) ) test_case_general<Image>(18,&mk_1x1);

  printf("\n\n Testing with 3x3 images \n");

  if ( !__n || ( __n == 19 ) ) test_case_simple_add<Image>(19,&mk_3x3);
  if ( !__n || ( __n == 20 ) ) test_case_2bin_add<Image>(20,&mk_3x3);
  if ( !__n || ( __n == 21 ) ) test_case_duplicate_add<Image>(21,&mk_3x3);
  if ( !__n || ( __n == 22 ) ) test_case_empty_bin<Image>(22,&mk_3x3);
  if ( !__n || ( __n == 23 ) ) test_case_construct_empty<Image>(23,&mk_3x3);
  if ( !__n || ( __n == 24 ) ) test_case_find_simple<Image>(24,&mk_3x3);
  if ( !__n || ( __n == 25 ) ) test_case_find_empty<Image>(25,&mk_3x3);
  if ( !__n || ( __n == 26 ) ) test_case_find_closest<Image>(26,&mk_3x3);
  if ( !__n || ( __n == 27 ) ) test_case_copy_v1<Image>(27,&mk_3x3);
  if ( !__n || ( __n == 28 ) ) test_case_copy_v2<Image>(28,&mk_3x3);
  if ( !__n || ( __n == 29 ) ) test_case_copy_empty<Image>(29,&mk_3x3);
  if ( !__n || ( __n == 30 ) ) test_case_assignment<Image>(30,&mk_3x3);
  if ( !__n || ( __n == 31 ) ) test_case_assignment_diff_nbins<Image>(31,&mk_3x3);
  if ( !__n || ( __n == 32 ) ) test_case_assignment_to_empty<Image>(32,&mk_3x3);
  if ( !__n || ( __n == 33 ) ) test_case_assignment_from_empty<Image>(33,&mk_3x3);
  if ( !__n || ( __n == 34 ) ) test_case_assignment_empty<Image>(34,&mk_3x3);
  if ( !__n || ( __n == 35 ) ) test_case_assignment_self<Image>(35,&mk_3x3);
  if ( !__n || ( __n == 36 ) ) test_case_general<Image>(36,&mk_3x3);

  printf("\n");
  return 0;
}
