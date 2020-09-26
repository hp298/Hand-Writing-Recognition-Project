//========================================================================
// vector-adhoc.cc
//========================================================================
// This file contains an ad-hoc test for vector.

#include <stdio.h>
#include "Vector.h"

int main()
{
  Vector<int> vec;
  vec.push_back( 19 );
  vec.push_back( 95 );
  vec.push_back( 4 );
  vec.push_back( 23 );

  printf( "Value stored at index 0 is %d\n", vec.at( 0 ) );
  printf( "Value stored at index 1 is %d\n", vec.at( 1 ) );
  printf( "Value stored at index 2 is %d\n", vec.at( 2 ) );
  printf( "Value stored at index 3 is %d\n", vec.at( 3 ) );

  vec.sort();
  
  printf( "Those values sorted are ..." );
  vec.print();
  return 0;
}
