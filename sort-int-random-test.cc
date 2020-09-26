//========================================================================
// sort-int-random-tests.c
//========================================================================
// This file contains the tests for the sort function with ints

#include "sort.h"
#include "sort-random-test.h"
#include "utst.h"
#include "ece2400-stdlib.h"

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

  if ( !__n || ( __n == 1 ) ) test_case_random<int>(1,&mk_int);
  if ( !__n || ( __n == 2 ) ) test_case_random_few_unique<int>(2,&mk_int);

  printf("\n");
  return 0;
}
