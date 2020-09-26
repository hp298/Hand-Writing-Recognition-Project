//========================================================================
// ece2400-stdlib.h
//========================================================================
// Utility functions and classes for PA4.
//
// Author: Yanghui Ou
//   Date: Oct 28, 2019

#ifndef ECE2400_STDLIB_H
#define ECE2400_STDLIB_H

#include <string>

namespace ece2400 {

//------------------------------------------------------------------------
// Exception
//------------------------------------------------------------------------
// Base class for exceptions.

class Exception {
};

//------------------------------------------------------------------------
// OutOfRangeException
//------------------------------------------------------------------------
// Exception for out of range access.

class OutOfRange : Exception {
 public:
  OutOfRange();
  OutOfRange( const char* err_msg );

  std::string to_str() const;

 private:
  std::string m_err_msg;
};

//------------------------------------------------------------------------
// InvalidArgumentException
//------------------------------------------------------------------------
// Exception for out of range access.

class InvalidArgument : Exception {
 public:
  InvalidArgument();
  InvalidArgument( const char* err_msg );

  std::string to_str() const;

 private:
  std::string m_err_msg;
};

//------------------------------------------------------------------------
// abs_diff
//------------------------------------------------------------------------
// Absolute comparison suitable for comparing integers and images.

template < typename T >
int abs_dist( const T& a, const T& b );

//------------------------------------------------------------------------
// log2
//------------------------------------------------------------------------
// Return nearest log base 2.

int log2( int x );

//------------------------------------------------------------------------
// print_array
//------------------------------------------------------------------------
// Prints the contents in an integer array.

void print_array( int* a, size_t size );

//------------------------------------------------------------------------
// sort
//------------------------------------------------------------------------
// Sorts an array of integer in ascending order using std::sort.

void sort( int* a, size_t size );

//------------------------------------------------------------------------
// timer_reset
//------------------------------------------------------------------------
// Resets the timer.

void timer_reset();

//------------------------------------------------------------------------
// timer_get_elapsed
//------------------------------------------------------------------------
// Return the elapsed time in seconds.

double timer_get_elapsed();

} // namespace ece2400

// Inline and template definitions
#include "ece2400-stdlib.inl"

#endif
