//========================================================================
// sort-int-directed-tests.c
//========================================================================
// This file contains the tests for the sort function with ints

#include "sort.h"
#include "sort-directed-test.h"
#include "utst.h"

#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------
// Object Creation Function
//------------------------------------------------------------------------
// All of the generic test functions are templated by an "object
// creation" function which should take as a parameter an integer and
// return a newly created object. For integers, the object creation
// function can just be the identity function.

int mk_int( int x )
{
  return x;
}

//------------------------------------------------------------------------
// main
//------------------------------------------------------------------------

int main( int argc, char** argv )
{
  __n = ( argc == 1 ) ? 0 : atoi( argv[1] );

  if ( !__n || ( __n == 1  ) ) test_case_helper<int>(1,&mk_int);
  if ( !__n || ( __n == 2  ) ) test_case_five_element<int>(2,&mk_int);
  if ( !__n || ( __n == 3  ) ) test_case_empty<int>(3,&mk_int);
  if ( !__n || ( __n == 4  ) ) test_case_one_element<int>(4,&mk_int);
  if ( !__n || ( __n == 5  ) ) test_case_two_elements<int>(5,&mk_int);
  if ( !__n || ( __n == 6  ) ) test_case_three_elements<int>(6,&mk_int);
  if ( !__n || ( __n == 7  ) ) test_case_even_size_array<int>(7,&mk_int);
  if ( !__n || ( __n == 8  ) ) test_case_odd_size_array<int>(8,&mk_int);
  if ( !__n || ( __n == 9  ) ) test_case_almost_sorted<int>(9,&mk_int);
  if ( !__n || ( __n == 10 ) ) test_case_sorted_ascending<int>(10,&mk_int);
  if ( !__n || ( __n == 11 ) ) test_case_sorted_descending<int>(11,&mk_int);
  if ( !__n || ( __n == 12 ) ) test_case_few_unique<int>(12,&mk_int);

  printf("\n");
  return 0;
}
