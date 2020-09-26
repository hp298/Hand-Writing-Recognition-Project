//========================================================================
// vector-int-directed-test.cc
//========================================================================
// This file contains directed tests for Vector<int>

#include "Vector.h"
#include "vector-directed-test.h"
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

  if ( !__n || ( __n ==  1 ) ) test_case_simple_push_back<int>(1,&mk_int);
  if ( !__n || ( __n ==  2 ) ) test_case_at_out_of_bound<int>(2,&mk_int);
  if ( !__n || ( __n ==  3 ) ) test_case_construct<int>(3,&mk_int);
  if ( !__n || ( __n ==  4 ) ) test_case_construct_empty<int>(4,&mk_int);
  if ( !__n || ( __n ==  5 ) ) test_case_find_simple<int>(5,&mk_int);
  if ( !__n || ( __n ==  6 ) ) test_case_find_empty<int>(6,&mk_int);
  if ( !__n || ( __n ==  7 ) ) test_case_find_closest<int>(7,&mk_int);
  if ( !__n || ( __n ==  8 ) ) test_case_find_closest_empty<int>(8,&mk_int);
  if ( !__n || ( __n ==  9 ) ) test_case_sort_simple<int>(9,&mk_int);
  if ( !__n || ( __n == 10 ) ) test_case_subscript<int>(10,&mk_int);
  if ( !__n || ( __n == 11 ) ) test_case_copy_v1<int>(11,&mk_int);
  if ( !__n || ( __n == 12 ) ) test_case_copy_v2<int>(12,&mk_int);
  if ( !__n || ( __n == 13 ) ) test_case_copy_empty<int>(13,&mk_int);
  if ( !__n || ( __n == 14 ) ) test_case_assignment<int>(14,&mk_int);
  if ( !__n || ( __n == 15 ) ) test_case_assignment_to_empty<int>(15,&mk_int);
  if ( !__n || ( __n == 16 ) ) test_case_assignment_from_empty<int>(16,&mk_int);
  if ( !__n || ( __n == 17 ) ) test_case_assignment_empty<int>(17,&mk_int);
  if ( !__n || ( __n == 18 ) ) test_case_assignment_self<int>(18,&mk_int);
  if ( !__n || ( __n == 19 ) ) test_case_general<int>(19,&mk_int);

  printf("\n");
  return 0;
}
