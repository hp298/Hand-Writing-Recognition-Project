//========================================================================
// sort-image-directed-tests.c
//========================================================================
// This file contains the tests for the sort function with images

#include "Image.h"
#include "sort.h"
#include "sort-directed-test.h"
#include "utst.h"

#include <stdio.h>
#include <stdlib.h>

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

  if ( !__n || ( __n == 1  ) ) test_case_helper<Image>(1,&mk_1x1);
  if ( !__n || ( __n == 2  ) ) test_case_five_element<Image>(2,&mk_1x1);
  if ( !__n || ( __n == 3  ) ) test_case_empty<Image>(3,&mk_1x1);
  if ( !__n || ( __n == 4  ) ) test_case_one_element<Image>(4,&mk_1x1);
  if ( !__n || ( __n == 5  ) ) test_case_two_elements<Image>(5,&mk_1x1);
  if ( !__n || ( __n == 6  ) ) test_case_three_elements<Image>(6,&mk_1x1);
  if ( !__n || ( __n == 7  ) ) test_case_even_size_array<Image>(7,&mk_1x1);
  if ( !__n || ( __n == 8  ) ) test_case_odd_size_array<Image>(8,&mk_1x1);
  if ( !__n || ( __n == 9  ) ) test_case_almost_sorted<Image>(9,&mk_1x1);
  if ( !__n || ( __n == 10 ) ) test_case_sorted_ascending<Image>(10,&mk_1x1);
  if ( !__n || ( __n == 11 ) ) test_case_sorted_descending<Image>(11,&mk_1x1);
  if ( !__n || ( __n == 12 ) ) test_case_few_unique<Image>(12,&mk_1x1);

  printf("\n\n Testing with 3x3 images \n");

  if ( !__n || ( __n == 13 ) ) test_case_helper<Image>(13,&mk_3x3);
  if ( !__n || ( __n == 14 ) ) test_case_five_element<Image>(14,&mk_3x3);
  if ( !__n || ( __n == 15 ) ) test_case_empty<Image>(15,&mk_3x3);
  if ( !__n || ( __n == 16 ) ) test_case_one_element<Image>(16,&mk_3x3);
  if ( !__n || ( __n == 17 ) ) test_case_two_elements<Image>(17,&mk_3x3);
  if ( !__n || ( __n == 18 ) ) test_case_three_elements<Image>(18,&mk_3x3);
  if ( !__n || ( __n == 19 ) ) test_case_even_size_array<Image>(19,&mk_3x3);
  if ( !__n || ( __n == 20 ) ) test_case_odd_size_array<Image>(20,&mk_3x3);
  if ( !__n || ( __n == 21 ) ) test_case_almost_sorted<Image>(21,&mk_3x3);
  if ( !__n || ( __n == 22 ) ) test_case_sorted_ascending<Image>(22,&mk_3x3);
  if ( !__n || ( __n == 23 ) ) test_case_sorted_descending<Image>(23,&mk_3x3);
  if ( !__n || ( __n == 24 ) ) test_case_few_unique<Image>(24,&mk_3x3);

  printf("\n");
  return 0;
}
