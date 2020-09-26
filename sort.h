//========================================================================
// sort.h
//========================================================================
// Declarations for generic sort algorithm.

#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

template < typename T >
void sort( T* a, size_t size );
template < typename T >
void sort_h( T* a, size_t begin, size_t end );
template < typename T >
void lin_sort( T* a, size_t begin, size_t end );

// Include inline definitions
#include "sort.inl"

#endif  // SORT_H

