/* 
 * BinarySearchTree.h
 *
 * Interface for derived class BST
 * Inherits from Binary Tree
 *
 * Gloria Gaynor wants you to 
 * SURVIVE this project. 
 *
 * Don't be afraid.
 * 
 * Don't be petrified.
 * 
 * Come back from outer space.
 */

#include "BinaryTree.h"

#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

// Prototypes for recursive wrapper functions
void insert_bst(BinaryNode *&, TreeItem);

class BinarySearchTree : public BinaryTree
{

public:
    BinarySearchTree();
    // BT has a virtual destructor
    // so we write our own for BST
    ~BinarySearchTree();

    // overridden from BinaryTree
    void insert_item(TreeItem);
};

#endif
