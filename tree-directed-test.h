//========================================================================
// tree-directed-tests.h
//========================================================================
// This file contains generic directed tests for trees. All of the
// generic test functions are templated by an "object creation" function
// which should take as a parameter an integer and return a newly created
// object. For integers, the object creation function can just be the
// identity function. For images, the object creation function can create
// a small image and initialize the pixels based on the given integer.

#include "Tree.h"
#include "utst.h"
#include <iostream>

//------------------------------------------------------------------------
// test_case_simple_add
//------------------------------------------------------------------------
// A simple test case that tests default constructor, add, and at.

template < typename T, typename Func >
void test_case_simple_add( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Use the default constructor
  Tree<T> tree;

  // Check size of empty tree
  UTST_ASSERT_INT_EQ( tree.size(), 0 );

  // Push back some values
  T data[] = { f(10), f(11), f(12) };
  for ( T v : data )
    tree.add( v );

  // Check size
  UTST_ASSERT_INT_EQ( tree.size(), 3 );

  // Check values
  for ( int i = 0; i < 3; i++ )
    UTST_ASSERT_TRUE( tree.find( data[i] ) );
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
  Tree<T> tree;

  // Check size of empty tree
  UTST_ASSERT_INT_EQ( tree.size(), 0 );

  // Push back some values
  T data[] = { f(1), f(1), f(2), f(2), f(1), f(1), f(2), f(2) };
  for ( T v : data )
    tree.add( v );

  // Check size
  UTST_ASSERT_INT_EQ( tree.size(), 2 );

  // Check values
  UTST_ASSERT_TRUE( tree.find( f(1) ) );
  UTST_ASSERT_TRUE( tree.find( f(2) ) );
}

//------------------------------------------------------------------------
// test_case_construct_empty
//------------------------------------------------------------------------
// A simple test case that tests empty tree

template < typename T, typename Func >
void test_case_construct_empty( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  Tree<T> tree;

  UTST_ASSERT_INT_EQ( tree.size(), 0 );
}

//------------------------------------------------------------------------
// test_case_find_simple
//------------------------------------------------------------------------
// A simple test case that tests find.

template < typename T, typename Func >
void test_case_find_simple( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Construct a tree from array

  Tree<T> tree;

  T data[] = { f(1), f(9), f(9), f(5), f(0), f(4), f(2), f(3) };
  for ( T v : data )
    tree.add( v );

  // Search for value, expecting success

  UTST_ASSERT_TRUE( tree.find( f(1) ) );
  UTST_ASSERT_TRUE( tree.find( f(9) ) );
  UTST_ASSERT_TRUE( tree.find( f(5) ) );
  UTST_ASSERT_TRUE( tree.find( f(0) ) );
  UTST_ASSERT_TRUE( tree.find( f(4) ) );
  UTST_ASSERT_TRUE( tree.find( f(2) ) );
  UTST_ASSERT_TRUE( tree.find( f(3) ) );

  // Search for value, expecting failure

  UTST_ASSERT_FALSE( tree.find( f(6) ) );
  UTST_ASSERT_FALSE( tree.find( f(7) ) );
  UTST_ASSERT_FALSE( tree.find( f(8) ) );
}

//------------------------------------------------------------------------
// test_case_find_empty
//------------------------------------------------------------------------
// A simple test case that tests find for an empty tree.

template < typename T, typename Func >
void test_case_find_empty( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Construct an empty tree

  Tree<T> tree;

  // Search for value, expecting failure

  for ( int i = 0; i < 10; i++ )
    UTST_ASSERT_FALSE( tree.find( f(i) ) );
}

//------------------------------------------------------------------------
// test_case_find_closest_balanced_largeK
//------------------------------------------------------------------------
// This will create a balanced tree with a total of 15 nodes and three
// levels.
//
//       150
//     140
//       130
//   120
//       110
//     100
//       90
// 80
//       70
//     60
//       50
//   40
//       30
//     20
//       10
//
// We choose a large K which means we are essentially doing an exhaustive
// search.

