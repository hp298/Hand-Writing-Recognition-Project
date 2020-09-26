//========================================================================
// Vector.h
//========================================================================
// Declarations for Vector.

#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <iostream>

template < typename T >
class Vector
{
 public:
  Vector();
  ~Vector();

  // Copy constructor
  Vector( const Vector<T>& vec );

  // Construct from an array
  Vector( T* a, size_t size );

  // Methods
  size_t   size() const;
  void     push_back( const T& v );
  const T& at( size_t idx ) const;
  T&       at( size_t idx );
  bool     find( const T& v ) const;
  const T& find_closest( const T& v ) const;
  void     sort();
  void     print() const;
  const T& find_closest_alt( const T& v);

  // Operator overloading
  const T&   operator[]( size_t idx ) const;
  T&         operator[]( size_t idx );
  Vector<T>& operator=( const Vector<T>& vec );

  size_t m_altVar;
 private:
  size_t m_size = 0;
  size_t m_maxSize = 0;
  T *m_a;
  
  void clear();
  void copy( T *a, size_t size, size_t maxSize );
};

// Include inline definitions
#include "Vector.inl"

#endif  // VECTOR_H

