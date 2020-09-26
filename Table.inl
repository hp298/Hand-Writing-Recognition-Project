//========================================================================
// Table.inl
//========================================================================
// Implementation of Table.

#include "ece2400-stdlib.h"
#include "Vector.h"
#include <iostream>

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement Table.
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

// default constructor
template < typename T >
Table<T>::Table( unsigned int nbins, T min, T max )
{
  if ( ( nbins == 0 ) || ( max < min ) )
    throw ece2400::InvalidArgument();

  m_nbins = nbins;
  m_min = min;
  m_max = max;
  m_size = 0;
  m_vecBins = new Vector<T>[m_nbins];
  m_range = ( m_max - m_min ) / m_nbins;
}

// destructor
template < typename T >
Table<T>::~Table()
{
  delete[] m_vecBins;
}

// copy constructor
template < typename T >
Table<T>::Table( const Table<T>& table )
{
  m_vecBins = new Vector<T>[table.m_nbins];
  m_nbins = table.m_nbins;
  m_min = table.m_min;
  m_max = table.m_max;
  m_size = table.m_size;
  m_range = table.m_range;
  
  for( size_t i = 0; i < m_nbins; i++ ) {
    m_vecBins[i] = table.m_vecBins[i];
  }
}

// = operator
template < typename T >
Table<T>& Table<T>::operator=( const Table<T>& table )
{
  if ( this == &table )
    return *this;
  delete[] m_vecBins;
  m_vecBins = new Vector<T>[table.m_nbins];  
  m_nbins = table.m_nbins;
  m_min = table.m_min;
  m_max = table.m_max;
  m_size = table.m_size;
  m_range = table.m_range;
  
  for( size_t i = 0; i < m_nbins; i++ ) {
    m_vecBins[i] = table.m_vecBins[i];
  }
  
  return *this;
}

// size
template < typename T >
size_t Table<T>::size() const
{
  return m_size;
}

// add
template < typename T >
void Table<T>::add( const T& value )
{
  size_t idx = get_bin(value);
  m_vecBins[idx].push_back(value);
  m_size++; 
}

// find
template < typename T >
bool Table<T>::find( const T& value ) 
{
  if ( m_size == 0 )
    return false;
  size_t idx = get_bin(value);
  return m_vecBins[idx].find(value);
}

// find closest
template < typename T >
const T& Table<T>::find_closest( const T& value ) 
{
  if ( m_size == 0 )
    throw ece2400::OutOfRange(" The Table Is Empty! ");
  
  size_t idx = get_bin(value);
  for( size_t i = 0; i < m_nbins; i++ ) {
    if ((( idx + i ) < m_nbins ) && ( m_vecBins[idx + i].size() != 0 ))
        return m_vecBins[idx + i].find_closest(value);
    if ((( idx - i ) >= 0 ) && ( m_vecBins[idx - i].size() != 0 ))
        return m_vecBins[idx - i].find_closest(value);
  }
  
  
  return m_vecBins[idx].find_closest(value);
}

// print
template < typename T >
void Table<T>::print() const
{
  for( size_t i = 0; i < m_nbins; i++ )
    m_vecBins[i].print();
}

// get bin helper
template < typename T >
size_t Table<T>::get_bin( T value )
{
  int t = m_range;
  if ( t == 0 )
    return 0;
  int s = value - m_min;
  size_t i = 0;
  
  while( s > t ){
    t += m_range; 
    i++;
  }
  
  if ( i >= m_nbins )
    return m_nbins - 1;
  
  return i;
}
