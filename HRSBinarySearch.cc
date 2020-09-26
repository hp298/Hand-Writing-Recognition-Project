//========================================================================
// HRSBinarySearch.cc
//========================================================================
// Handwritten recognition system that uses binary search.

#include <cstddef>
#include <iostream>
#include "IHandwritingRecSys.h"
#include "Image.h"
#include "Vector.h"
#include "HRSBinarySearch.h"

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement HRSBinarySearch.
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

// default constructor
HRSBinarySearch::HRSBinarySearch( unsigned int K )
{
  m_K = K;
}

// Training
void HRSBinarySearch::train( const Vector<Image>& vec )
{
  m_vec = vec;
  m_vec.sort();
}

// Classification
Image HRSBinarySearch::classify( const Image& img )
{
  m_img = img;
  size_t size = m_vec.size();
  size_t idx = search( 0, size);
  unsigned int hk = m_K / 2;
  size_t begin;
  size_t end;
  
  if ( idx < hk )
    begin = 0;
  else
    begin = idx - hk;
    
  if ( ( size - idx ) < hk )
    end = size;
  else
    end = idx + hk;
    
  size_t closestIdx = begin;
  int min =  abs( m_vec[begin] - m_img );
  for( size_t i = begin; i < end; i++ ) {
    int diff = abs( m_vec[i] - m_img );
    
    if ( diff == 0 )
      return m_vec[i];
      
    if ( diff < min ) {
      closestIdx = i;
      min = abs( m_vec[i] - m_img );
    }
  }
    
    
  return m_vec[closestIdx];
  
}

// Search
size_t HRSBinarySearch::search( size_t begin, size_t end)
{
  size_t half = begin + ( ( end - begin ) / 2 );
  Image comp = m_vec[half];
  
  if ( ( end - begin ) <= 2 )
    return ( begin + 1 );
  
  if ( comp == m_img )
    return half;
  else if ( comp < m_img )
    return search( half, end );
  else // ( comp > m_img )
    return search( begin, half );
}
