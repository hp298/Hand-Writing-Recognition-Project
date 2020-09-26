//========================================================================
// table-directed-tests.h
//========================================================================
// This file contains generic directed tests for tables. All of the
// generic test functions are templated by an "object creation" function
// which should take as a parameter an integer and return a newly created
// object. For integers, the object creation function can just be the
// identity function. For images, the object creation function can create
// a small image and initialize the pixels based on the given integer.

#include "Table.h"
#include "utst.h"

//------------------------------------------------------------------------
// test_case_simple_add
//------------------------------------------------------------------------
// A simple test case that tests default constructor, add, and at. This
// uses a single bin.

template < typename T, typename Func >
void test_case_simple_add( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Use the default constructor
  Table<T> table( 1, f(0), f(100) );

  // Check size of empty table
  UTST_ASSERT_INT_EQ( table.size(), 0 );

  // Push back some values
  T data[] = { f(10), f(11), f(12) };
  for ( T v : data )
    table.add( v );

  // Check size
  UTST_ASSERT_INT_EQ( table.size(), 3 );

  // Check values
  for ( int i = 0; i < 3; i++ )
    UTST_ASSERT_TRUE( table.find( data[i] ) );
}

//------------------------------------------------------------------------
// test_case_2bin_add
//------------------------------------------------------------------------
// A simple test case that tests default constructor, add, and at. This
// uses a two bins.

template < typename T, typename Func >
void test_case_2bin_add( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Use the default constructor
  Table<T> table( 2, f(0), f(100) );

  // Check size of empty table
  UTST_ASSERT_INT_EQ( table.size(), 0 );

  // Push back some values
  T data[] = { f(10), f(11), f(12), f(60), f(61), f(62) };
  for ( T v : data )
    table.add( v );

  // Check size
  UTST_ASSERT_INT_EQ( table.size(), 6 );

  // Check values
  for ( int i = 0; i < 3; i++ )
    UTST_ASSERT_TRUE( table.find( data[i] ) );
}

//------------------------------------------------------------------------
// test_case_duplicate_add
//------------------------------------------------------------------------
// A simple test case that tests adding duplicates

template < typename T, typename Func >
void test_case_duplicate_add( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Use the default constructor
  Table<T> table( 1, f(0), f(100) );

  // Check size of empty table
  UTST_ASSERT_INT_EQ( table.size(), 0 );

  // Push back some values
  T data[] = { f(1), f(1), f(2), f(2), f(1), f(1), f(2), f(2) };
  for ( T v : data )
    table.add( v );

  // Check size
  UTST_ASSERT_INT_EQ( table.size(), 8 );

  // Check values
  UTST_ASSERT_TRUE( table.find( f(1) ) );
  UTST_ASSERT_TRUE( table.find( f(2) ) );
}

//------------------------------------------------------------------------
// test_case_empty_bin
//------------------------------------------------------------------------
// A simple test case that tests default constructor, add, and at. This
// uses a two bins, but one bin is empty.

template < typename T, typename Func >
void test_case_empty_bin( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Use the default constructor
  Table<T> table( 2, f(0), f(100) );

  // Check size of empty table
  UTST_ASSERT_INT_EQ( table.size(), 0 );

  // Push back some values
  T data[] = { f(10), f(11), f(12), f(13), f(14), f(15) };
  for ( T v : data )
    table.add( v );

  // Check size
  UTST_ASSERT_INT_EQ( table.size(), 6 );

  // Check values
  for ( int i = 0; i < 3; i++ )
    UTST_ASSERT_TRUE( table.find( data[i] ) );
}

//------------------------------------------------------------------------
// test_case_construct_empty
//------------------------------------------------------------------------
// A simple test case that tests empty table

template < typename T, typename Func >
void test_case_construct_empty( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  Table<T> table( 1, f(0), f(100) );

  UTST_ASSERT_INT_EQ( table.size(), 0 );
}

//------------------------------------------------------------------------
// test_case_find_simple
//------------------------------------------------------------------------
// A simple test case that tests find.

