//========================================================================
// HRSTreeSearch.cc
//========================================================================
// Definitions for HRSTreeSearch

#include "HRSTreeSearch.h"
#include "Vector.h"
#include "Tree.h"
#include "Image.h"

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement HRSBinarySearch.
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

// default constructor
HRSTreeSearch::HRSTreeSearch( unsigned int K)
{
  m_k = K;
  Tree<Image> temp(m_k);
  m_tree = temp;
}

// Training
void HRSTreeSearch::train( const Vector<Image>& vec )
{
  for( size_t i = 0; i < vec.size(); i++ )
    m_tree.add(vec[i]);
}

// Classification
Image HRSTreeSearch::classify( const Image& img )
{
  return m_tree.find_closest( img );
}
