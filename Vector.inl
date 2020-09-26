//========================================================================
// Vector.inl
//========================================================================
// Implementation of Vector.

#include "ece2400-stdlib.h"
#include "sort.h"

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement Vector.
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

// default constructor
template < typename T >
Vector<T>::Vector()
{
  m_size = 0;
  m_maxSize = 1;
  m_a = new T[1];
}

// destructor
template < typename T >
Vector<T>::~Vector()
{
  if (m_maxSize != 0)
    clear();
}

// copy constructor
template < typename T >
Vector<T>::Vector( const Vector<T>& vec )
{
  copy( vec.m_a, vec.m_size, vec.m_maxSize );
}

// non-default constructor
template < typename T >
Vector<T>::Vector( T* a, size_t size )
{
  if ( size == 0 )
    Vector<T>();
  else
    copy( a, size, size );
}

// = operator
template < typename T >
Vector<T>& Vector<T>::operator=( const Vector<T>& vec )
{
  if ( this != &vec )
    copy( vec.m_a, vec.m_size, vec.m_maxSize );
  return *this;
}

// size function
template < typename T >
size_t Vector<T>::size() const
{
  return m_size;
}

// vector push back
template < typename T >
void Vector<T>::push_back( const T& v )
{
  if ( m_maxSize == 0 ) {
    clear();
    m_maxSize = 1;
    m_a = new T[1];
  }
  
  if ( m_size >= m_maxSize ) {
    T *a = new T[m_size];
    for ( size_t i = 0; i < m_size; i++ )
      a[i] = m_a[i];
      
    size_t size = m_size;
    size_t maxSize = ( 2 * size );
    copy( a, size, maxSize );
    delete[] a;
  }
  m_a[m_size] = v;
  m_size++;
}

// at const
template < typename T >
const T& Vector<T>::at( size_t idx ) const
{
  if ( idx < m_size )
    return m_a[idx];
  else
    throw ece2400::OutOfRange("Index value must be less the size.");
}

// at
template < typename T >
T& Vector<T>::at( size_t idx )
{
  if ( idx < m_size )
    return m_a[idx];
  else
    throw ece2400::OutOfRange("Index value must be less the size.");
}

// find
template < typename T >
bool Vector<T>::find( const T& v ) const
{
  for ( size_t i = 0; i < m_size; i++ ) {
    if ( m_a[i] == v )
      return true;
  }
  return false;
}

// find closests
template < typename T >
const T& Vector<T>::find_closest( const T& v ) const
{
  if ( m_size < 2 ) {
    if ( m_size == 0 )
      throw ece2400::OutOfRange("The vector is empty.");
    return m_a[0];
  }
  
  size_t closestIdx = 0;
  auto min =  abs( m_a[0] - v );
  for( size_t i = 0; i < m_size; i++ ) {
    auto diff = abs( m_a[i] - v );
    
    if ( diff == 0 )
      return m_a[i];
      
    if ( diff < min ) {
      closestIdx = i;
      min = abs( m_a[i] - v );
    }
  }
  
  return m_a[closestIdx];
}

// sort
template < typename T >
void Vector<T>::sort()
{
  ::sort( m_a, m_size);
}

// print
template < typename T >
void Vector<T>::print() const
{
  for( size_t i = 0; i < m_size; i++ )
    m_a[i].print();
  printf( "\n" );
}

// [] op const
template < typename T >
const T& Vector<T>::operator[]( size_t idx ) const
{
  return m_a[idx];
}

// [] op
template < typename T >
T& Vector<T>::operator[]( size_t idx )
{
  return m_a[idx];
}

// clear helper
template < typename T >
void Vector<T>::clear()
{
  delete[] m_a;
  m_size = 0;
  m_maxSize = 0;
}

// copy helper
template < typename T >
void Vector<T>::copy( T *a, size_t size, size_t maxSize )
{
  if ( m_maxSize != 0 )
    clear();
  m_size = size;
  m_maxSize = maxSize;
  m_a = new T[m_maxSize];
  for( size_t i = 0; i < m_size; i++ )
    m_a[i] = a[i];
}

// hrs-alt find closests
template < typename T >
const T& Vector<T>::find_closest_alt( const T& v)
{
  size_t closestIdx = 0;
  auto min =  abs( m_a[0] - v );
  for( size_t i = 0; i < m_size; i++ ) {
    auto diff = abs( m_a[i] - v );
    
    if ( diff == 0 )
      return m_a[i];
      
    if ( diff < min ) {
      closestIdx = i;
      min = abs( m_a[i] - v );
    }
  }
  
  m_altVar = closestIdx;
  return m_a[closestIdx];
}