template < typename T, typename Func >
void test_case_find_simple( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Construct a table from array

  Table<T> table( 2, f(0), f(40) );

  T data[] = { f(1), f(29), f(9), f(25), f(0), f(24), f(2), f(23) };
  for ( T v : data )
    table.add( v );

  // Search for value, expecting success

  UTST_ASSERT_TRUE( table.find( f(1)  ) );
  UTST_ASSERT_TRUE( table.find( f(29) ) );
  UTST_ASSERT_TRUE( table.find( f(9)  ) );
  UTST_ASSERT_TRUE( table.find( f(25) ) );
  UTST_ASSERT_TRUE( table.find( f(0)  ) );
  UTST_ASSERT_TRUE( table.find( f(24) ) );
  UTST_ASSERT_TRUE( table.find( f(2)  ) );
  UTST_ASSERT_TRUE( table.find( f(23) ) );

  // Search for value, expecting failure

  UTST_ASSERT_FALSE( table.find( f(6) ) );
  UTST_ASSERT_FALSE( table.find( f(7) ) );
  UTST_ASSERT_FALSE( table.find( f(8) ) );
  UTST_ASSERT_FALSE( table.find( f(26) ) );
  UTST_ASSERT_FALSE( table.find( f(27) ) );
  UTST_ASSERT_FALSE( table.find( f(28) ) );
}

//------------------------------------------------------------------------
// test_case_find_empty
//------------------------------------------------------------------------
// A simple test case that tests find for an empty table.

template < typename T, typename Func >
void test_case_find_empty( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Construct an empty table

  Table<T> table( 2, f(0), f(100) );

  // Search for value, expecting failure

  for ( int i = 0; i < 10; i++ )
    UTST_ASSERT_FALSE( table.find( f(i) ) );
}

//------------------------------------------------------------------------
// test_case_find_closest
//------------------------------------------------------------------------
// This will create a relatively balanced table with a total of 16
// elements and five bins. It will look like this:
//
//  bin 0 : empty
//  bin 1 : 110, 120, 130, 140
//  bin 2 : 210, 220, 230, 240
//  bin 3 : 310, 320, 330, 340
//  bin 4 : 410, 420, 430, 440
//

template < typename T, typename Func >
void test_case_find_closest( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  Table<T> table( 5, f(0), f(500) );

  T data[] = { f(110), f(210), f(310), f(410),
               f(120), f(220), f(320), f(420),
               f(130), f(230), f(330), f(430),
               f(140), f(240), f(340), f(440) };

  for ( T v : data )
    table.add( v );

  // First find exact matches

  UTST_ASSERT_TRUE( table.find_closest(f(110)) == f(110)  );
  UTST_ASSERT_TRUE( table.find_closest(f(120)) == f(120)  );
  UTST_ASSERT_TRUE( table.find_closest(f(130)) == f(130)  );
  UTST_ASSERT_TRUE( table.find_closest(f(140)) == f(140)  );

  UTST_ASSERT_TRUE( table.find_closest(f(210)) == f(210)  );
  UTST_ASSERT_TRUE( table.find_closest(f(220)) == f(220)  );
  UTST_ASSERT_TRUE( table.find_closest(f(230)) == f(230)  );
  UTST_ASSERT_TRUE( table.find_closest(f(240)) == f(240)  );

  UTST_ASSERT_TRUE( table.find_closest(f(310)) == f(310)  );
  UTST_ASSERT_TRUE( table.find_closest(f(320)) == f(320)  );
  UTST_ASSERT_TRUE( table.find_closest(f(330)) == f(330)  );
  UTST_ASSERT_TRUE( table.find_closest(f(340)) == f(340)  );

  UTST_ASSERT_TRUE( table.find_closest(f(410)) == f(410)  );
  UTST_ASSERT_TRUE( table.find_closest(f(420)) == f(420)  );
  UTST_ASSERT_TRUE( table.find_closest(f(430)) == f(430)  );
  UTST_ASSERT_TRUE( table.find_closest(f(440)) == f(440)  );

  // Find near matches

  UTST_ASSERT_TRUE( table.find_closest(f(109)) == f(110)  );
  UTST_ASSERT_TRUE( table.find_closest(f(111)) == f(110)  );
  UTST_ASSERT_TRUE( table.find_closest(f(219)) == f(220)  );
  UTST_ASSERT_TRUE( table.find_closest(f(221)) == f(220)  );
  UTST_ASSERT_TRUE( table.find_closest(f(329)) == f(330)  );
  UTST_ASSERT_TRUE( table.find_closest(f(331)) == f(330)  );
  UTST_ASSERT_TRUE( table.find_closest(f(439)) == f(440)  );
  UTST_ASSERT_TRUE( table.find_closest(f(441)) == f(440)  );
}

