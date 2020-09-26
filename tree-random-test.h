//========================================================================
// tree-random-test.h
//========================================================================
// This file contains generic random tests for trees. All of the generic
// test functions are templated by an "object creation" function which
// should take as a parameter an integer and return a newly created
// object. For integers, the object creation function can just be the
// identity function. For images, the object creation function can create
// a small image and initialize the pixels based on the given integer.

#include "Tree.h"
#include "utst.h"
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// count_unique
//------------------------------------------------------------------------
// yes this is O(N^2) ...

int count_unique( int* data, size_t size )
{
  int num_unique = 0;
  for ( size_t i = 0; i < size; i++ ) {
    bool unique = true;
    for ( size_t j = i+1; j < size; j++ ) {
      if ( data[i] == data[j] )
        unique = false;
    }
    if ( unique )
      num_unique++;
  }
  return num_unique;
}

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

    Tree<T> tree;

    size_t size = rand() % 100;
    int*   data = new int[size];

    printf( "\n - [ -note- ] size = %lu\n", size );

    for ( size_t j = 0; j < size; j++ ) {
      int rand_int = rand() % 100000;
      tree.add( f(rand_int) );
      data[j] = rand_int;
    }

    int num_unique = count_unique( data, size );
    UTST_ASSERT_INT_EQ( tree.size(), num_unique );

    // Check tree against array that has same elements

    for ( size_t j = 0; j < size; j++ )
      UTST_ASSERT_TRUE( tree.find( f(data[j]) ) );

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

    Tree<T> tree0;
    Tree<T> tree1;

    size_t size0 = rand() % 100;
    size_t size1 = rand() % 100;
    int*   data  = new int[size0+size1];

    printf( "\n - [ -note- ] size = %lu\n", size0+size1 );

    for ( size_t j = 0; j < size0; j++ ) {
      int rand_int = rand() % 1000;
      tree0.add( f(rand_int) );
      data[j] = rand_int;
    }

    // Assignment operator

    tree1 = tree0;

    // Copy constructor

    Tree<T> tree2( tree1 );

    // Add more elements to tree0 and tree1

    for ( size_t j = size0; j < size0+size1; j++ ) {
      int rand_int = rand() % 1000;
      tree1.add( f(rand_int) );
      tree2.add( f(rand_int) );
      data[j] = rand_int;
    }

    // Check size

    int num_unique0 = count_unique( data, size0 );
    UTST_ASSERT_INT_EQ( tree0.size(), num_unique0 );

    int num_unique1 = count_unique( data, size0 + size1 );
    UTST_ASSERT_INT_EQ( tree1.size(), num_unique1 );
    UTST_ASSERT_INT_EQ( tree2.size(), num_unique1 );

    // Check tree 0

    for ( size_t j = 0; j < size0; j++ )
      UTST_ASSERT_TRUE( tree0.find( f(data[j]) ) );

    for ( size_t j = 0; j < size0+size1; j++ ) {
      UTST_ASSERT_TRUE( tree1.find( f(data[j]) ) );
      UTST_ASSERT_TRUE( tree2.find( f(data[j]) ) );
    }

    delete[] data;
  }
}

