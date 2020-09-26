//========================================================================
// Image.cc
//========================================================================
// Implementations for Image.

#include <iostream>
#include "Image.h"
#include "ece2400-stdlib.h"

//------------------------------------------------------------------------
// print_pixel
//------------------------------------------------------------------------
// A helper function that prints a grayscale pixel using unicode based on
// the integer value.

void print_pixel( int v )
{
  if ( v <= 0 )
    std::cout << "  ";
  else if ( 0 < v && v <= 64 )
    std::cout << "\u2591\u2591";
  else if ( 64 < v && v <= 128 )
    std::cout << "\u2592\u2592";
  else if ( 128 < v && v <= 192 )
    std::cout << "\u2593\u2593";
  else
    std::cout << "\u2588\u2588";
}

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement Image.
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

// default constructor
Image::Image()
{
   m_cols = 0 ;
   m_rows = 0;
   m_label = '?';
   m_intensity = 0;
}

// non-default constructor
Image::Image( const Vector<int>& vec, size_t ncols, size_t nrows )
{
   if (nrows * ncols != vec.size() )
     throw ece2400::InvalidArgument("Size does not match the number of columns and number of rows.") ;
   m_vec = vec;
   m_cols = ncols ;
   m_rows = nrows ;
   m_label = '?';
   m_intensity = 0;
   for( size_t i = 0; i < m_vec.size(); i++)
     m_intensity = m_intensity + m_vec[i];
}

// Image get_ncols
size_t Image::get_ncols() const
{
  return m_cols;
}

// Image get_nrows
size_t Image::get_nrows() const
{
  return m_rows;
}

// Image at
int Image::at( size_t x, size_t y ) const
{
  if ( ( m_vec.size() == 0 ) || ( ( x >= m_cols ) || ( y >= m_rows ) ) )
     throw ece2400::OutOfRange("Out of range");
  return m_vec[ x + ( y * ( m_cols ) ) ];
}

// Image set_label
void Image::set_label( char label )
{
  m_label = label;
}

// Image get_intensity
int Image::get_intensity() const
{
  return m_intensity;
}

// Image print
void Image::print() const
{
  for( size_t i = 0; i < m_rows; i++) {
    for( size_t j = 0; j < m_cols; j++) {
      print_pixel(at(j,i));
    }
    printf("\n") ;
  }
}



// < operator
bool Image::operator< ( const Image& rhs ) const
{
  return get_intensity() < rhs.get_intensity();
}

// > operator
bool Image::operator> ( const Image& rhs ) const
{
   return get_intensity() > rhs.get_intensity();
}

// <= operator
bool Image::operator<=( const Image& rhs ) const
{
  return get_intensity() <= rhs.get_intensity();
}

// >= operator
bool Image::operator>=( const Image& rhs ) const
{
  return get_intensity() >= rhs.get_intensity();
}

// == operator
bool Image::operator==( const Image& rhs ) const
{
  if ( ( m_cols != rhs.get_ncols() ) || ( m_rows != rhs.get_nrows() ) )
    return false;

  for(size_t i = 0; i < m_cols; i++) {   
    for(size_t j = 0; j < m_rows; j++) {   
      if ( at(i,j) != rhs.at(i,j) )
        return false;
    }
  }
  
  return true;
}

// != operator
bool Image::operator!=( const Image& rhs ) const
{
  if ( ( m_cols != rhs.get_ncols() ) || ( m_rows != rhs.get_nrows() ) )
     return true;

  for(size_t i = 0; i < m_cols; i++) {  
    for(size_t j = 0; j < m_rows; j++) { 
      if ( at(i,j) != rhs.at(i,j) )
        return true;
    }        
  }
  
  return false;
}
