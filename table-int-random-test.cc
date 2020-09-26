//========================================================================
// table-int-random-test.cc
//========================================================================
// This file contains random tests for Table<int>

#include "Table.h"
#include "table-random-test.h"
#include "utst.h"

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

  if ( !__n || ( __n ==  1 ) ) test_case_add_random<int>(1,&mk_int);
  if ( !__n || ( __n ==  2 ) ) test_case_copy_random<int>(2,&mk_int);

  printf("\n");
  return 0;
}