template < typename T, typename Func >
void test_case_find_closest_balanced_largeK( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  Tree<T> tree( 1024 );

  T data[] = { f(80), f(40), f(120), f(20), f(60), f(100), f(140),
               f(10), f(30), f(50),  f(70), f(90), f(110), f(130), f(150) };
  for ( T v : data )
    tree.add( v );

  // First find exact matches

  UTST_ASSERT_TRUE( tree.find_closest(f(10))  == f(10)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(20))  == f(20)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(30))  == f(30)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(40))  == f(40)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(50))  == f(50)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(60))  == f(60)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(70))  == f(70)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(80))  == f(80)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(90))  == f(90)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(100)) == f(100) );
  UTST_ASSERT_TRUE( tree.find_closest(f(110)) == f(110) );
  UTST_ASSERT_TRUE( tree.find_closest(f(120)) == f(120) );
  UTST_ASSERT_TRUE( tree.find_closest(f(130)) == f(130) );
  UTST_ASSERT_TRUE( tree.find_closest(f(140)) == f(140) );
  UTST_ASSERT_TRUE( tree.find_closest(f(150)) == f(150) );

  // Find near matches

  UTST_ASSERT_TRUE( tree.find_closest(f(9))   == f(10)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(11))  == f(10)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(19))  == f(20)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(21))  == f(20)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(29))  == f(30)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(31))  == f(30)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(39))  == f(40)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(41))  == f(40)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(49))  == f(50)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(51))  == f(50)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(59))  == f(60)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(61))  == f(60)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(69))  == f(70)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(71))  == f(70)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(79))  == f(80)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(81))  == f(80)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(89))  == f(90)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(91))  == f(90)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(99))  == f(100) );
  UTST_ASSERT_TRUE( tree.find_closest(f(101)) == f(100) );
  UTST_ASSERT_TRUE( tree.find_closest(f(109)) == f(110) );
  UTST_ASSERT_TRUE( tree.find_closest(f(111)) == f(110) );
  UTST_ASSERT_TRUE( tree.find_closest(f(119)) == f(120) );
  UTST_ASSERT_TRUE( tree.find_closest(f(121)) == f(120) );
  UTST_ASSERT_TRUE( tree.find_closest(f(129)) == f(130) );
  UTST_ASSERT_TRUE( tree.find_closest(f(131)) == f(130) );
  UTST_ASSERT_TRUE( tree.find_closest(f(139)) == f(140) );
  UTST_ASSERT_TRUE( tree.find_closest(f(141)) == f(140) );
  UTST_ASSERT_TRUE( tree.find_closest(f(149)) == f(150) );
  UTST_ASSERT_TRUE( tree.find_closest(f(151)) == f(150) );
}

//------------------------------------------------------------------------
// test_case_find_closest_balanced_smallK
//------------------------------------------------------------------------
// This will create a balanced tree with a total of 15 nodes and three
// levels. It looks like this:
//
//       150
//     140
//       130
//   120
//       110
//     100
//       90
// 80
//       70
//     60
//       50
//   40
//       30
//     20
//       10
//
// We choose a K of 4 which means we should be doing an exhaustive search
// through the bottom two levels (i.e., three nodes). We don't check for
// values which are in the first two levels since an implementation might
// not be looking for exact matches during the binary search part.

