//========================================================================
// vector-directed-tests.h
//========================================================================
// This file contains generic directed tests for vectors. All of the
// generic test functions are templated by an "object creation" function
// which should take as a parameter an integer and return a newly created
// object. For integers, the object creation function can just be the
// identity function. For images, the object creation function can create
// a small image and initialize the pixels based on the given integer.

#include "Vector.h"
#include "utst.h"

//------------------------------------------------------------------------
// test_case_simple_push_back
//------------------------------------------------------------------------
// A simple test case that tests default constructor, push_back, and at.

template < typename T, typename Func >
void test_case_simple_push_back( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Use the default constructor
  Vector<T> vec;

  // Check size of empty vector
  UTST_ASSERT_INT_EQ( vec.size(), 0 );

  // Push back some values
  T data[] = { f(10), f(11), f(12) };
  for ( T v : data )
    vec.push_back( v );

  // Check size
  UTST_ASSERT_INT_EQ( vec.size(), 3 );

  // Check values
  for ( int i = 0; i < 3; i++ )
    UTST_ASSERT_TRUE( vec.at(i) == data[i] );
}

//------------------------------------------------------------------------
// test_case_at_out_of_bound
//------------------------------------------------------------------------
// Test that exception is properly thrown when at is out of bound.

template < typename T, typename Func >
void test_case_at_out_of_bound( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  Vector<T> vec;

  // empty vector

  bool flag = false;
  try {
    vec.at(0);
  }
  catch ( ece2400::OutOfRange e ) {
    flag = true;
  }
  UTST_ASSERT_TRUE( flag );

  // push back some values

  vec.push_back(f(0));
  vec.push_back(f(9));

  UTST_ASSERT_TRUE( vec.at(0) == f(0) );
  UTST_ASSERT_TRUE( vec.at(1) == f(9) );

  // right at the boundary

  flag = false;
  try {
    vec.at(2);
  }
  catch ( ece2400::OutOfRange e ) {
    flag = true;
  }
  UTST_ASSERT_TRUE( flag );

  // beyond the boundary

  flag = false;
  try {
    vec.at(5);
  }
  catch ( ece2400::OutOfRange e ) {
    flag = true;
  }
  UTST_ASSERT_TRUE( flag );
}

//------------------------------------------------------------------------
// test_case_construct
//------------------------------------------------------------------------
// A simple test case that tests non-default constructor.

template < typename T, typename Func >
void test_case_construct( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Test constructing from array with one element

  T a0[] = { f(10) };
  Vector<T> vec0( a0, 1 );

  UTST_ASSERT_INT_EQ( vec0.size(),  1 );
  UTST_ASSERT_TRUE( vec0.at(0) == f(10) );

  // Test constructing from array with two elements

  T a1[] = { f(10), f(11) };
  Vector<T> vec1( a1, 2 );

  UTST_ASSERT_INT_EQ( vec1.size(), 2 );
  UTST_ASSERT_TRUE( vec1.at(0) == f(10) );
  UTST_ASSERT_TRUE( vec1.at(1) == f(11) );

  // Test constructing from array with three elements

  T a2[] = { f(10), f(11), f(12) };
  Vector<T> vec2( a2, 3 );

  UTST_ASSERT_INT_EQ( vec2.size(), 3 );
  UTST_ASSERT_TRUE( vec2.at(0) == f(10) );
  UTST_ASSERT_TRUE( vec2.at(1) == f(11) );
  UTST_ASSERT_TRUE( vec2.at(2) == f(12) );

  // Test constructing from array with eight elements

  T a3[] = { f(0), f(1), f(2), f(3), f(4), f(5), f(6), f(7) };
  Vector<T> vec3( a3, 8 );

  UTST_ASSERT_INT_EQ( vec3.size(), 8 );

  for ( size_t i = 0; i < 8; i++ )
    UTST_ASSERT_TRUE( vec3.at(i) == f(i) );
}

//------------------------------------------------------------------------
// test_case_construct_empty
//------------------------------------------------------------------------
// A simple test case that tests non-default constructor with empty array

template < typename T, typename Func >
void test_case_construct_empty( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Test constructing from empty array

  T* a0 = nullptr;
  Vector<T> vec0( a0, 0 );

  UTST_ASSERT_INT_EQ( vec0.size(), 0 );

  // Test constructing from empty array

  T a1[] = { f(10), f(11), f(12) };
  Vector<T> vec1( a1, 0 );

  UTST_ASSERT_INT_EQ( vec1.size(), 0 );
}

