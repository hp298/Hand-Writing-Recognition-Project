//========================================================================
// tree-adhoc.cc
//========================================================================
// This file contains an ad-hoc test for table.

#include "Table.h"
#include <cstdio>

int main()
{
  Table<int> table( 10, 0, 100 );

  for ( int v : { 55, 20, 74, 5, 43, 59, 99, 12, 32 } )
    table.add( v );

  table.print();

  std::printf("\n");

  return 0;
}
