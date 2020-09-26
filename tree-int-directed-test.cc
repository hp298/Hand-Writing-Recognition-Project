//========================================================================
// tree-int-directed-test.cc
//========================================================================
// This file contains directed tests for Tree<int>

#include "Tree.h"
#include "tree-directed-test.h"
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

  if ( !__n || ( __n ==  1 ) ) test_case_simple_add<int>(1,&mk_int);
  if ( !__n || ( __n ==  2 ) ) test_case_duplicate_add<int>(2,&mk_int);
  if ( !__n || ( __n ==  3 ) ) test_case_construct_empty<int>(3,&mk_int);
  if ( !__n || ( __n ==  4 ) ) test_case_find_simple<int>(4,&mk_int);
  if ( !__n || ( __n ==  5 ) ) test_case_find_empty<int>(5,&mk_int);
  if ( !__n || ( __n ==  6 ) ) test_case_find_closest_balanced_largeK<int>(6,&mk_int);
  if ( !__n || ( __n ==  7 ) ) test_case_find_closest_balanced_smallK<int>(7,&mk_int);
  if ( !__n || ( __n ==  8 ) ) test_case_find_closest_unbalanced_largeK<int>(8,&mk_int);
  if ( !__n || ( __n ==  9 ) ) test_case_find_closest_unbalanced_smallK<int>(9,&mk_int);
  if ( !__n || ( __n == 10 ) ) test_case_copy_v1<int>(10,&mk_int);
  if ( !__n || ( __n == 11 ) ) test_case_copy_v2<int>(11,&mk_int);
  if ( !__n || ( __n == 12 ) ) test_case_copy_empty<int>(12,&mk_int);
  if ( !__n || ( __n == 13 ) ) test_case_assignment<int>(13,&mk_int);
  if ( !__n || ( __n == 14 ) ) test_case_assignment_to_empty<int>(14,&mk_int);
  if ( !__n || ( __n == 15 ) ) test_case_assignment_from_empty<int>(15,&mk_int);
  if ( !__n || ( __n == 16 ) ) test_case_assignment_empty<int>(16,&mk_int);
  if ( !__n || ( __n == 17 ) ) test_case_assignment_self<int>(17,&mk_int);
  if ( !__n || ( __n == 18 ) ) test_case_general<int>(18,&mk_int);

  printf("\n");
  return 0;
}
