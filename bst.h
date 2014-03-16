/*
 * This is the header file for the bst.cpp implementation file.
 */

#include <iostream>

struct Node
{
  /* Node Data Members */

  int data;          // data held by the Node
  Node* leftChild;   // pointer to leftChild Node
  Node* rightChild;  // pointer to rightChild Node

  /* Node Constructor */
  Node();


  /* Node Member Functions */
  
  bool hasLeftChild();
  // Returns true if the Node has a left child, false otherwise.

  bool hasRightChild();
  // Returns true if the Node has a right child, false otherwise.

  void insert( int value );
  // Recursively inserts given value.

  void remove( int const value );
  // removes Node with Value from BST

  bool contains( int const value );
  // Returns 1 if Node contains value, 0 if not.

  unsigned int size();
  // Returns the number of Nodes.

  void printContentsInOrder();
  // Prints the Node's contents in-order.

  void printContentsPreOrder();
  // Prints the Node's contents preorder.

  void printContentsPostOrder();
  // Prints the Node's contents postorder.

  unsigned int height();
  // Returns the max tree depth from the current Node
};

struct BinarySearchTree
{
  /* BST Data Members */

  Node* root;        // pointer to the BST's root Node

  /* Constructor and Destructor */
  BinarySearchTree() { root = nullptr; }

  // should probably have a destructor here...oops?


  /* BST Main Member Functions */

  void insert( int value );
  // Will insert an integer value into the BST.
  // However, if the value already exists in the BST it will output
  // an error message and return without inserting anything.

  void remove( int value );
  // Will remove the given integer value from the BST.
  // Will reorganize the tree accordingly if the value being
  // removed is not a leaf ( Node without children ).

  bool contains( int const value );
  // Returns true if the BST contains the value, false otherwise.

  unsigned int size();
  // Returns the number of Nodes in the BST.

  void printContentsInOrder();
  // Prints the contents of the BST In-Order.

  void printContentsPreOrder();
  // Prints the contents of the BST Preorder.

  void printContentsPostOrder();
  // Prints the contents of the BST Postorder.

  unsigned int height();
  // Returns the depth ( # of levels ) of the BST.

  
  /* BST Helper Member Functions */

  bool empty();
  // Returns true if the BST is empty, false otherwise.
};
