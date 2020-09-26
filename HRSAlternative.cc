//========================================================================
// HRSAlternative.cc
//========================================================================
// Alternative HRS implementation.

#include <cstddef>
#include <iostream>
#include "IHandwritingRecSys.h"
#include "Image.h"
#include "Vector.h"
#include "HRSAlternative.h"
#include "ece2400-stdlib.h"

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement HRSAlternative.
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

// K Nearest Neighbors

// default constructor
HRSAlternative::HRSAlternative( unsigned int K )
{
  m_k = K;
}

// training
void HRSAlternative::train( const Vector<Image>& vec )
{
  if ( m_k >= vec.size() )
    throw ece2400::OutOfRange("The vector is empty.");
  m_vec = vec;
  Vector<int> imgVec;
  size_t imgRows = m_vec[0].get_nrows();
  size_t imgCols = m_vec[0].get_ncols();
  size_t imgSize = imgRows * imgCols;
  
  for( size_t i = 0; i < imgSize; i++ )
    imgVec.push_back( 0 );
  
  Image tempImg( imgVec, imgCols, imgRows );
  
  m_empty = tempImg;
}

