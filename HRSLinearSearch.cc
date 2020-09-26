//========================================================================
// HRSLinearSearch.cc
//========================================================================
// Handwritten recognition system that uses linear search.

#include <iostream>
#include <cstddef>
#include "Image.h"
#include "HRSLinearSearch.h"

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement HRSLinearSearch.
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

// default constructor
HRSLinearSearch::HRSLinearSearch()
{

}

// Training
void HRSLinearSearch::train( const Vector<Image>& vec )
{
  m_vec = vec;
}

// Classification
Image HRSLinearSearch::classify( const Image& img )
{
  return m_vec.find_closest(img);
}