//------------------------------------------------------------------------
// test_case_find_simple
//------------------------------------------------------------------------
// A simple test case that tests find.

template < typename T, typename Func >
void test_case_find_simple( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Construct a vector from array

  T data[] = { f(1), f(9), f(9), f(5), f(0), f(4), f(2), f(3) };
  Vector<T> vec( data, 8 );

  // Search for value, expecting success

  UTST_ASSERT_TRUE( vec.find(f(1)) );
  UTST_ASSERT_TRUE( vec.find(f(9)) );
  UTST_ASSERT_TRUE( vec.find(f(5)) );
  UTST_ASSERT_TRUE( vec.find(f(0)) );
  UTST_ASSERT_TRUE( vec.find(f(4)) );
  UTST_ASSERT_TRUE( vec.find(f(2)) );
  UTST_ASSERT_TRUE( vec.find(f(3)) );

  // Search for value, expecting failure

  UTST_ASSERT_FALSE( vec.find(f(6)) );
  UTST_ASSERT_FALSE( vec.find(f(7)) );
  UTST_ASSERT_FALSE( vec.find(f(8)) );
}

//------------------------------------------------------------------------
// test_case_find_empty
//------------------------------------------------------------------------
// A simple test case that tests find for an empty vector.

template < typename T, typename Func >
void test_case_find_empty( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Construct an empty vector
  Vector<T> vec;

  // Search for value, expecting failure
  for ( int i = 0; i < 10; i++ )
    UTST_ASSERT_FALSE( vec.find(f(i)) );
}

//------------------------------------------------------------------------
// test_case_find_closest
//------------------------------------------------------------------------
// A simple test case that tests find closest.

template < typename T, typename Func >
void test_case_find_closest( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  T data[] = { f(40), f(20), f(60), f(10), f(30), f(50), f(70) };
  Vector<T> vec( data, 7 );

  // First find exact matches

  UTST_ASSERT_TRUE( vec.find_closest(f(10))  == f(10) );
  UTST_ASSERT_TRUE( vec.find_closest(f(20))  == f(20) );
  UTST_ASSERT_TRUE( vec.find_closest(f(30))  == f(30) );
  UTST_ASSERT_TRUE( vec.find_closest(f(40))  == f(40) );
  UTST_ASSERT_TRUE( vec.find_closest(f(50))  == f(50) );
  UTST_ASSERT_TRUE( vec.find_closest(f(60))  == f(60) );
  UTST_ASSERT_TRUE( vec.find_closest(f(70))  == f(70) );

  // Find near matches

  UTST_ASSERT_TRUE( vec.find_closest(f(9))   == f(10) );
  UTST_ASSERT_TRUE( vec.find_closest(f(11))  == f(10) );
  UTST_ASSERT_TRUE( vec.find_closest(f(19))  == f(20) );
  UTST_ASSERT_TRUE( vec.find_closest(f(21))  == f(20) );
  UTST_ASSERT_TRUE( vec.find_closest(f(29))  == f(30) );
  UTST_ASSERT_TRUE( vec.find_closest(f(31))  == f(30) );
  UTST_ASSERT_TRUE( vec.find_closest(f(39))  == f(40) );
  UTST_ASSERT_TRUE( vec.find_closest(f(41))  == f(40) );
  UTST_ASSERT_TRUE( vec.find_closest(f(49))  == f(50) );
  UTST_ASSERT_TRUE( vec.find_closest(f(51))  == f(50) );
  UTST_ASSERT_TRUE( vec.find_closest(f(59))  == f(60) );
  UTST_ASSERT_TRUE( vec.find_closest(f(61))  == f(60) );
  UTST_ASSERT_TRUE( vec.find_closest(f(69))  == f(70) );
  UTST_ASSERT_TRUE( vec.find_closest(f(71))  == f(70) );
}

//------------------------------------------------------------------------
// test_case_find_closest_empty
//------------------------------------------------------------------------
// Test that the exception is properly thrown when calling find_closest
// on an empty vector.

template < typename T, typename Func >
void test_case_find_closest_empty( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  Vector<T> vec;

  bool flag = false;
  try {
    vec.find_closest( f(0) );
  }
  catch ( ece2400::OutOfRange e ) {
    flag = true;
  }
  UTST_ASSERT_TRUE( flag );
}

