//========================================================================
// Image.h
//========================================================================
// Declarations for Image.

#ifndef IMAGE_H
#define IMAGE_H

#include "Vector.h"

#include <iostream>
#include <cstddef>

class Image
{
 public:
  // Constructors
  Image();
  Image( const Vector<int>& vec, size_t ncols, size_t nrows );

  // Methods
  size_t get_ncols() const;
  size_t get_nrows() const;
  int    at( size_t x, size_t y ) const;
  void   set_label( char l );
  char   get_label() const;
  int    get_intensity() const;
  void   print() const;

  // Operator overloading
  int  operator- ( const Image& rhs ) const;
  bool operator< ( const Image& rhs ) const;
  bool operator> ( const Image& rhs ) const;
  bool operator<=( const Image& rhs ) const;
  bool operator>=( const Image& rhs ) const;
  bool operator==( const Image& rhs ) const;
  bool operator!=( const Image& rhs ) const;

  friend std::ostream& operator<<( std::ostream& output,
                                   const Image& image );

 private:
  Vector<int> m_vec;
  size_t m_cols;
  size_t m_rows;
  int m_intensity;
  char m_label;
};

// Include inline definitions
#include "Image.inl"

#endif  // IMAGE_H

