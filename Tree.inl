//========================================================================
// Tree.inl
//========================================================================
// Implementation of Tree.

#include "ece2400-stdlib.h"
#include <cassert>
#include <iostream>

//'''' ASSIGNMENT TASK '''''''''''''''''''''''''''''''''''''''''''''''''''
// Implement Tree.
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

// default constructor
template < typename T >
Tree<T>::Tree( unsigned int K )
{
  m_k = K;
  m_size = 0;
  m_root = nullptr;
}

// destructor
template < typename T >
Tree<T>::~Tree()
{
  if ( m_size == 0 )
    return;
  dstruct( m_root );
}

// destuct helper
template < typename T >
void Tree<T>::dstruct( Node* arrow )
{
  if ( ( arrow->left == nullptr ) && ( arrow->right == nullptr ) ) {
    delete arrow;
    m_size = 0;
    m_root = nullptr;
    return;  
  }
  if ( arrow->left != nullptr )
    dstruct( arrow->left );
  if ( arrow->right != nullptr )
    dstruct( arrow->right );
}

// copy constructor
template < typename T >
Tree<T>::Tree( const Tree<T>& tree )
{
  if ( tree.size() == 0 )
    return;
  
  Node* node = new Node;
  node->value = tree.m_root->value;
  m_root = node;
  m_size = tree.m_size;
  copy( tree.m_root, m_root );
}

// = operator
template < typename T >
Tree<T>& Tree<T>::operator=( const Tree<T>& tree )
{
  if ( this == &tree )
    return *this;
  
  if ( m_size != 0 )
    dstruct( m_root ); 
    
  m_size = tree.m_size;
  
  if ( tree.size() != 0 ) {
    Node* node = new Node;
    node->value = tree.m_root->value;
    m_root = node;
    m_size = tree.m_size;
    copy( tree.m_root, m_root );
  }
  m_k = tree.m_k;
  return *this;
}

// copy helper
template < typename T >
void Tree<T>::copy( Node* treeArrow, Node* arrow )
{
  if ( treeArrow->left != nullptr ) {
    Node* node = new Node;
    node->value = treeArrow->left->value;
    arrow->left = node;
    copy( treeArrow->left, arrow->left );
    
  }
  
  if ( treeArrow->right != nullptr ) {
    Node* node = new Node;
    node->value = treeArrow->right->value;
    arrow->right = node;
    copy( treeArrow->right, arrow->right );
  }
  
}

// size
template < typename T >
size_t Tree<T>::size() const
{
  return m_size;
}

// add
template < typename T >
void Tree<T>::add( const T& value )
{
  // empty tree
  if ( m_root == nullptr ) {
    m_root = new Node;
    m_root->value = value;
    m_size++;
  }
  // non-empty tree
  else {
    // value not in tree
    if ( find( value ) == false ) {
      Node* node = new Node;
      node->value = value;
      Node* temp = pointer( value, m_root );
      if ( temp->value > value )
        temp->left = node;
      else
        temp->right = node;
      m_size++;
    }
  }
}

// find
template < typename T >
bool Tree<T>::find( const T& value )
{
  if (m_size == 0)
    return false;
  
  T v = value;
  return find_h( v, m_root );
}

// find helper
template < typename T >
bool Tree<T>::find_h( T value, Node* arrow )
{
  T nVal = arrow->value;
  if ( value == nVal )
    return true;
  
  if ( value < nVal ) {
    if ( arrow->left != nullptr )
      return find_h( value, arrow->left );
    return false;
  }
  else {
    if ( arrow->right != nullptr )
      return find_h( value, arrow->right );
    return false;
  }
}

// find_closest
template < typename T >
const T& Tree<T>::find_closest( const T& value )
{
  if ( m_size == 0 )
    throw ece2400::OutOfRange(" Can not find closest. Tree is empty. ");
  
  int totalLvls = ece2400::log2( m_size );
  int exhastLvls = ece2400::log2( m_k );
  int binaryLvls = totalLvls - exhastLvls;
  if ( binaryLvls < 0 )
    binaryLvls = 0;
  
  Node* temp = m_root;
  for( int i = 0; i < binaryLvls; i++ ) {
    if ( value < temp->value )
      temp = temp->left;
    else if ( value > temp->value )
      temp = temp->right;
    else
      return temp->value;
  }
  m_diff = -1;
  find_closest_h( value, temp );
  return m_closest;
}

// find_closest helper
template < typename T >
void Tree<T>::find_closest_h( T value, Node* arrow )
{
  if ( m_diff == 0 ) return;
  
  unsigned int diff = ece2400::abs_dist( arrow->value, value );
  
  if ( diff < m_diff ) {
    m_diff = diff;
    m_closest = arrow->value;  
  }
  
  if ( arrow->left != nullptr )
    find_closest_h( value, arrow->left );

  if ( arrow->right != nullptr )
    find_closest_h( value, arrow->right );
  
}

// print
template < typename T >
void Tree<T>::print()
{
  if ( m_size != 0 )
    print_h( m_root );
}

// print helper
template < typename T >
void Tree<T>::print_h( Node* arrow )
{
  if ( arrow->left != nullptr )
    print_h( arrow->left );
  arrow->value.print(); 
  if ( arrow->right != nullptr )
    print_h( arrow->right );
}

// helper that returns a pointer to node of value or where it would go
template < typename T >
typename Tree<T>::Node* Tree<T>::pointer( T value, Node* arrow )
{
  if ( arrow->value > value ) {
    if ( arrow->left == nullptr )
      return arrow;
    else
      return pointer( value, arrow->left );
  }
  else if ( arrow->value < value ) {
    if ( arrow->right == nullptr )
      return arrow;
    else
      return pointer( value, arrow->right);
  }
  else
    return arrow;
}
