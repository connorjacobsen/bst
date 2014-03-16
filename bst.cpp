/*
 * This is the implementation file for the bst header file.
 */

#include "bst.h"

/* Node Constructor */
Node::Node()
{
  leftChild = nullptr;
  rightChild = nullptr;
}

/* Node Member Function Implementations */

bool Node::hasLeftChild()
{
  if ( leftChild == nullptr )
    return false;

  return true;
}

bool Node::hasRightChild()
{
  if ( rightChild == nullptr )
    return false;

  return true;
}

void Node::insert( int value )
{
  if ( value < data )
  {
    // the data should go to the left
    if ( hasLeftChild() ) // if already has a leftChild, keep traversing
      leftChild->insert( value );
    else
    {
      Node* tmp = new Node();
      tmp->data = value;
      leftChild = tmp; // insert the data as the leftChild
    }
  }
  else // data < value
  {
    // data should go to the right
    if ( hasRightChild() ) // if already has a rightChild, keep traversing
      rightChild->insert( value );
    else
    {
      Node* tmp = new Node();
      tmp->data = value;
      rightChild = tmp; // insert the value as rightChild
    }
  }
}

void Node::remove( int const value )
{
  if ( leftChild->data == value ) // THIS
  {
    // Delete a leaf: we can simply remove it
    if ( !(leftChild->hasLeftChild()) && !(leftChild->hasRightChild()) )
    {
      Node* tmp = leftChild;
      delete tmp;
      leftChild = nullptr;
      return;
    }
    // Deleting a Node that has only one child:
    // the child replaces the parent.
    if ( leftChild->hasLeftChild() && !(leftChild->hasRightChild()) )
    {
      // Replace Node with leftChild and delete
      Node* tmp = leftChild->leftChild; // ptr to leftChild
      if ( leftChild->hasLeftChild() )
	tmp->leftChild = leftChild->leftChild;
      if ( leftChild->hasRightChild() )
	tmp->rightChild = leftChild->rightChild;
      // Now we can 
    }
    if ( leftChild->hasRightChild() && !(leftChild->hasLeftChild()) )
    {
      // Replace Node with rightChild and delete 
    }
  }
  if ( rightChild->data == value ) // THIS
  {
    // Delete a leaf: we can simply remove it
    if ( !(rightChild->hasLeftChild()) && !(rightChild->hasRightChild()) )
    {
      Node* tmp = rightChild;
      delete tmp;
      rightChild = nullptr;
      return;
    }
    // Deleting a Node that has only one child:
    // the child replaces the parent.
    if ( leftChild->hasLeftChild() && !(leftChild->hasRightChild()) )
    {
      // Replace Node with leftChild and delete
    }
    if ( leftChild->hasRightChild() && !(leftChild->hasLeftChild()) )
    {
      // Replace Node with rightChild and delete 
    }
  }

  else // Go find the right Node
  {
    if ( value < data )
    {
      if ( hasLeftChild() ) // should be to the left
	leftChild->remove( value );
    }
    else // value > data
    {
      if ( hasRightChild() ) // should be to the right
	rightChild->remove( value );
    }
  }
}

bool Node::contains( int const value )
{
  if ( data == value )
    return true;
  else
  {
    if ( value < data )
    {
      if ( hasLeftChild() ) // if left child, check there
	return leftChild->contains( value );
      else                  // else, return false.
	return false;
    }
    else // value > data
    {
      if ( hasRightChild() ) // if right child, check there
	return rightChild->contains( value );
      else
	return false;        // else, return false.
    }
  }
}

unsigned int Node::size()
{
  if ( !hasLeftChild() && !hasRightChild() )
    return 1;
  else if ( hasLeftChild() && !hasRightChild() )
    return leftChild->size() + 1;
  else if ( hasRightChild() && !hasLeftChild() )
    return 1 + rightChild->size();
  else
    return leftChild->size() + 1 + rightChild->size();
}

void Node::printContentsInOrder()
{
  // Left
  if ( hasLeftChild() )
    leftChild->printContentsInOrder();
  // This
  std::cout << data << " ";
  // Right
  if ( hasRightChild() )
    rightChild->printContentsInOrder();
}

void Node::printContentsPreOrder()
{
  // Do something with this Node
  std::cout << data << " ";
  // Left
  if ( hasLeftChild() )
    leftChild->printContentsPreOrder();
  // Right
  if (hasRightChild() )
    rightChild->printContentsPreOrder();
}