//------------------------------------------------------------------------
// test_case_copy_v1
//------------------------------------------------------------------------
// A simple test case that tests copy constructor with first syntax.

template < typename T, typename Func >
void test_case_copy_v1( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Push back to table0

  Table<T> table0( 2, f(0), f(100) );
  T data0[] = { f(10),  f(60),  f(11),  f(61)  };
  for ( T v : data0 )
    table0.add( v );

  // Copy constructor

  Table<T> table1( table0 );

  // Push different values to table0 and table1

  T data1[] = { f(20), f(70), f(21), f(71) };
  for ( T v : data1 )
    table0.add( v );

  T data2[] = { f(30), f(80), f(31), f(81) };
  for ( T v : data2 )
    table1.add( v );

  // Check size

  UTST_ASSERT_INT_EQ( table0.size(), 8 );
  UTST_ASSERT_INT_EQ( table1.size(), 8 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( table0.find( data0[i] ) );
    UTST_ASSERT_TRUE( table1.find( data0[i] ) );
  }

  // Check the last 4 elements

  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( table0.find( data1[i] ) );
    UTST_ASSERT_TRUE( table1.find( data2[i] ) );
  }
}

//------------------------------------------------------------------------
// test_case_copy_v2
//------------------------------------------------------------------------
// A simple test case that tests copy constructor with second syntax.

template < typename T, typename Func >
void test_case_copy_v2( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Push back to table0

  Table<T> table0( 2, f(0), f(100) );
  T data0[] = { f(10),  f(60),  f(11),  f(61)  };
  for ( T v : data0 )
    table0.add( v );

  // Copy constructor with second syntax

  Table<T> table1 = table0;

  // Push different values to table0 and table1

  T data1[] = { f(20), f(70), f(21), f(71) };
  for ( T v : data1 )
    table0.add( v );

  T data2[] = { f(30), f(80), f(31), f(81) };
  for ( T v : data2 )
    table1.add( v );

  // Check size

  UTST_ASSERT_INT_EQ( table0.size(), 8 );
  UTST_ASSERT_INT_EQ( table1.size(), 8 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( table0.find( data0[i] ) );
    UTST_ASSERT_TRUE( table1.find( data0[i] ) );
  }

  // Check the last 4 elements

  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( table0.find( data1[i] ) );
    UTST_ASSERT_TRUE( table1.find( data2[i] ) );
  }
}

//------------------------------------------------------------------------
// test_case_copy_empty
//------------------------------------------------------------------------
// A simple test case that tests copy constructor with empty table.

template < typename T, typename Func >
void test_case_copy_empty( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Copy constructor

  Table<T> table0( 2, f(0), f(100) );
  Table<T> table1 = table0;

  // Check both tables are empty

  UTST_ASSERT_INT_EQ( table0.size(), 0 );
  UTST_ASSERT_INT_EQ( table1.size(), 0 );

  // Push different values to table0 and table1

  T data0[] = { f(20), f(70), f(21), f(71) };
  for ( T v : data0 )
    table0.add( v );

  T data1[] = { f(30), f(80), f(31), f(81) };
  for ( T v : data1 )
    table1.add( v );

  // Check size

  UTST_ASSERT_INT_EQ( table0.size(), 4 );
  UTST_ASSERT_INT_EQ( table1.size(), 4 );

  // Check the elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( table0.find( data0[i] ) );
    UTST_ASSERT_TRUE( table1.find( data1[i] ) );
  }
}

//------------------------------------------------------------------------
// test_case_assignment
//------------------------------------------------------------------------
// A simple test case that tests assignment operator on a non-empty
// table.

