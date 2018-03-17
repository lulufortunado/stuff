/*
 * BinarySearchTree.h
 *
 * COMP15
 * Spring 2018
 * Derived class for a BST
 *
 */

#include "BinaryTree.h"

#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

// Prototypes for recursive wrapper functions
void get_successor(BinaryNode *, BinaryNode *&);
void copy_tree(BinaryNode *&, BinaryNode *&);
void find_bst(BinaryNode *, TreeItem, BinaryNode *&, bool &);

class BinarySearchTree : public BinaryTree
{

public:
    // BT has a constructor
    // both get called
    BinarySearchTree();

    // BT has a virtual destructor
    // so we write our own for BST
    // Both get called when BST goes out of scope
    ~BinarySearchTree();

    // Rule of 3
    // Copy constructor and assignment operator
    // WILL go here, when you do them for Proj1
    // not needed for the lab

    // overwritten from BinaryTree
    void insert_item(TreeItem);
    void remove_item(TreeItem);
};

#endif
