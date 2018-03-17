/*
 * BinaryTree.cpp
 *
 * Implementation for base class BinaryTree
 * Starter code for Project 1
 * 
 * COMP15
 * Spring 2018
 *
 * What did the Binary Tree traversal get a dinner?
 *
 * The pre-fix menu!
 */

#include <cstddef>
#include "Queue.h"
#include "BinaryTree.h"

// Constructor
BinaryTree::BinaryTree()
{
    root = NULL;
}

// Destructor
BinaryTree::~BinaryTree()
{
    destroy(root);
}

// Function get_length (const)
// Counts the total number of nodes in the tree
int BinaryTree::get_length() const
{
    return count_nodes(root);
}

// Inorder traversal
void BinaryTree::inorder(ostream &out) const
{
    print_inorder(root, out);
}

// preorder traversal
void BinaryTree::preorder(ostream &out) const
{
    print_preorder(root, out);
}

// postorder traversal
void BinaryTree::postorder(ostream &out) const
{
    print_postorder(root, out);
}

// Function insert_item
// Checks for fullness, throws exception if necessary
// insert item into next open slot
void BinaryTree::insert_item(TreeItem item)
{
    if (is_full())
        throw FullTree();
    else
        insert_bt(root, item);
}

// Function find_item
// finds the given item using queue as auxiliary structure
void BinaryTree::find_item(TreeItem &item, bool & found) const
{
    find_bt(root, item, found);
}

// Function remove_item
// Checks for empty tree, throws exception if necssary
// remove item, if found
void BinaryTree::remove_item(TreeItem item)
{
    if (is_empty())
        throw EmptyTree();
    else
    {    
        bool found = false;
        find_item(item, found);
        if (found)
            remove_bt(root, item);
    }
}

// Return the item at the deepest left node
// (Would come first in an in-order traversal)
// Throws exception if tree is empty
TreeItem BinaryTree::get_leftmost() const
{
    return return_leftmost(root);
}

/* Definitions for Recursive Wrapper Functions */

// Function destroy (wrapper)
// Used by destructor and = operator
// Follows postfix order, deletes nodes one by one
void destroy(BinaryNode *&tree)
{
    if (tree != NULL)
    {
        destroy(tree->left);
        destroy(tree->right);
        delete tree;
    }
}

// Recursively counts the total number of nodes in the tree
int count_nodes(BinaryNode *tree)
{
    if (tree == NULL)
        return 0;
    else
        return count_nodes(tree->left) + count_nodes(tree->right) + 1;
}

// Print in  order
void print_inorder(BinaryNode *tree, ostream &out)
{
    if (tree != NULL)
    {
        print_inorder(tree->left, out);
        tree->info.print(out);
        print_inorder(tree->right, out);
    }
} 

// Print in prefix order
void print_preorder(BinaryNode *tree, ostream &out)
{
    if (tree != NULL)
    {
        tree->info.print(out);
        print_preorder(tree->left, out);
        print_preorder(tree->right, out);
    }
} 

// Print in postfix order
void print_postorder(BinaryNode *tree, ostream &out)
{
    if (tree != NULL)
    {
        print_postorder(tree->left, out);
        print_postorder(tree->right, out);
        tree->info.print(out);
    }
}

// Function insert_bt (wrapper)
// Params: BinaryNode reference, TreeItem
// Returns: void
// Does: Finds next open spot using a queue
//       allocates a new BinaryNode and sets
//       its info to the given tree
void insert_bt(BinaryNode *&tree, TreeItem item)
{
    // enqueue and dequeue until empty
    BinaryNode *temp = NULL;
    BinaryNode *node = new BinaryNode;
    node->info = item;
    node->left = NULL;
    node->right = NULL;
    if (tree == NULL)
    {
        tree = node;
        return;
    }
    
    Queue q;
    q.enqueue(tree);
    while (!q.is_empty())
    {
        q.dequeue(temp);
        if (temp->left != NULL)
        {
            q.enqueue(temp->left);
        }
        else
        {
            temp->left = node;
            return;
        }
        if (temp->right != NULL)
        {
            q.enqueue(temp->right);
        }
        else
        {
            temp->right = node;
            return;
        }
    }
}

// Function find_bt (not a member function)
// Parameters: BinaryNode (root), TreeItem reference, bool reference
// Returns: void
// Does: Uses an auxiliary queue to iterate through each node
//       until the item is found. Updates the item reference with
//       the one actually found, and bool reference with true/false. 
void find_bt(BinaryNode *tree, TreeItem &item, bool &found)
{ 
    found = false;
    if (tree == NULL)
    {
        return;
    }

    Queue q;
    q.enqueue(tree);

    while (!q.is_empty())
    {
        BinaryNode *node; 
        q.dequeue(node);
        if (node->info == item)
        {
            item = node->info;
            found = true;
            return;
        }
        if (node->left != NULL)
            q.enqueue(node->left);
        if (node->right != NULL)
            q.enqueue(node->right);
    }
}

// Function remove_bt (wrapper)
// Parameters: BinaryNode reference (root), TreeItem to remove
// Returns: void
// Does: Uses an auxiliary queue to find the deepest item
//       swaps one to delete with deepest item
//       deletes deepest item
void remove_bt(BinaryNode *&tree, TreeItem item) 
{
    if (tree == NULL)
    {
        return;
    }

    Queue q;
    q.enqueue(tree);

    BinaryNode *deep = NULL, *keynode = NULL;

    while (!q.is_empty())
    {
        q.dequeue(deep);
        if (deep->info == item)
            keynode = deep;
        if (deep->left != NULL)
            q.enqueue(deep->left);
        if (deep->right != NULL)
            q.enqueue(deep->right);
    }

    TreeItem val = deep->info;
    delete_deepest(tree, deep);
    if (deep != keynode)
        keynode->info = val;
}

// Delete deepest node in the tree
// Helper function for remove
void delete_deepest(BinaryNode *&tree, BinaryNode *&deepnode)
{
    Queue q;
    q.enqueue(tree);

    BinaryNode *temp;
    while (!q.is_empty())
    {
        q.dequeue(temp);
        if (temp->right != NULL)
        {
            if (temp->right->info == deepnode->info)
            {
                temp->right = NULL;
                delete deepnode;
                return;
            }
            else
                q.enqueue(temp->right);
        }
        if (temp->left != NULL)
        {
                if (temp->left->info == deepnode->info)
                {
                    temp->left = NULL;
                    delete deepnode;
                    return;
                }
                else
                    q.enqueue(temp->left);
        }
    }
}

// Function return_leftmost(wrapper)
// Params: BinaryNode *, the tree
// Returns: TreeItem, the info in the deepest left node
// Throws exception if tree is empty, it has no leftmost ndoe
TreeItem return_leftmost(BinaryNode *tree)
{
    if (tree == NULL)
        throw EmptyTree();
    else if (tree->left == NULL)
        return tree->info;
    else
       return return_leftmost(tree->left);
}