//------------------------------------------------------------------------
// test_case_sort_simple
//------------------------------------------------------------------------
// A simple sort test.

template < typename T, typename Func >
void test_case_sort_simple( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Construct a vector
  T data[] = { f(1), f(9), f(9), f(5), f(0), f(4), f(2), f(3) };
  Vector<T> vec( data, 8 );

  // Sort the vector
  vec.sort();

  // Sorted reference array
  T ref[] = { f(0), f(1), f(2), f(3), f(4), f(5), f(9), f(9) };

  // Verify that we sorted things correctly
  for ( size_t i = 0; i < 8; i++ )
    UTST_ASSERT_TRUE( vec.at(i) == ref[i] );
}

//------------------------------------------------------------------------
// test_case_subscript
//------------------------------------------------------------------------
// A simple test for the subscript operator.

template < typename T, typename Func >
void test_case_subscript( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Construct a vector from array
  T data[] = { f(1), f(9), f(9), f(5), f(0), f(4), f(2), f(3) };
  Vector<T> vec( data, 8 );

  // Check the value using subscript operator
  for ( int i = 0; i < 8; i++ )
    UTST_ASSERT_TRUE( vec[i] == data[i] );
}

//------------------------------------------------------------------------
// test_case_copy_v1
//------------------------------------------------------------------------
// A simple test case that tests copy constructor with first syntax.

template < typename T, typename Func >
void test_case_copy_v1( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Push back to vec0

  T data0[] = { f(0),  f(1),  f(2),  f(3)  };
  Vector<T> vec0;
  for ( T v : data0 )
    vec0.push_back( v );

  // Copy constructor

  Vector<T> vec1( vec0 );

  // Push different values to vec0 and vec1

  T data1[] = { f(10), f(11), f(12), f(13) };
  for ( T v : data1 )
    vec0.push_back( v );

  T data2[] = { f(20), f(21), f(22), f(23) };
  for ( T v : data2 )
    vec1.push_back( v );

  // Check size

  UTST_ASSERT_INT_EQ( vec0.size(), 8 );
  UTST_ASSERT_INT_EQ( vec1.size(), 8 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( vec0.at(i) == data0[i] );
    UTST_ASSERT_TRUE( vec1.at(i) == data0[i] );
  }

  // Check the last 4 elements

  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( vec0.at(i+4) == data1[i] );
    UTST_ASSERT_TRUE( vec1.at(i+4) == data2[i] );
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

  // Push back to vec0

  T data0[] = { f(0),  f(1),  f(2),  f(3)  };
  Vector<T> vec0;
  for ( T v : data0 )
    vec0.push_back( v );

  // Copy constructor with second syntax

  Vector<T> vec1 = vec0;

  // Push different values to vec0 and vec1

  T data1[] = { f(10), f(11), f(12), f(13) };
  for ( T v : data1 )
    vec0.push_back( v );

  T data2[] = { f(20), f(21), f(22), f(23) };
  for ( T v : data2 )
    vec1.push_back( v );

  // Check size

  UTST_ASSERT_INT_EQ( vec0.size(), 8 );
  UTST_ASSERT_INT_EQ( vec1.size(), 8 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( vec0.at(i) == data0[i] );
    UTST_ASSERT_TRUE( vec1.at(i) == data0[i] );
  }

  // Check the last 4 elements

  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( vec0.at(i+4) == data1[i] );
    UTST_ASSERT_TRUE( vec1.at(i+4) == data2[i] );
  }
}

//------------------------------------------------------------------------
// test_case_copy_empty
//------------------------------------------------------------------------
// A simple test case that tests copy constructor from empty vector.

template < typename T, typename Func >
void test_case_copy_empty( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Copy constructor

  Vector<T> vec0;
  Vector<T> vec1 = vec0;

  // Check both vectors are empty

  UTST_ASSERT_INT_EQ( vec0.size(), 0 );
  UTST_ASSERT_INT_EQ( vec1.size(), 0 );

  // Push different values to vec0 and vec1

  T data0[] = { f(0),  f(1),  f(2),  f(3)  };
  for ( T v : data0 )
    vec0.push_back( v );

  T data1[] = { f(10), f(11), f(12), f(13) };
  for ( T v : data1 )
    vec1.push_back( v );

  // Check size

  UTST_ASSERT_INT_EQ( vec0.size(), 4 );
  UTST_ASSERT_INT_EQ( vec1.size(), 4 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( vec0.at(i) == data0[i] );
    UTST_ASSERT_TRUE( vec1.at(i) == data1[i] );
  }
}

