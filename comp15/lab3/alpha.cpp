/*
 * COMP15
 * Spring 2018
 * Lab 3
 *
 * Driver: Populate a BT and a BST from the given file
 * Goal: print both in alpha order
 *
 * 
 */

#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
using namespace std;

const string INPUT_FILE = "ww.txt";

void populate_tree_from_file(BinaryTree *);

int main()
{    
    BinaryTree * BT;
    BinaryTree * BST;
    BT = new BinaryTree();
    populate_tree_from_file(BT);
    cout << endl << "BT traversal: " << endl;
    BT->preorder(cout);
    cout << endl;
    BST = new BinarySearchTree();
    populate_tree_from_file(BST);
    cout << endl << "BST traversal: " << endl;
    BST->inorder(cout);
    cout << endl;

    return 0;
}

// Function populate_tree_from_file
// Input: Pointer to Binary Tree object
// Returns: None
// Does: Inserts the elements from INPUT_FILE
//       into the given tree
void populate_tree_from_file(BinaryTree *tree)
{
    ifstream infile;
    infile.open(INPUT_FILE.c_str());

    if (!infile.is_open())
    {
        cerr << "Could not open file for reading\n";
        return;
    }
    string s;
    while (!infile.eof())
    {
        infile >> s;
        if (s != "-1")
        {
            try
            {
                tree->insert_item(s);
            }
            catch (FullTree exception)
            {
                cerr << exception.what();
                return;
            }
        }
    }
    infile.close();
}
