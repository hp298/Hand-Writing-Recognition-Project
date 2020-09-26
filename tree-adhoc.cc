//========================================================================
// tree-adhoc.cc
//========================================================================
// This file contains an ad-hoc test for tree.

#include "Tree.h"
#include <cstdio>

int main()
{
  Tree<int> tree;

  for ( int v : { 55, 20, 74, 5, 43, 59, 99, 12, 32 } )
    tree.add( v );

  tree.print();

  std::printf("\n");

  return 0;
}
