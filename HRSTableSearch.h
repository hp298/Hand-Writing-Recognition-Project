//========================================================================
// HRSTableSearch.h
//========================================================================
// Handwritten recognition system that uses linear search.

#ifndef HRS_TABLE_SEARCH_H
#define HRS_TABLE_SEARCH_H

#include "IHandwritingRecSys.h"
#include "Image.h"
#include "Table.h"

// Here we use forward declaration instead of #include. Forward
// declaration is a declaration of an identifier (type, variable, or
// class) before giving a complete definition.
//
// We should use forward declaration whenever possible. Using forward
// declaration is almost always better than using #include because
// #include may have some side effects such as:
// - including other headers you don't need
// - polluting the namespcae
// - longer compilation time

template < typename T >
class Vector;

//------------------------------------------------------------------------
// HRSTableSearch
//------------------------------------------------------------------------

class HRSTableSearch : public IHandwritingRecSys
{
public:
  HRSTableSearch( unsigned int K = 1000 );

  void  train   ( const Vector<Image>& vec );
  Image classify( const Image& img       );

private:
  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Declare private data members and member functions. Note that
  // according to our naming convention, data member's name should starts
  // with a `m_` prefix.
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  unsigned int m_k;
  Vector<Image> m_vec;
  Image m_min;
  Image m_max;
  unsigned int m_bins;
  Table<Image> m_tbl;
};

#endif
