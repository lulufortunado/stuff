/*
 * BinaryTree.h
 *
 * Interface for base class Binary Tree
 *
 * COMP15
 * Spring 2018
 *
 * Why don't you make like a tree...
 * and get outta here.
 */

#include <iostream>
#include "Queue.h"
using namespace std;

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

class FullTree : public exception
{
public:
    const char *what () const throw() { return "Full Tree!\n"; }
};

class EmptyTree : public exception
{
public:
    const char * what() const throw() { return "Empty Tree!\n"; }
};

//error thrown in survivor-driver.cpp if counting leaves 
//in trees after inserting from files does not give expecting 
// integer
class NumLeavesError : public exception
{
public:
    const char * what() const throw() 
    { 
        return "Error countng leaves!\n"; 
    }
};

// Prototypes for recursive wrapper functions
void destroy(BinaryNode *&);
int count_nodes(BinaryNode *);
int count_leaves(BinaryNode *);
int calculate_height(BinaryNode *);
double calculate_average_age(BinaryNode *, double &, int );
TreeItem return_leftmost(BinaryNode *);
TreeItem return_rightmost(BinaryNode *);
void print_inorder(BinaryNode *, ostream &);
void print_preorder(BinaryNode *, ostream &);
void print_postorder(BinaryNode *, ostream &);
void insert_bt(BinaryNode *&, TreeItem);
void find_bt(BinaryNode *, TreeItem &, bool &);
void remove_bt(BinaryNode *&, TreeItem);
void delete_deepest(BinaryNode *&, BinaryNode *&);
void copy_tree(BinaryNode *&, const BinaryNode *);


class BinaryTree
{
public:
    BinaryTree();
    
    // virtual destructor to ensure
    // derived class version runs first
    virtual ~BinaryTree();

    //Copy constructor1
    BinaryTree(const BinaryTree &bt);

    // Assignment Operator
    BinaryTree & operator = (const BinaryTree &bt);

    // implemented in base class, and
    // inherited by all derived classes
    int get_length() const;
    int get_height() const;
    int get_number_of_leaves() const;
    TreeItem get_leftmost() const;
    TreeItem get_rightmost() const;
    void inorder(ostream &) const;
    void preorder(ostream &) const;
    void postorder(ostream &) const;
    bool is_full() const;
    bool is_empty() const;
    double average_age();
    void print_the_tree(ostream &) const;
    void print_root(ostream &) const;
    void copy_tree_wrapper(BinaryNode *&) const;
    void assign_tree_wrapper(BinaryNode *&) const;

    // virtual function is defined in base class,
    // overridden in derived class
    virtual void insert_item(TreeItem);
    virtual void find_item(TreeItem &, bool &) const; 
    virtual void remove_item(TreeItem);

protected:
    BinaryNode *root;
};

#endif