//------------------------------------------------------------------------
// test_case_assignment
//------------------------------------------------------------------------
// A simple test case that tests assignment operator on a non-empty
// vector.

template < typename T, typename Func >
void test_case_assignment( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Push back to vec0

  Vector<T> vec0;
  T data0[] = { f(0),  f(1),  f(2),  f(3)  };
  for ( T v : data0 )
    vec0.push_back( v );

  // Push back some values to vec1

  Vector<T> vec1;
  T data1[] = { f(10), f(11), f(12), f(13) };
  for ( int i = 0; i < 10; i++ )
    vec1.push_back( f(i) );

  // Assignment operator

  vec1 = vec0;

  // Push different values to vec0 and vec1

  T data2[] = { f(20), f(21), f(22), f(23) };
  for ( T v : data1 )
    vec0.push_back( v );

  for ( T v : data2 )
    vec1.push_back( v );

  // Check size

  UTST_ASSERT_INT_EQ( vec0.size(), 8 );
  UTST_ASSERT_INT_EQ( vec1.size(), 8 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( vec0.at(i) == data0[i] );
    UTST_ASSERT_TRUE( vec1.at(i) == data0[i] );
  }

  // Check the last 4 elements

  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( vec0.at(i+4) == data1[i] );
    UTST_ASSERT_TRUE( vec1.at(i+4) == data2[i] );
  }
}

//------------------------------------------------------------------------
// test_case_assignment_to_empty
//------------------------------------------------------------------------
// A simple test case that tests assignment operator to empty vector from
// non-empty vector.

template < typename T, typename Func >
void test_case_assignment_to_empty( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Push back to vec0

  Vector<T> vec0;
  T data0[] = { f(0),  f(1),  f(2),  f(3)  };
  for ( T v : data0 )
    vec0.push_back( v );

  // Assignment operator

  Vector<T> vec1;
  vec1 = vec0;

  // Push different values to vec0 and vec1

  T data1[] = { f(10), f(11), f(12), f(13) };
  for ( T v : data1 )
    vec0.push_back( v );

  T data2[] = { f(20), f(21), f(22), f(23) };
  for ( T v : data2 )
    vec1.push_back( v );

  // Check size

  UTST_ASSERT_INT_EQ( vec0.size(), 8 );
  UTST_ASSERT_INT_EQ( vec1.size(), 8 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( vec0.at(i) == data0[i] );
    UTST_ASSERT_TRUE( vec1.at(i) == data0[i] );
  }

  // Check the last 4 elements

  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( vec0.at(i+4) == data1[i] );
    UTST_ASSERT_TRUE( vec1.at(i+4) == data2[i] );
  }
}

//------------------------------------------------------------------------
// test_case_assignment_from_empty
//------------------------------------------------------------------------
// A simple test case that tests assignment operator from empty vector to
// non-empty vector.

template < typename T, typename Func >
void test_case_assignment_from_empty( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Push back to vec0

  Vector<T> vec0;
  T data0[] = { f(0),  f(1),  f(2),  f(3)  };
  for ( T v : data0 )
    vec0.push_back( v );

  // Assignment operator

  Vector<T> vec1;
  vec0 = vec1;

  // Check size

  UTST_ASSERT_INT_EQ( vec0.size(), 0 );
  UTST_ASSERT_INT_EQ( vec1.size(), 0 );

  // Push different values to vec0 and vec1

  T data1[] = { f(10), f(11), f(12), f(13) };
  for ( T v : data1 )
    vec0.push_back( v );

  T data2[] = { f(20), f(21), f(22), f(23) };
  for ( T v : data2 )
    vec1.push_back( v );

  // Check size

  UTST_ASSERT_INT_EQ( vec0.size(), 4 );
  UTST_ASSERT_INT_EQ( vec1.size(), 4 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( vec0.at(i) == data1[i] );
    UTST_ASSERT_TRUE( vec1.at(i) == data2[i] );
  }
}

//------------------------------------------------------------------------
// test_case_assignment_empty
//------------------------------------------------------------------------
// A simple test case that tests assignment operator from empty vector to
// empty vector.