template < typename T, typename Func >
void test_case_assignment( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Push back to table0

  Table<T> table0( 2, f(0), f(100) );
  T data0[] = { f(10),  f(60),  f(11),  f(61)  };
  for ( T v : data0 )
    table0.add( v );

  // Push back some values to table1

  Table<T> table1( 2, f(0), f(100) );
  for ( int i = 0; i < 10; i++ )
    table1.add( f(i) );

  // Assignment operator

  table1 = table0;

  // Push different values to table0 and table1

  T data1[] = { f(20), f(70), f(21), f(71) };
  for ( T v : data1 )
    table0.add( v );

  T data2[] = { f(30), f(80), f(31), f(81) };
  for ( T v : data2 )
    table1.add( v );

  // Check size

  UTST_ASSERT_INT_EQ( table0.size(), 8 );
  UTST_ASSERT_INT_EQ( table1.size(), 8 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( table0.find( data0[i] ) );
    UTST_ASSERT_TRUE( table1.find( data0[i] ) );
  }

  // Check the last 4 elements

  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( table0.find( data1[i] ) );
    UTST_ASSERT_TRUE( table1.find( data2[i] ) );
  }
}

//------------------------------------------------------------------------
// test_case_assignment_diff_nbins
//------------------------------------------------------------------------
// A test case that tests assignment operator when the two tables have
// different numbers of bins.

template < typename T, typename Func >
void test_case_assignment_diff_nbins( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Push back to table0

  Table<T> table0( 2, f(0), f(100) );
  T data0[] = { f(10),  f(60),  f(11),  f(61)  };
  for ( T v : data0 )
    table0.add( v );

  // Push back some values to table1

  Table<T> table1( 1, f(0), f(100) );
  for ( int i = 0; i < 10; i++ )
    table1.add( f(i) );

  // Assignment operator

  table1 = table0;

  // Push different values to table0 and table1

  T data1[] = { f(20), f(70), f(21), f(71) };
  for ( T v : data1 )
    table0.add( v );

  T data2[] = { f(30), f(80), f(31), f(81) };
  for ( T v : data2 )
    table1.add( v );

  // Check size

  UTST_ASSERT_INT_EQ( table0.size(), 8 );
  UTST_ASSERT_INT_EQ( table1.size(), 8 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( table0.find( data0[i] ) );
    UTST_ASSERT_TRUE( table1.find( data0[i] ) );
  }

  // Check the last 4 elements

  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( table0.find( data1[i] ) );
    UTST_ASSERT_TRUE( table1.find( data2[i] ) );
  }
}

//------------------------------------------------------------------------
// test_case_assignment_to_empty
//------------------------------------------------------------------------
// A simple test case that tests assignment operator to empty table from
// non-empty table.

template < typename T, typename Func >
void test_case_assignment_to_empty( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Push back to table0

  Table<T> table0( 2, f(0), f(100) );
  T data0[] = { f(10),  f(60),  f(11),  f(61)  };
  for ( T v : data0 )
    table0.add( v );

  // Assignment operator

  Table<T> table1( 2, f(0), f(100) );
  table1 = table0;

  // Push different values to table0 and table1

  T data1[] = { f(20), f(70), f(21), f(71) };
  for ( T v : data1 )
    table0.add( v );

  T data2[] = { f(30), f(80), f(31), f(81) };
  for ( T v : data2 )
    table1.add( v );

  // Check size

  UTST_ASSERT_INT_EQ( table0.size(), 8 );
  UTST_ASSERT_INT_EQ( table1.size(), 8 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( table0.find( data0[i] ) );
    UTST_ASSERT_TRUE( table1.find( data0[i] ) );
  }

  // Check the last 4 elements

  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( table0.find( data1[i] ) );
    UTST_ASSERT_TRUE( table1.find( data2[i] ) );
  }
}

//------------------------------------------------------------------------
// test_case_assignment_from_empty
//------------------------------------------------------------------------
// A simple test case that tests assignment operator from empty table to
// non-empty table.