template < typename T, typename Func >
void test_case_find_closest_balanced_smallK( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  Tree<T> tree( 4 );

  T data[] = { f(80), f(40), f(120), f(20), f(60), f(100), f(140),
               f(10), f(30), f(50),  f(70), f(90), f(110), f(130), f(150) };
  for ( T v : data )
    tree.add( v );

  // First find exact matches at the leaves

  UTST_ASSERT_TRUE( tree.find_closest(f(10))  == f(10)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(20))  == f(20)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(30))  == f(30)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(50))  == f(50)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(60))  == f(60)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(70))  == f(70)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(90))  == f(90)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(100)) == f(100) );
  UTST_ASSERT_TRUE( tree.find_closest(f(110)) == f(110) );
  UTST_ASSERT_TRUE( tree.find_closest(f(130)) == f(130) );
  UTST_ASSERT_TRUE( tree.find_closest(f(140)) == f(140) );
  UTST_ASSERT_TRUE( tree.find_closest(f(150)) == f(150) );

  // Find near matches at the leaves

  UTST_ASSERT_TRUE( tree.find_closest(f(9))   == f(10)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(11))  == f(10)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(19))  == f(20)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(21))  == f(20)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(29))  == f(30)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(31))  == f(30)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(49))  == f(50)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(51))  == f(50)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(59))  == f(60)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(61))  == f(60)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(69))  == f(70)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(71))  == f(70)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(89))  == f(90)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(91))  == f(90)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(99))  == f(100) );
  UTST_ASSERT_TRUE( tree.find_closest(f(101)) == f(100) );
  UTST_ASSERT_TRUE( tree.find_closest(f(109)) == f(110) );
  UTST_ASSERT_TRUE( tree.find_closest(f(111)) == f(110) );
  UTST_ASSERT_TRUE( tree.find_closest(f(129)) == f(130) );
  UTST_ASSERT_TRUE( tree.find_closest(f(131)) == f(130) );
  UTST_ASSERT_TRUE( tree.find_closest(f(139)) == f(140) );
  UTST_ASSERT_TRUE( tree.find_closest(f(141)) == f(140) );
  UTST_ASSERT_TRUE( tree.find_closest(f(149)) == f(150) );
  UTST_ASSERT_TRUE( tree.find_closest(f(151)) == f(150) );
}

//------------------------------------------------------------------------
// test_case_find_closest_unbalanced_largeK
//------------------------------------------------------------------------
// This will create a unbalanced tree with a total of 15 nodes and 8
// levels. It looks like this:
//
//               150
//             140
//           130
//         120
//       110
//     100
//   90
// 80
//   70
//     60
//       50
//         40
//           30
//             20
//               10
//
// We choose a large K which means we are essentially doing an
// exhaustive search.

template < typename T, typename Func >
void test_case_find_closest_unbalanced_largeK( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  Tree<T> tree( 1024 );

  T data[] = { f(80), f(90), f(100), f(110), f(120), f(130), f(140), f(150),
               f(70), f(60), f(50),  f(40), f(30), f(20), f(10) };
  for ( T v : data )
    tree.add( v );

  // First find exact matches

  UTST_ASSERT_TRUE( tree.find_closest(f(10))  == f(10)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(20))  == f(20)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(30))  == f(30)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(40))  == f(40)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(50))  == f(50)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(60))  == f(60)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(70))  == f(70)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(80))  == f(80)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(90))  == f(90)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(100)) == f(100) );
  UTST_ASSERT_TRUE( tree.find_closest(f(110)) == f(110) );
  UTST_ASSERT_TRUE( tree.find_closest(f(120)) == f(120) );
  UTST_ASSERT_TRUE( tree.find_closest(f(130)) == f(130) );
  UTST_ASSERT_TRUE( tree.find_closest(f(140)) == f(140) );
  UTST_ASSERT_TRUE( tree.find_closest(f(150)) == f(150) );

  // Find near matches

  UTST_ASSERT_TRUE( tree.find_closest(f(9))   == f(10)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(11))  == f(10)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(19))  == f(20)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(21))  == f(20)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(29))  == f(30)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(31))  == f(30)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(39))  == f(40)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(41))  == f(40)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(49))  == f(50)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(51))  == f(50)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(59))  == f(60)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(61))  == f(60)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(69))  == f(70)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(71))  == f(70)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(79))  == f(80)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(81))  == f(80)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(89))  == f(90)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(91))  == f(90)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(99))  == f(100) );
  UTST_ASSERT_TRUE( tree.find_closest(f(101)) == f(100) );
  UTST_ASSERT_TRUE( tree.find_closest(f(109)) == f(110) );
  UTST_ASSERT_TRUE( tree.find_closest(f(111)) == f(110) );
  UTST_ASSERT_TRUE( tree.find_closest(f(119)) == f(120) );
  UTST_ASSERT_TRUE( tree.find_closest(f(121)) == f(120) );
  UTST_ASSERT_TRUE( tree.find_closest(f(129)) == f(130) );
  UTST_ASSERT_TRUE( tree.find_closest(f(131)) == f(130) );
  UTST_ASSERT_TRUE( tree.find_closest(f(139)) == f(140) );
  UTST_ASSERT_TRUE( tree.find_closest(f(141)) == f(140) );
  UTST_ASSERT_TRUE( tree.find_closest(f(149)) == f(150) );
  UTST_ASSERT_TRUE( tree.find_closest(f(151)) == f(150) );
}