void Node::printContentsPostOrder()
{
  // Left
  if ( hasLeftChild() )
    leftChild->printContentsPostOrder();
  // Right
  if ( hasRightChild() )
    rightChild->printContentsPostOrder();
  // This
  std::cout << data << " ";
}

unsigned int Node::height()
{
  // compute depth of each subtree
  unsigned int lDepth = ( hasLeftChild() ) ? leftChild->height() : 0; 
  unsigned int rDepth = ( hasRightChild() ) ? rightChild->height() : 0;

  // use the larger one
  if ( lDepth > rDepth )
    return 1 + lDepth;
  else
    return 1 + rDepth;
}


/* BST Main Member Function Implementations */

void BinarySearchTree::insert( int value )
{
  if ( empty() ) // insert at the root
  {
    Node* tmp = new Node();
    root = tmp;
    tmp->data = value;
    // leftChild and rightChild initialized by constructor
  }
  else // pass it to the Nodes
    root->insert( value );
}

void BinarySearchTree::remove( int const value )
{
  if ( empty() ) // Nothing to remove!
  {
    std::cout << "Empty!" << std::endl;
    return;
  }
  if ( !contains( value ) ) // Value not in tree!
  {
    std::cout << "ERROR: Value not in tree!" << std::endl;
    return;
  }
  
  if ( root->data == value )
  {
    if ( !( root->hasRightChild() ) )
    {
      Node* tmp = root;
      root = root->leftChild;
      delete tmp; // kill the original root Node
    }
    else
    {
      Node* tmp = root;
      root = tmp->rightChild;
      Node* node = tmp->rightChild;
      while ( node->hasLeftChild() )
	node = node->leftChild;
      node->leftChild = tmp->leftChild;
    }
    return;
  }
  
  Node* previous = root;
  Node* node = root;
  while ( true )
  {
    if ( node->data > value )
    {
      if ( node->hasLeftChild() )
      {
	previous = node;
	node = node->leftChild;
      }
    }
    else if ( node->data < value )
    {
      if ( node->hasRightChild() )
      {
	previous = node;
	node = node->rightChild;
      }
    }
    else if ( node->data == value )
    {
      if ( previous->data > value )
      {
	if ( !(node->hasRightChild()) )
	{
	  if ( node->hasLeftChild() )
	    previous-leftChild = node->leftChild;
	  else
	    previous->leftChild = nullptr;
	}
      }
      else 
      {
	previous->leftChild = node->rightChild;
	if ( !(node->hasLeftChild()) )
	{
	  Node* tmp = node->rightChild;
	  while ( !(tmp->hasLeftChild() ) )
	    tmp = tmp->leftChild;
	  tmp->leftChild = node->leftChild;
	}
      }
    }
    else if ( previous->data < value )
    {
      if ( !(node->hasLeftChild()) )
      {
	if ( !(node->hasRightChild() ) )
	  previou->rightChild = nullptr;
	else
	  previous->rightChild = node->rightChild;
      }
      else
      {
	previous->rightChild = node->leftChild;
	if ( node->hasRightChild() )
	{
	  Node* tmp = node->left;
	  while ( tmp->hasRightChild() )
	    tmp = tmp->rightChild;
	  tmp->right = node->right;
	}
      }
    }
    return;
  }
}

bool BinarySearchTree::contains( int const value ) 
{
  if ( empty() )
    return false;
  else
    return root->contains( value );
}

unsigned int BinarySearchTree::size()
{
  if ( empty() )
    return 0;
  else
    return root->size();
}

void BinarySearchTree::printContentsInOrder()
{
  if ( empty() ) 
    std::cout << "Empty!" << std::endl;
  else
  {
    root->printContentsInOrder();
    std::cout << std::endl;
  }
}

void BinarySearchTree::printContentsPreOrder()
{
  if ( empty() )
    std::cout << "Empty!" << std::endl;
  else
  {
    root->printContentsPreOrder();
    std::cout << std::endl;
  }
}

void BinarySearchTree::printContentsPostOrder()
{
  if ( empty() )
    std::cout << "Empty!" << std::endl;
  else
  {
    root->printContentsPostOrder();
    std::cout << std::endl;
  }
}

unsigned int BinarySearchTree::height()
{
  if ( empty() )
    return 0;
  else
    return root->height();
}


/* BST Helper Member Function Implementations */
bool BinarySearchTree::empty()
{
  if ( root == nullptr )
    return true;

  return false;
}