template < typename T, typename Func >
void test_case_assignment_from_empty( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Push back to table0

  Table<T> table0( 2, f(0), f(100) );
  T data0[] = { f(10),  f(60),  f(11),  f(61)  };
  for ( T v : data0 )
    table0.add( v );

  // Assignment operator

  Table<T> table1( 2, f(0), f(100) );
  table0 = table1;

  // Check size

  UTST_ASSERT_INT_EQ( table0.size(), 0 );
  UTST_ASSERT_INT_EQ( table1.size(), 0 );

  // Push different values to table0 and table1

  T data1[] = { f(20), f(70), f(21), f(71) };
  for ( T v : data1 )
    table0.add( v );

  T data2[] = { f(30), f(80), f(31), f(81) };
  for ( T v : data2 )
    table1.add( v );

  // Check size

  UTST_ASSERT_INT_EQ( table0.size(), 4 );
  UTST_ASSERT_INT_EQ( table1.size(), 4 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( table0.find( data1[i] ) );
    UTST_ASSERT_TRUE( table1.find( data2[i] ) );
  }
}

//------------------------------------------------------------------------
// test_case_assignment_empty
//------------------------------------------------------------------------
// A simple test case that tests assignment operator from empty table to
// empty table.

template < typename T, typename Func >
void test_case_assignment_empty( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Assignment operator

  Table<T> table0( 2, f(0), f(100) );
  Table<T> table1( 2, f(0), f(100) );
  table0 = table1;

  // Push different values to table0 and table1

  T data1[] = { f(20), f(70), f(21), f(71) };
  for ( T v : data1 )
    table0.add( v );

  T data2[] = { f(30), f(80), f(31), f(81) };
  for ( T v : data2 )
    table1.add( v );

  // Check size

  UTST_ASSERT_INT_EQ( table0.size(), 4 );
  UTST_ASSERT_INT_EQ( table1.size(), 4 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( table0.find( data1[i] ) );
    UTST_ASSERT_TRUE( table1.find( data2[i] ) );
  }
}

//------------------------------------------------------------------------
// test_case_assignment_self
//------------------------------------------------------------------------
// A simple test case that tests self assignment.

template < typename T, typename Func >
void test_case_assignment_self( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Push back to table0

  Table<T> table0( 2, f(0), f(100) );
  T data0[] = { f(10),  f(60),  f(11),  f(61)  };
  for ( T v : data0 )
    table0.add( v );

  // Assignment operator

  table0 = table0;

  // Push more values into table0

  T data1[] = { f(20), f(70), f(21), f(71) };
  for ( T v : data1 )
    table0.add( v );

  // Check size

  UTST_ASSERT_INT_EQ( table0.size(), 8 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ )
    UTST_ASSERT_TRUE( table0.find( data0[i] ) );

  // Check the second 4 elements

  for ( size_t i = 0; i < 4; i++ )
    UTST_ASSERT_TRUE( table0.find( data1[i] ) );
}

//------------------------------------------------------------------------
// test_case_general
//------------------------------------------------------------------------
// A generic test case.

template < typename T, typename Func >
void test_case_general( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Construct a new table

  Table<T> table( 20, f(0), f(1000) );

  // Push data into the data structure

  for ( int i = 0; i < 5; i++ )
    table.add( f(100+i) );

  for ( int i = 5; i < 10; i++ )
    table.add( f(200+i) );

  for ( int i = 10; i < 20; i++ )
    table.add( f(300+i) );

  for ( int i = 20; i < 30; i++ )
    table.add( f(400+i) );

  // Test size

  UTST_ASSERT_INT_EQ( table.size(), 30 );

  // Test data

  for ( int i = 0; i < 5; i++ )
    UTST_ASSERT_TRUE( table.find( f(100+i) ) );

  for ( int i = 5; i < 10; i++ )
    UTST_ASSERT_TRUE( table.find( f(200+i) ) );

  for ( int i = 10; i < 20; i++ )
    UTST_ASSERT_TRUE( table.find( f(300+i) ) );

  for ( int i = 20; i < 30; i++ )
    UTST_ASSERT_TRUE( table.find( f(400+i) ) );

  // Test find, expecting not successful

  for ( size_t i = 1000; i < 2000; i++ )
    UTST_ASSERT_FALSE( table.find( f(i) ) );
}

