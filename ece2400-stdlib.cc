//========================================================================
// ece2400-stdlib.cc
//========================================================================
// Utility functions and classes for PA4.
//
// Author: Yanghui Ou
//   Date: Oct 28, 2019

#include <algorithm>
#include <string>
#include <sys/time.h>
#include "ece2400-stdlib.h"

using namespace ece2400;

const double million = 1000000.0;

//------------------------------------------------------------------------
// Global variables
//------------------------------------------------------------------------

struct timeval start_time;
struct timeval end_time;

//------------------------------------------------------------------------
// OutOfRange
//------------------------------------------------------------------------

OutOfRange::OutOfRange() { }

OutOfRange::OutOfRange( const char* err_msg )
  : m_err_msg( err_msg )
{ }

std::string OutOfRange::to_str() const
{
  return m_err_msg;
}

//------------------------------------------------------------------------
// InvalidArgument
//------------------------------------------------------------------------

InvalidArgument::InvalidArgument() { }

InvalidArgument::InvalidArgument( const char* err_msg )
  : m_err_msg( err_msg )
{ }

std::string InvalidArgument::to_str() const
{
  return m_err_msg;
}

//------------------------------------------------------------------------
// print_array
//------------------------------------------------------------------------
// Prints the contents in an integer array.

void ece2400::print_array( int* a, size_t size )
{
  if ( size > 0 )
    std::printf( "%d", a[0] );
  for ( size_t i = 1; i < size; i++ )
    std::printf( ", %d", a[i] );
  std::printf( "\n" );
}

//------------------------------------------------------------------------
// log2
//------------------------------------------------------------------------
// To find log2(x) we can just repeatedly do (( x/2 ) / 2 ) / 2 until the
// result is zero.

int ece2400::log2( int x )
{
  int result = 0;
  while ( x > 1 ) {
    x = x / 2;
    result++;
  }
  return result;
}

//------------------------------------------------------------------------
// sort
//------------------------------------------------------------------------
// Sorts an array of integer in ascending order using std::sort.

void ece2400::sort( int* a, size_t size )
{
  std::sort( a, a + size );
}

//------------------------------------------------------------------------
// timer_reset
//------------------------------------------------------------------------
// Resets the timer.

void ece2400::timer_reset()
{
  gettimeofday( &start_time, NULL );
}

//------------------------------------------------------------------------
// timer_get_elapsed
//------------------------------------------------------------------------
// Return the elapsed time in seconds.

double ece2400::timer_get_elapsed()
{
  gettimeofday( &end_time, NULL );
  double elapsed_time = ( end_time.tv_sec - start_time.tv_sec ) +
                        ( end_time.tv_usec - start_time.tv_usec ) / million;
  return elapsed_time;
}

