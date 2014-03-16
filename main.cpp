#include "bst.h"

int main()
{
  // Create an empty BinarySearchTree
  BinarySearchTree* bst = new BinarySearchTree();

  // Test the empty() helper.
  std::cout << "Empty? " << bst->empty() << std::endl;

  // print the empty list preorder
  bst->printContentsPreOrder();

  // Insert a new Node
  bst->insert( 42 );

  // Shouldn't be empty now
  std::cout << "Empty? " << bst->empty() << std::endl;

  // Print the list again
  bst->printContentsPreOrder();

  // Insert another node
  bst->insert( 23 );

  // print again
  bst->printContentsPreOrder();

  // insert more
  bst->insert( 66 );
  bst->insert( 19 );
  bst->insert( 78 );

  // print again
  bst->printContentsPreOrder();

  // test contains
  std::cout << "Contains 12? " << bst->contains( 12 ) << std::endl;
  std::cout << "Contains 42? " << bst->contains( 42 ) << std::endl;
  std::cout << "Contains 78? " << bst->contains( 78 ) << std::endl;
  std::cout << "Contains 102? " << bst->contains( 102 ) << std::endl;
  std::cout << "Contains 34? " << bst->contains( 34 ) << std::endl;

  // get the size
  std::cout << "Size: " << bst->size() << std::endl;

  // get height
  std::cout << "Height: " << bst->height() << std::endl;

  return 0;
}
