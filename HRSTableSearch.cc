//========================================================================
// HRSTableSearch.cc
//========================================================================
// Definitions for HRSTableSearch

#include "HRSTableSearch.h"
#include "Vector.h"
#include "Table.h"
#include "Image.h"
#include <iostream>

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement HRSBinarySearch.
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

// default constructor
HRSTableSearch::HRSTableSearch( unsigned int K )
{
  m_k = K;
}

// training
void HRSTableSearch::train( const Vector<Image>& vec )
{
  m_vec = vec;
  m_min = vec[0];
  m_max = vec[0];
  m_bins = vec.size() / m_k;
  for( size_t i = 0; i < vec.size(); i++ ) {
    if ( vec[i] < m_min )
      m_min = vec[i];
    if ( vec[i] > m_max )
      m_max = vec[i];
  }
  
  Table<Image> tbl( m_bins, m_min, m_max );
  m_tbl = tbl;
  for( size_t j = 0; j < vec.size(); j++ ) {
      m_tbl.add( vec[j] );
  }
}

// classification
Image HRSTableSearch::classify( const Image& img )
{
  return m_tbl.find_closest( img );
}