template < typename T, typename Func >
void test_case_assignment_empty( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Assignment operator

  Vector<T> vec0;
  Vector<T> vec1;

  vec0 = vec1;

  // Push different values to vec0 and vec1

  T data1[] = { f(10), f(11), f(12), f(13) };
  for ( T v : data1 )
    vec0.push_back( v );

  T data2[] = { f(20), f(21), f(22), f(23) };
  for ( T v : data2 )
    vec1.push_back( v );

  // Check size

  UTST_ASSERT_INT_EQ( vec0.size(), 4 );
  UTST_ASSERT_INT_EQ( vec1.size(), 4 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( vec0.at(i) == data1[i] );
    UTST_ASSERT_TRUE( vec1.at(i) == data2[i] );
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

  // Push back to vec0

  Vector<T> vec0;
  T data0[] = { f(0),  f(1),  f(2),  f(3)  };
  for ( T v : data0 )
    vec0.push_back( v );

  // Assignment operator

  vec0 = vec0;

  // Push more values into vec0

  T data1[] = { f(10), f(11), f(12), f(13) };
  for ( T v : data1 )
    vec0.push_back( v );

  // Check size

  UTST_ASSERT_INT_EQ( vec0.size(), 8 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ )
    UTST_ASSERT_TRUE( vec0.at(i) == data0[i] );

  // Check the second 4 elements

  for ( size_t i = 0; i < 4; i++ )
    UTST_ASSERT_TRUE( vec0.at(i+4) == data1[i] );
}

//------------------------------------------------------------------------
// test_case_general
//------------------------------------------------------------------------
// A generic test case.

template < typename T, typename Func >
void test_case_general( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Construct a new vector

  Vector<T> vec;

  // Push data into the data structure

  for ( int i = 0; i < 5; i++ )
    vec.push_back( f(100+i) );

  for ( int i = 5; i < 10; i++ )
    vec.push_back( f(200+i) );

  for ( int i = 10; i < 20; i++ )
    vec.push_back( f(300+i) );

  for ( int i = 20; i < 30; i++ )
    vec.push_back( f(400+i) );

  // Test data

  for ( int i = 0; i < 5; i++ )
    UTST_ASSERT_TRUE( f(100+i) == vec.at(i) );

  for ( int i = 5; i < 10; i++ )
    UTST_ASSERT_TRUE( f(200+i) == vec.at(i) );

  for ( int i = 10; i < 20; i++ )
    UTST_ASSERT_TRUE( f(300+i) == vec.at(i) );

  for ( int i = 20; i < 30; i++ )
    UTST_ASSERT_TRUE( f(400+i) == vec.at(i) );

  // Test size

  UTST_ASSERT_INT_EQ( vec.size(), 30 );

  // Test at and find, expecting successful

  for ( size_t i = 0; i < 5; i++ ) {
    UTST_ASSERT_TRUE( vec.find( f(100+i) ) );
    UTST_ASSERT_TRUE( vec.at(i) == f(100+i) );
  }

  for ( size_t i = 5; i < 10; i++ ) {
    UTST_ASSERT_TRUE( vec.find( f(200+i) ) );
    UTST_ASSERT_TRUE( vec.at(i) == f(200+i) );
  }

  for ( size_t i = 10; i < 20; i++ ) {
    UTST_ASSERT_TRUE( vec.find( f(300+i) ) );
    UTST_ASSERT_TRUE( vec.at(i) == f(300+i) );
  }

  for ( size_t i = 20; i < 30; i++ ) {
    UTST_ASSERT_TRUE( vec.find( f(400+i) ) );
    UTST_ASSERT_TRUE( vec.at(i) == f(400+i) );
  }

  // Test find, expecting not successful

  for ( size_t i = 1000; i < 2000; i++ )
    UTST_ASSERT_FALSE( vec.find( f(i) ) );

  // Test find_closest

  for ( size_t i = 0; i < 100; i++ )
    UTST_ASSERT_TRUE( vec.find_closest( f(i) ) == f(100) );

  UTST_ASSERT_TRUE( vec.find_closest( f(250) ) == f(209) );
  UTST_ASSERT_TRUE( vec.find_closest( f(350) ) == f(319) );
  UTST_ASSERT_TRUE( vec.find_closest( f(450) ) == f(429) );
}

