//========================================================================
// sort.inl
//========================================================================
// Definition of generic sort algorithm.

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement the generic sort algorithm.
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//#include "ece2400-stdlib.h"
//#include "sort.h"

template < typename T >
inline void sort( T* a, size_t size )
{
  if ( size <= 1 )
    return;
  
  sort_h( a, 0, size);
  
}

template < typename T >
inline void sort_h( T* a, size_t begin, size_t end )
{
  size_t size = ( end - begin );
  
  if ( size < 9 ) {
    lin_sort( a, begin, end );
  }
  else {
    size_t p = end - 1;
  
    T pivot = a[p];
    size_t idx = begin;
    T temp;
  
    for( size_t i = begin; i < end; i++ ) {
      if ( a[i] <= pivot ) {
        temp = a[i];
        a[i] = a[idx];
        a[idx] = temp;
        idx++;
      }
    }
    sort_h( a, begin, idx-1);
    sort_h( a, idx, end);
  }
}

template < typename T >
inline void lin_sort( T* a, size_t begin, size_t end )
{
  if ( ( end - begin ) < 2 )
    return;
    
  T minVal;
  size_t minIdx;
  T temp;
  for( size_t i = begin; i < end; i++ ) {
    minVal = a[i];
    minIdx = i;
    for( size_t j = i; j < end; j++ ) {
      if ( a[j] < minVal ) {
        minVal = a[j];
        minIdx = j;
      }
    }
    temp = a[i];
    a[i] = a[minIdx];
    a[minIdx] = temp;
  }
}
