//========================================================================
// sort-adhoc.c
//========================================================================

#include "sort.h"
#include "ece2400-stdlib.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
  size_t size = 4;
  int    a[]  = { 19, 95, 4, 23 };

  // Print out array before

  printf( "Before sorting: " );

  ece2400::print_array( a, size );

  // Call sort

  sort( a, size );

  // Print out array after

  printf( "After sorting:  " );

  ece2400::print_array( a, size );

  return 0;
}
