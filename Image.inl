//========================================================================
// Image.inl
//========================================================================
// Implementations for inline functions for Image. This is for
// optimization purpose only. It is fine to leave this file empty.
//
// To inline a member function, simply use the inline keyword. For
// exmaple, to inline the get_ncols function, you need to put the
// definition of get_ncols in this file with the inline keyword like
// this:
//
// inline size_t Image::get_ncols() const
// {
//   ...
// }
//
// Think critically about which functions you want to inline! Note that
// inlining might HURT PERFORMANCE as it will cause your code to bloat.
// In other words, the executable size might be too big such that the
// system may spend most of its time fetching the next chunk of code from
// the disk.
#include "ece2400-stdlib.h"
// - operator
inline int Image::operator- ( const Image& rhs ) const
{   
  if ( ( m_cols != rhs.get_ncols() ) || ( m_rows != rhs.get_nrows() ) )
    throw  ece2400::InvalidArgument("Dimensions does not match");
   
  int sum = 0;
  int diff;
  size_t size = m_vec.size();
  for( size_t i = 0; i < size; i++) {
    diff =  m_vec[i] - rhs.m_vec[i];
    sum += (diff * diff);
  }
  return sum;
}

// Image get_label
inline char Image::get_label() const
{
  return m_label;  
}