//------------------------------------------------------------------------
// test_case_find_closest_unbalanced_smallK
//------------------------------------------------------------------------
// This will create a balanced tree with a total of 15 nodes and three
// levels.
//
//               150
//             140
//           130
//         120
//       110
//     100
//   90
// 80
//   70
//     60
//       50
//         40
//           30
//             20
//               10
//
// We choose a K of 4 which means we should be doing an exhaustive search
// through the bottom two levels (i.e., two nodes). We don't check for
// values which are in the upper levels since an implementation might not
// be looking for exact matches during the binary search part.

template < typename T, typename Func >
void test_case_find_closest_unbalanced_smallK( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  Tree<T> tree( 4 );

  T data[] = { f(80), f(90), f(100), f(110), f(120), f(130), f(140), f(150),
               f(70), f(60), f(50),  f(40), f(30), f(20), f(10) };
  for ( T v : data )
    tree.add( v );

  // First find exact matches

  UTST_ASSERT_TRUE( tree.find_closest(f(10))  == f(10)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(20))  == f(20)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(140)) == f(140) );
  UTST_ASSERT_TRUE( tree.find_closest(f(150)) == f(150) );

  // Find near matches

  UTST_ASSERT_TRUE( tree.find_closest(f(9))   == f(10)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(11))  == f(10)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(19))  == f(20)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(21))  == f(20)  );
  UTST_ASSERT_TRUE( tree.find_closest(f(139)) == f(140) );
  UTST_ASSERT_TRUE( tree.find_closest(f(141)) == f(140) );
  UTST_ASSERT_TRUE( tree.find_closest(f(149)) == f(150) );
  UTST_ASSERT_TRUE( tree.find_closest(f(151)) == f(150) );
}

//------------------------------------------------------------------------
// test_case_copy_v1
//------------------------------------------------------------------------
// A simple test case that tests copy constructor with first syntax.

template < typename T, typename Func >
void test_case_copy_v1( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Push back to tree0

  Tree<T> tree0;
  T data0[] = { f(0),  f(1),  f(2),  f(3)  };
  for ( T v : data0 )
    tree0.add( v );

  // Copy constructor

  Tree<T> tree1( tree0 );

  // Push different values to tree0 and tree1

  T data1[] = { f(10), f(11), f(12), f(13) };
  for ( T v : data1 )
    tree0.add( v );

  T data2[] = { f(20), f(21), f(22), f(23) };

  for ( T v : data2 )
    tree1.add( v );

  // Check size
  UTST_ASSERT_INT_EQ( tree0.size(), 8 );
  UTST_ASSERT_INT_EQ( tree1.size(), 8 );

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( tree0.find( data0[i] ) );
    UTST_ASSERT_TRUE( tree1.find( data0[i] ) );
  }

  // Check the last 4 elements

  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( tree0.find( data1[i] ) );
    UTST_ASSERT_TRUE( tree1.find( data2[i] ) );
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

  // Push back to tree0

  Tree<T> tree0;
  T data0[] = { f(0),  f(1),  f(2),  f(3)  };
  for ( T v : data0 )
    tree0.add( v );

  // Copy constructor with second syntax

  Tree<T> tree1 = tree0;

  // Push different values to tree0 and tree1

  T data1[] = { f(10), f(11), f(12), f(13) };
  for ( T v : data1 )
    tree0.add( v );

  T data2[] = { f(20), f(21), f(22), f(23) };
  for ( T v : data2 )
    tree1.add( v );

  // Check size

  UTST_ASSERT_INT_EQ( tree0.size(), 8 );
  UTST_ASSERT_INT_EQ( tree1.size(), 8 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( tree0.find( data0[i] ) );
    UTST_ASSERT_TRUE( tree1.find( data0[i] ) );
  }

  // Check the last 4 elements

  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( tree0.find( data1[i] ) );
    UTST_ASSERT_TRUE( tree1.find( data2[i] ) );
  }
}

