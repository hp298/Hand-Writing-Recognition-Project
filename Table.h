//========================================================================
// Table.h
//========================================================================
// Declarations for generic table.

#ifndef TABLE_H
#define TABLE_H

#include <cstddef>

template < typename T >
class Vector;

template < typename T >
class Table
{
 public:
  Table( unsigned int nbins = 1, T min = T(), T max = T() );
  ~Table();
  Table( const Table<T>& table );
  
  Table<T>& operator=(const Table<T>& table);

  // Methods
  size_t   size() const;
  void     add( const T& value );
  bool     find( const T& value ) ;
  const T& find_closest( const T& value ) ;
  void     print() const;


 private:
  //'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''
  // Declare private data members and member functions. Note that
  // according to our naming convention, data member's name should starts
  // with a `m_` prefix.
  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
  unsigned int m_nbins = 0;
  T m_min;
  T m_max;
  size_t m_size;
  Vector<T>* m_vecBins;
  int m_range;
  
  size_t get_bin(T value);
};

// Include inline definitions
#include "Table.inl"

#endif /* TABLE_H */

