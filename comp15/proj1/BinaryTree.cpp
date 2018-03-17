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
#include <algorithm>
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


// Copy constructor
// passes root of tree to copy the passed bst to, to copy_tree_wrapper. 
// copy_tree_wrapper then calls the recursive copy_tree function.
// passes root because root is protected
BinaryTree::BinaryTree(const BinaryTree &bt)
{   
    bt.copy_tree_wrapper(root);
}

// Assignment operator
// passes root of tree to assign the passed bst to, to assign_tree_wrapper. 
// assign_tree_wrapper then empties the destination tree and calls the recursive
// copy_tree function
// passes root because root is protected
BinaryTree & BinaryTree::operator = (const BinaryTree &bt)
{
    bt.assign_tree_wrapper(root);
    
    return *this;
}

// Function copy_tree_wrapper
// Inputs: BinaryNode * by reference
// Returns: nothing
// Does: passes root of tree to be copied, and 
// dest_tree, which is root of tree to be copied to, to 
// the recursive copy_tree function
void BinaryTree::copy_tree_wrapper(BinaryNode *&dest_tree) const
{
   try
    {
        copy_tree(dest_tree, root);
    }
    catch (FullTree ft)
    {
        cerr << "Full tree when calling copy_tree" << endl;
    }
}

// Function assign_tree_wrapper
// Inputs: BinaryNode * by reference
// Returns: nothing
// Does: 
// Does: makes the passed tree equivalent to this tree. First it
// checks if the destination tree (dest_tree) is empty, and if
// not, destroys it and calls copy_tree to make an exact copy 
void BinaryTree::assign_tree_wrapper(BinaryNode *&dest_tree) const
{
    if (dest_tree != NULL)
    {
        destroy(dest_tree);
    }
    try
    {
        copy_tree(dest_tree, root);
    }
    catch (FullTree ft)
    {
        cerr << "Full tree when calling copy_tree" << endl;
    }
}


// Function copy_tree
// Inputs: BinaryNode * by reference, const BinaryNode *
// Returns: nothing
// Does: copies source_tree to dest_tree
void copy_tree(BinaryNode *&dest_tree, const BinaryNode *source_tree)
{
    if (source_tree == NULL)
    {
        dest_tree = NULL;
        return;
    }   
    try
    {
        dest_tree = new BinaryNode;
        dest_tree->left = NULL;
        dest_tree->right = NULL;
        dest_tree->info = source_tree->info;  

        copy_tree(dest_tree->left, source_tree->left);
        copy_tree(dest_tree->right, source_tree->right);
    }
    catch (bad_alloc exception)
    {
        cerr << "Full tree when attempting tree copy" << endl;
    }
 
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
    {
        bool found = false;
        find_bt(root, item, found);

        if (!found)
        {
            insert_bt(root, item);
        }       
    }
}

// Function find_item
// finds the given item using queue as auxiliary structure
void BinaryTree::find_item(TreeItem &item, bool &found) const
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
        {
            if (get_length() == 1)
            {
                destroy(root);
                root = NULL;
            }
            else
            {
                remove_bt(root, item);
            }
        }
    }
}

// Return the item at the deepest left node
// (Would come first in an in-order traversal)
// Throws exception if tree is empty
TreeItem BinaryTree::get_leftmost() const
{
    return return_leftmost(root);
}

// Return the item at the deepest right node
// (Would come last in an in-order traversal)
// Throws exception if tree is empty
TreeItem BinaryTree::get_rightmost() const
{
    return return_rightmost(root);
}

// Function get_number_of_leaves
// Inputs: none
// Returns: int
// Does: returns number of leaves
// in the tree by passing root to
// the recursive count_leaves function
int BinaryTree::get_number_of_leaves() const
{
    return count_leaves(root);
}

// Function get_height
// Inputs: none
// Returns: int
// Does: returns height of tree
// in the tree by passing root to
// the recursive calculate_height function
int BinaryTree::get_height() const
{
    return calculate_height(root);
}

// Function average_age
// Inputs: none
// Returns: double
// Does: returns the average age
// of the castaways in the tree by
// passing root to the recursive
// calculate_average_age function
// we also pass a 0 to initialize the
// recursice call counter in 
// calculate_average_age
double BinaryTree::average_age()
{
    double age = 0;
    return calculate_average_age(root, age, get_length());
}

// Function is_full
// Inputs: none
// Returns: bool
// Does: returns true if tree is
// full, false if not
bool BinaryTree::is_full() const
{
    try
    {
        BinaryTree *node = new BinaryTree;
        delete node;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}

// Function is_empty
// Inputs: none
// Returns: bool
// Does: returns true if tree is
// empty
bool BinaryTree::is_empty() const
{
    if (root == NULL) 
    {
        return true;
    }

    return false;
}

// Function print_the_tree
// Inputs: ostream by reference
// Returns: nothing
// Does: Prints the root node 
// (by calling the Survivor class’s print 
// function), the height of the tree, 
// the number of nodes in the tree, and 
// the number of leaves in the tree
void BinaryTree::print_the_tree(ostream &out) const
{
    if (root == NULL) 
        return;
    root->info.print(out);
    out << endl;
    out << "Height: " << get_height() << endl;
    out << "Number of nodes: " << get_length() << endl;
    out << "Number of leaves: " << get_number_of_leaves() << endl;
}

// Function print_root
// Inputs: ostream by reference
// Returns: nothing
// Does: Prints the root node 
// (by calling the Survivor class’s print 
// function)
void BinaryTree::print_root(ostream &out) const
{
    if (root == NULL) 
        return;
    root->info.print(out);
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

//counts leaves
int count_leaves(BinaryNode *tree)
{
    if (tree == NULL)
        return 0;
    if (tree->left == NULL && tree->right == NULL)
        return 1;
    return count_leaves(tree->left) + count_leaves(tree->right);
}

//recursively calculates height of tree
int calculate_height(BinaryNode *tree)
{
    if (tree == NULL)
        return -1;
    return max(calculate_height(tree->left), calculate_height(tree->right)) + 1;
}

//recursively callculates average age of castaways in tree
double calculate_average_age(BinaryNode *tree, double &age, int length)
{        
    if (tree == NULL)
    {
        return 0;
    }
    age += tree->info.get_age();
    calculate_average_age(tree->left, age, length);
    calculate_average_age(tree->right, age, length);    
    return age/length;
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
//       we return the found BinaryNode pointer to foundtree
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
            tree = node;
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
// Throws exception if tree is empty, it has no leftmost node
TreeItem return_leftmost(BinaryNode *tree)
{
    if (tree == NULL)
        throw EmptyTree();
    else if (tree->left == NULL)
        return tree->info;
    else
       return return_leftmost(tree->left);
}

// Function return_rightmost(wrapper)
// Params: BinaryNode *, the tree
// Returns: TreeItem, the info in the deepest right node
// Throws exception if tree is empty, it has no rightmost node
TreeItem return_rightmost(BinaryNode *tree)
{
    if (tree == NULL)
        throw EmptyTree();
    else if (tree->right == NULL)
        return tree->info;
    else
       return return_rightmost(tree->right);
}
