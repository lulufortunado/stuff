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

// Copy constructor
// passes root of tree to copy the passed bst to, to copy_tree_wrapper (defined 
// in the base BinaryTree class). copy_tree_wrapper then calls the recursive
// copy_tree function in the BinaryTree class
// passes root because root is protected
BinarySearchTree::BinarySearchTree(const BinarySearchTree &bst)
{   
    bst.copy_tree_wrapper(root);
}

// Assignment operator
// passes root of tree to assign the passed bst to, to assign_tree_wrapper 
// (defined in the base BinaryTree class). assign_tree_wrapper then empties 
// the destination tree and calls the recursive copy_tree function
// in the BinaryTree class
// passes root because root is protected
BinarySearchTree & BinarySearchTree::operator = (const BinarySearchTree &bst)
{
    bst.assign_tree_wrapper(root);
    return *this;
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

// Function find_item
// finds the given item using queue as auxiliary structure
// found tree is saved to passed param foundtree
void BinarySearchTree::find_item(TreeItem &item, bool &found) const 
{
    find_bst(root, item, found);
}


// Function remove_item
// Params: TreeItem
// Returns: void
// Does: Looks for item passed as parameter and
// makes first call to recursive function remove_bst if found.
void BinarySearchTree::remove_item(TreeItem item)
{
    if (is_empty())
    {
        throw EmptyTree();
    }
    else
    {    
        bool found = false;

        find_item(item, found);

        if (found)
        {           
            remove_bst(root, item);
        }
    }
}


/* Definitions for Recursive Wrapper Functions */

// Function remove_bst
// Params: BinaryNode pointer by reference, TreeItem
// Returns: void
// Does: removes item passed in
// calls itself recursively to find
// passed item. 
// and handles these 3 cases (in order of the if/else calls for these cases):
// case 1: found item is a leaf
// case 2: found item has two children
// case 3: found item has one child
// in case 2 we have to call get_successor
// recursively to find the replacement for our deleted node (the node with the 
// smallest value in the right subtree). We set the info of the node we want to 
// remove with the info of the successor, then remove successor. In case 2 we
// also handle the special case of the successor being right child of item
void remove_bst(BinaryNode *&tree, TreeItem item) 
{    
    if (tree == NULL)
    {
        return;
    }
    else if (tree->info == item)
    {   
        if(tree->left == NULL && tree->right == NULL)
        {
            BinaryNode *temp = tree;
            tree = NULL;
            delete temp;
        }
        else if (tree->left != NULL && tree->right != NULL)
        {
            
            TreeItem leftmostItem  = return_leftmost(tree->right);
            tree->info = leftmostItem;
            remove_bst(tree->right, leftmostItem);

            // BinaryNode *successortree = nullptr;
            // BinaryNode *successor_tree_parent = nullptr;  

            // get_successor(tree->right, successortree, 
            //                             successor_tree_parent, item);

            // tree->info = item;

            // if (tree->right->info == item)
            // {           
            //     tree->right = successortree->right;
            //     delete successortree;
            // }
            // else
            // {
            //     if(successortree->right!= NULL)
            //     {                  
            //         successor_tree_parent->left = successortree->right;
            //     }
            //     else 
            //     {
            //         successor_tree_parent->left = NULL;
            //     }

            //     delete successortree;
            // }

        }
        else
        {      
            if (tree->left == NULL)
            {
                BinaryNode *temp = tree;
                tree = tree->right;
                delete temp;
            }
            else if (tree->right == NULL)
            {
                BinaryNode *temp = tree;
                tree = tree->left;
                delete temp;
            }
               
        }

        return;
    }
    else if (tree->info < item)
    {
        remove_bst(tree->right, item);
    }
    else 
    {
        remove_bst(tree->left, item);
    }

}

// Wrapper function for insert
void insert_bst(BinaryNode *&tree, TreeItem item)
{
    if (tree == NULL)
    {
        tree = new BinaryNode; 
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


// Wrapper function for finding item 
// Recursively looks for item passed as parameter
// if found sets passed bool found to true and sets
// foundtree to tree with found item as root
void find_bst(BinaryNode *tree, TreeItem &item, bool &found)
{
    if (tree == NULL)
    {
        found = false;
        return;
    }
    else if (tree->info == item)
    {
      found = true;
      item = tree->info;
      return;
    }
    else if (tree->info < item)
    {
        find_bst(tree->right, item, found);
    }
    else 
    {
        find_bst(tree->left, item, found);
    }
}

// Wrapper function for finding successor to replace
// node with two children that is being deleted
// this finds the node with the smallest value in the given
// tree and sets the successor_tree parameter to the found tree (has
// the successor as its root), successor_tree_parent to the parent of the
// found tree, and item to the found successor item
// it is assumed here that when this is called, tree->right of
// the original tree is passed as the tree parameter here
// void get_successor(BinaryNode *tree, BinaryNode *&successor_tree, 
//                             BinaryNode *&successor_tree_parent, TreeItem &item)
// {   
//     if (tree == NULL)
//     {
//         return;
//     }
//     else if (tree->left == NULL)
//     {
//         item = tree->info;
//         successor_tree = tree;
//         return;
//     }
//     else
//     {
//        successor_tree_parent = tree;
//        return get_successor(tree->left, successor_tree, 
//                                             successor_tree_parent, item);
//     }
// }
