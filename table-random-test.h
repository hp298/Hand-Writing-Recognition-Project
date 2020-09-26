//========================================================================
// table-random-test.h
//========================================================================
// This file contains generic random tests for tables. All of the generic
// test functions are templated by an "object creation" function which
// should take as a parameter an integer and return a newly created
// object. For integers, the object creation function can just be the
// identity function. For images, the object creation function can create
// a small image and initialize the pixels based on the given integer.

#include "Table.h"
#include "utst.h"
#include "ece2400-stdlib.h"
#include <iostream>

//------------------------------------------------------------------------
// test_case_add_random
//------------------------------------------------------------------------
// A random test case that tests push back.

template < typename T, typename Func >
void test_case_add_random( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );
  srand( 0xdeadbeef );

  for ( size_t i = 0; i < 50; i++ ) {

    // we need to add one to make sure nbins > 0
    int nbins = (rand() % 10) + 1;
    Table<T> table( nbins, f(0), f(10000) );

    size_t size = rand() % 100;
    int*   data = new int[size];

    printf( "\n - [ -note- ] nbins = %d, size = %lu\n", nbins, size );

    for ( size_t j = 0; j < size; j++ ) {
      int rand_int = rand() % 10000;
      table.add( f(rand_int) );
      data[j] = rand_int;
    }

    UTST_ASSERT_INT_EQ( table.size(), size );

    // Check table against array that has same elements

    for ( size_t j = 0; j < size; j++ )
      UTST_ASSERT_TRUE( table.find( f(data[j]) ) );

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

  for ( size_t i = 0; i < 50; i++ ) {

    // we need to add one to make sure nbins > 0
    int nbins0 = (rand() % 10) + 1;
    Table<T> table0( nbins0, f(0), f(10000) );

    // we need to add one to make sure nbins > 0
    int nbins1 = (rand() % 10) + 1;
    Table<T> table1( nbins1, f(0), f(10000) );

    size_t size0 = rand() % 100;
    size_t size1 = rand() % 100;
    int*   data  = new int[size0+size1];

    printf( "\n - [ -note- ] nbins = %d, nbins = %d, size = %lu\n", nbins0, nbins1, size0+size1 );

    for ( size_t j = 0; j < size0; j++ ) {
      int rand_int = rand() % 10000;
      table0.add( f(rand_int) );
      data[j] = rand_int;
    }

    // Assignment operator

    table1 = table0;

    // Copy constructor

    Table<T> table2( table1 );

    // Add more elements to table0 and table1

    for ( size_t j = size0; j < size0+size1; j++ ) {
      int rand_int = rand() % 10000;
      table1.add( f(rand_int) );
      table2.add( f(rand_int) );
      data[j] = rand_int;
    }

    // Check size

    UTST_ASSERT_INT_EQ( table0.size(), size0 );
    UTST_ASSERT_INT_EQ( table1.size(), size0+size1 );
    UTST_ASSERT_INT_EQ( table2.size(), size0+size1 );

    // Check table 0

    for ( size_t j = 0; j < size0; j++ )
      UTST_ASSERT_TRUE( table0.find( f(data[j]) ) );

    for ( size_t j = 0; j < size0+size1; j++ ) {
      UTST_ASSERT_TRUE( table1.find( f(data[j]) ) );
      UTST_ASSERT_TRUE( table2.find( f(data[j]) ) );
    }

    delete[] data;
  }
}

