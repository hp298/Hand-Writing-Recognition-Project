//========================================================================
// ece2400-stdlib.inl
//========================================================================
// Inline and/or template definitions for ECE 2400 standard library.

#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// abs_diff
//------------------------------------------------------------------------
// Absolute comparison suitable for comparing integers and images.

namespace ece2400 {

template < typename T >
int abs_dist( const T& a, const T& b )
{
  int diff = a - b;
  if ( diff < 0 ) {
    diff = -diff;
  }
  return diff;
}

}

