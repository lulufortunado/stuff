/*
 * BinarySearchTree.cpp
 *
 * COMP15
 * Spring 2018
 *
 * Implementation for BST class.
 * Inherits from BinaryTree class.
 *
 * Beyonce also wants you to be a SURVIVOR.
 *
 * You thought you'd be stressed but you're chillin'.
 */

#include <cstddef>
#include "BinarySearchTree.h"

// Member function definitions
BinarySearchTree::BinarySearchTree()
{

}

// Destructor requires no action, base class handles it
BinarySearchTree::~BinarySearchTree()
{

}

// Function to insert into a BST
// Throws exception if full
// Calls wrapper function for recursion
void BinarySearchTree::insert_item(TreeItem item)
{
    if (is_full())
        throw FullTree();
    else
        insert_bst(root, item);
}

// Wrapper function for insert
void insert_bst(BinaryNode *&tree, TreeItem item)
{
    if (tree == NULL)
    {
        tree = new BinaryNode; // this part is why pass by ref
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }
    else if (item < tree->info)
    {
        insert_bst(tree->left, item);
    }
    else if (item > tree->info)   
    {
        insert_bst(tree->right, item);
    }
}


