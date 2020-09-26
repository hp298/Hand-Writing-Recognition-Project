//========================================================================
// sort-random-tests.h
//========================================================================
// This file contains generic random tests for the sort function. All of
// the generic test functions are templated by an "object creation"
// function which should take as a parameter an integer and return a
// newly created object. For integers, the object creation function can
// just be the identity function. For images, the object creation
// function can create a small image and initialize the pixels based on
// the given integer.

#include "sort.h"
#include "utst.h"
#include "ece2400-stdlib.h"

#include <stdio.h>
#include <stdlib.h>

//------------------------------------------------------------------------
// test_case_random
//------------------------------------------------------------------------
// Many random values

template < typename T, typename Func >
void test_case_random( int test_case_num, Func f )
{
  printf( "\n%d: %s\n", test_case_num, __func__ );
  srand( 0xdeadbeef );

  // Do 100 random tests

  for ( size_t i = 0; i < 100; i++ ) {

    // Choose a random size

    size_t size = rand() % 100;
    printf( "\n - [ -note- ] size = %lu\n", size );

    // Allocate space for our test array and reference array

    T* a     = new T[size];
    T* a_ref = new T[size];

    // Fill both arrays with random values

    for ( size_t j = 0; j < size; j++ ) {
      T value   = f( rand() % 100000 );
      a[j]      = value;
      a_ref[j]  = value;
    }

    // Use our sort algorithm on test array

    sort( a, size );

    // Verify that we sorted things correctly

    for ( size_t j = 1; j < size; j++ )
      UTST_ASSERT_TRUE( a[j-1] <= a[j] );

    // Cleanup

    delete[] a;
    delete[] a_ref;
  }

}

//------------------------------------------------------------------------
// test_case_random_few_unique
//------------------------------------------------------------------------
// Many values, but few unique

template < typename T, typename Func >
void test_case_random_few_unique( int test_case_num, Func f )
{
  printf( "\n%d: %s\n", test_case_num, __func__ );
  srand( 0xdeadbeef );

  // Do 100 random tests

  for ( size_t i = 0; i < 100; i++ ) {

    // Choose a random size

    size_t size = rand() % 100;
    printf( "\n - [ -note- ] size = %lu\n", size );

    // Allocate space for our test array and reference array

    T* a     = new T[size];
    T* a_ref = new T[size];

    // Fill both arrays with random values

    for ( size_t j = 0; j < size; j++ ) {
      T value   = f( rand() % 10 );
      a[j]      = value;
      a_ref[j]  = value;
    }

    // Use our sort algorithm on test array

    sort( a, size );

    // Verify that we sorted things correctly

    for ( size_t j = 1; j < size; j++ )
      UTST_ASSERT_TRUE( a[j-1] <= a[j] );

    // Cleanup

    delete[] a;
    delete[] a_ref;
  }

}

