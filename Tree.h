//========================================================================
// Tree.h
//========================================================================
// Declarations for generic tree.

#ifndef TREE_H
#define TREE_H

#include <cstddef>
#include "Image.h"

template < typename T >
class Tree
{
 public:
  Tree( unsigned int K = 0 );
  ~Tree();

  // Copy constructor
  Tree( const Tree<T>& tree );

  // Methods
  size_t   size() const;
  void     add( const T& value );
  bool     find( const T& value );
  const T& find_closest( const T& value );
  void     print();

  // Operator overloading
  Tree<T>& operator=( const Tree<T>& tree );
  
  // Node
  struct Node
  {
    T value;
    Node* left = nullptr;
    Node* right = nullptr;
  };
  
 private:
   
   size_t m_size = 0;
   Node* m_root;
   unsigned int m_k;
   unsigned int m_diff;
   T m_closest;
  
   void dstruct( Node* arrow );
   void copy( Node* treeArrow, Node* arrow );
   Node* pointer( T value, Node* arrow );
   bool find_h( T value, Node* arrow );
   void find_closest_h( T value, Node* arrow );
   void print_h( Node* arrow );
  
};

// Include inline definitions
#include "Tree.inl"

#endif /* TREE_H */