//------------------------------------------------------------------------
// test_case_copy_empty
//------------------------------------------------------------------------
// A simple test case that tests copy constructor with empty tree.

template < typename T, typename Func >
void test_case_copy_empty( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Copy constructor

  Tree<T> tree0;
  Tree<T> tree1 = tree0; 

  UTST_ASSERT_INT_EQ( tree0.size(), 0 );
  UTST_ASSERT_INT_EQ( tree1.size(), 0 );

  // Push different values to tree0 and tree1

  T data0[] = { f(0),  f(1),  f(2),  f(3)  };
  for ( T v : data0 )
    tree0.add( v );

  T data1[] = { f(10), f(11), f(12), f(13) };
  for ( T v : data1 )
    tree1.add( v );

  // Check size

  UTST_ASSERT_INT_EQ( tree0.size(), 4 );
  UTST_ASSERT_INT_EQ( tree1.size(), 4 );

  // Check the elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( tree0.find( data0[i] ) );
    UTST_ASSERT_TRUE( tree1.find( data1[i] ) );
  }
}

//------------------------------------------------------------------------
// test_case_assignment
//------------------------------------------------------------------------
// A simple test case that tests assignment operator on a non-empty
// tree.

template < typename T, typename Func >
void test_case_assignment( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Push back to tree0

  Tree<T> tree0;
  
  T data0[] = { f(0),  f(1),  f(2),  f(3)  };
  for( size_t i = 0; i < 4; i++) {
    tree0.add( f(i) );
  }

  // Push back some values to tree1

  Tree<T> tree1;
  for ( int i = 0; i < 10; i++ )
    tree1.add( f(i) );
  
  tree1 = tree0;
  // Assignment operator

  // Push different values to tree0 and tree1

  T data1[] = { f(10), f(11), f(12), f(13) };
  for ( T v : data1 )
    tree0.add( v );

  T data2[] = { f(20), f(21), f(22), f(23) };
  for ( T v : data2 )
    tree1.add( v );

  // Check size

  UTST_ASSERT_INT_EQ( tree0.size(), 8 );
  UTST_ASSERT_INT_EQ( tree1.size(), 8 );
  
  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( tree0.find( data0[i] ) );
    UTST_ASSERT_TRUE( tree1.find( data0[i] ) );
  }

  // Check the last 4 elements

  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( tree0.find( data1[i] ) );
    UTST_ASSERT_TRUE( tree1.find( data2[i] ) );
  }
}

//------------------------------------------------------------------------
// test_case_assignment_to_empty
//------------------------------------------------------------------------
// A simple test case that tests assignment operator to empty tree from
// non-empty tree.

template < typename T, typename Func >
void test_case_assignment_to_empty( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Push back to tree0

  Tree<T> tree0;
  T data0[] = { f(0),  f(1),  f(2),  f(3)  };
  for ( T v : data0 )
    tree0.add( v );

  // Assignment operator

  Tree<T> tree1;
  tree1 = tree0;

  // Push different values to tree0 and tree1

  T data1[] = { f(10), f(11), f(12), f(13) };
  for ( T v : data1 )
    tree0.add( v );

  T data2[] = { f(20), f(21), f(22), f(23) };
  for ( T v : data2 )
    tree1.add( v );

  // Check size

  UTST_ASSERT_INT_EQ( tree0.size(), 8 );
  UTST_ASSERT_INT_EQ( tree1.size(), 8 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( tree0.find( data0[i] ) );
    UTST_ASSERT_TRUE( tree1.find( data0[i] ) );
  }

  // Check the last 4 elements

  for ( auto i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( tree0.find( data1[i] ) );
    UTST_ASSERT_TRUE( tree1.find( data2[i] ) );
  }
}

//------------------------------------------------------------------------
// test_case_assignment_from_empty
//------------------------------------------------------------------------
// A simple test case that tests assignment operator from empty tree to
// non-empty tree.

template < typename T, typename Func >
void test_case_assignment_from_empty( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Push back to tree0

  Tree<T> tree0;
  T data0[] = { f(0),  f(1),  f(2),  f(3)  };
  for ( T v : data0 )
    tree0.add( v );

  // Assignment operator

  Tree<T> tree1;
  tree0 = tree1;

  // Check size
  UTST_ASSERT_INT_EQ( tree0.size(), 0 );
  UTST_ASSERT_INT_EQ( tree1.size(), 0 );

  // Push different values to tree0 and tree1
  T data1[] = { f(10), f(11), f(12), f(13) };
  for ( T v : data1 )
    tree0.add( v );
  T data2[] = { f(20), f(21), f(22), f(23) };
  for ( T v : data2 )
    tree1.add( v );

  // Check size

  UTST_ASSERT_INT_EQ( tree0.size(), 4 );
  UTST_ASSERT_INT_EQ( tree1.size(), 4 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( tree0.find( data1[i] ) );
    UTST_ASSERT_TRUE( tree1.find( data2[i] ) );
  }
}

//------------------------------------------------------------------------
// test_case_assignment_empty
//------------------------------------------------------------------------
// A simple test case that tests assignment operator from empty tree to
// empty tree.

template < typename T, typename Func >
void test_case_assignment_empty( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Assignment operator

  Tree<T> tree0;
  Tree<T> tree1; 
  printf("Assignemnt Error?\n");
  tree0 = tree1;

  // Push different values to tree0 and tree1

  T data1[] = { f(10), f(11), f(12), f(13) };
  for ( T v : data1 ) {
    printf("Data1 Error?\n");
    tree0.add( v );
  }
  T data2[] = { f(20), f(21), f(22), f(23) };
  for ( T v : data2 ) {
    printf("Data2 Error?\n");
    tree1.add( v );
}
  // Check size

  UTST_ASSERT_INT_EQ( tree0.size(), 4 );
  UTST_ASSERT_INT_EQ( tree1.size(), 4 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ ) {
    UTST_ASSERT_TRUE( tree0.find( data1[i] ) );
    UTST_ASSERT_TRUE( tree1.find( data2[i] ) );
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

  // Push back to tree0

  Tree<T> tree0;
  T data0[] = { f(0),  f(1),  f(2),  f(3)  };
  for ( T v : data0 )
    tree0.add( v );

  // Assignment operator

  tree0 = tree0;

  // Push more values into tree0

  T data1[] = { f(10), f(11), f(12), f(13) };
  for ( T v : data1 )
    tree0.add( v );

  // Check size

  UTST_ASSERT_INT_EQ( tree0.size(), 8 );

  // Check the first 4 elements

  for ( size_t i = 0; i < 4; i++ )
    UTST_ASSERT_TRUE( tree0.find( data0[i] ) );

  // Check the second 4 elements

  for ( size_t i = 0; i < 4; i++ )
    UTST_ASSERT_TRUE( tree0.find( data1[i] ) );
}

//------------------------------------------------------------------------
// test_case_general
//------------------------------------------------------------------------
// A generic test case.

template < typename T, typename Func >
void test_case_general( int test_case_num, Func f )
{
  std::printf( "\n%d: %s\n", test_case_num, __func__ );

  // Construct a new tree

  Tree<T> tree;

  // Push data into the data structure

  for ( int i = 0; i < 5; i++ )
    tree.add( f(100+i) );

  for ( int i = 5; i < 10; i++ )
    tree.add( f(200+i) );

  for ( int i = 10; i < 20; i++ )
    tree.add( f(300+i) );

  for ( int i = 20; i < 30; i++ )
    tree.add( f(400+i) );

  // Test size

  UTST_ASSERT_INT_EQ( tree.size(), 30 );

  // Test data

  for ( int i = 0; i < 5; i++ )
    UTST_ASSERT_TRUE( tree.find( f(100+i) ) );

  for ( int i = 5; i < 10; i++ )
    UTST_ASSERT_TRUE( tree.find( f(200+i) ) );

  for ( int i = 10; i < 20; i++ )
    UTST_ASSERT_TRUE( tree.find( f(300+i) ) );

  for ( int i = 20; i < 30; i++ )
    UTST_ASSERT_TRUE( tree.find( f(400+i) ) );

  // Test find, expecting not successful

  for ( size_t i = 1000; i < 2000; i++ )
    UTST_ASSERT_FALSE( tree.find( f(i) ) );
}

