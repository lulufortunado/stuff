/*
 * test-more-files-driver.cpp
 *
 * Tests more input files with BT and BST
 * 
 * This file tests the Binary Search Tree first, runs the same tests on
 * the Binary Tree, then tests the assignment operator and copy constructor
 * for both trees
 * 
 * COMP15
 * Spring 2018
 *
 */

#include <iostream>
#include <string>
#include "BinarySearchTree.h"
using namespace std;

// Input and output files
const string TWO_SURVIVORS_FILE = "twosurvivors.txt";
const string FIVE_SURVIVORS_FILE = "fivesurvivors.txt";


// Test functions for the BST operations
void test_file1_insert(BinaryTree *);
void test_inorder(BinaryTree *);
void test_remove_item_not_there(BinaryTree *);
void test_remove_item(BinaryTree *);
void test_remove_item2(BinaryTree *);
void test_file2_insert(BinaryTree *);
void test_insert_duplicates(BinaryTree *);
void test_average_age(BinaryTree *);
void test_num_leaves(BinaryTree *);
void test_tree_height(BinaryTree *);
void test_copy_constructor_empty_treeBST(BinarySearchTree);
void test_copy_constructor_empty_treeBT(BinaryTree);
void test_assignment_empty_treeBST(BinarySearchTree);
void test_assignment_empty_treeBT(BinaryTree);
void test_unbalanced_tree_assignment_operator();
void test_unbalanced_tree_copy_constructor();
void test_full_tree_assignment_operator();
void test_full_tree_copy_constructor();

int main()
{
    cout << endl;
    cout << "***************************************" << endl;
    cout << "first testing as Binary Search Tree" << endl;
    cout << "***************************************" << endl;
    cout << endl;
    BinaryTree *BST = new BinarySearchTree;
    test_file1_insert(BST);
    test_inorder(BST);
    
    test_num_leaves(BST);
    cout << "if num leaves is 1 then SUCCESS"  << endl;
    
    test_tree_height(BST);
    cout << "if tree height is 1 then SUCCESS"  << endl;

    test_remove_item_not_there(BST);
    test_remove_item(BST);
    test_remove_item2(BST);
    test_remove_item2(BST);

    test_num_leaves(BST);
    cout << "if num leaves is 0 then SUCCESS"  << endl << endl;

    test_average_age(BST);
    cout << "if average is 0 then GREAT SUCCESS!!" << endl;

    test_file2_insert(BST);
    test_insert_duplicates(BST);
    test_average_age(BST);
    cout << "if average is 27.8 then GREAT SUCCESS!!" << endl << endl;
    
    test_num_leaves(BST);
    cout << "if num leaves is 3 then SUCCESS"  << endl;

    test_tree_height(BST);
    cout << "if tree height is 2 then SUCCESS"   << endl;


    cout << endl;
    cout << "***************************************" << endl;
    cout << "now doing it all again as Binary Tree" << endl;
    cout << "***************************************" << endl;
    cout << endl;
    BinaryTree *BT = new BinaryTree;
    test_file1_insert(BT);
    test_inorder(BT);
    
    test_num_leaves(BT);
    cout << "if num leaves is 1 then SUCCESS"  << endl;
    
    test_tree_height(BT);
    cout << "if tree height is 1 then SUCCESS"  << endl;
    
    test_remove_item_not_there(BT);
    test_remove_item(BT);
    test_remove_item2(BT);
    test_remove_item2(BT);
    test_remove_item2(BT);

    test_num_leaves(BT);
    cout << "if num leaves is 0 then SUCCESS"  << endl << endl;

    test_average_age(BT);
    cout << "if average is 0 then GREAT SUCCESS!!" << endl << endl;

    test_file2_insert(BT);
    test_insert_duplicates(BT);
    test_average_age(BT);
    cout << "if average is 27.8 then GREAT SUCCESS!!" << endl;
    
    test_num_leaves(BT);
    cout << "if num leaves is 3 then SUCCESS"  << endl;
    
    test_tree_height(BT);
    cout << "if tree height is 2 then SUCCESS"  << endl;

    cout << endl;
    cout << "***********************************************" << endl;
    cout << "assignment operator and copy constructor tests" << endl;
    cout << "***********************************************" << endl;
    cout << endl;

    BinarySearchTree EmptyBST;
    test_copy_constructor_empty_treeBST(EmptyBST);
    test_assignment_empty_treeBST(EmptyBST);

    BinaryTree EmptyBT;
    test_copy_constructor_empty_treeBT(EmptyBT);
    test_assignment_empty_treeBT(EmptyBT);

    test_unbalanced_tree_assignment_operator();
    test_unbalanced_tree_copy_constructor();

    test_full_tree_assignment_operator();
    test_full_tree_copy_constructor();

    delete BST;
    delete BT;

    return 0;
}

// test_file1_insert
// tests the insertion of the items from twosurvivors.txt
void test_file1_insert(BinaryTree *BT)
{
    cout << "***** TEST test_file1_insert (TWO_SURVIVORS_FILE) *****\n";
    string firstword;
    ifstream fileIn;
    fileIn.open(TWO_SURVIVORS_FILE.c_str());
    if (!fileIn.is_open())
    {
        cerr << "Could not add castaways from file\n";
        return;
    }

    while (!fileIn.eof())
    {           
        Survivor s;
        s.generate_next_castaway(fileIn);
        if (s.get_name() != "-1 nolastname")
        {
            BT->insert_item(s); 
        }   
    }

    fileIn.close();

    BT->inorder(cout);
    cout << "length of list: " << BT->get_length() << endl;
    cout << "If list is Sonja Christopher and BB Andersen then SUCCESS!\n\n";
}

// Print an inorder traversal
void test_inorder(BinaryTree *BT)
{
    cout << endl;
    cout << "***** Begin inorder test.*****  \n";
    BT->inorder(cout);
    cout << "BST case: if names listed alphabetically then SUCCESS\n";
    cout << "Expected BB Andersen then Sonja Christopher\n";
    cout << "Did that look right? If so then SUCCESS!\n\n";
}

// test_remove_item_not_there
// tests the removal of an item that is not there
void test_remove_item_not_there(BinaryTree *BT)
{
    cout << endl;
    cout << "***** TEST test_remove_item_not_there **********" << endl;

    Survivor s;
    s.set_name("Carl", "Bilancione");

    try
    {
        BT->remove_item(s);
    }
    catch (EmptyTree et)
    {
        cerr << "throwing empty tree error" << endl;
    }

    cout << "full list after removing Carl Bilancione"  << endl;
    BT->inorder(cout);
    cout << "length of BT after removing Carl Bilancione: ";
    cout << BT->get_length() << endl;
    cout << "If no change to list and length is 2 then SUCCESS!\n\n";
}

// test_remove_item
// tests removal of an item and then list must be eyeballed to see if correct
void test_remove_item(BinaryTree *BT)
{
    cout << endl;
    cout << "***** TEST test_remove_item **********" << endl;
    Survivor s;
    s.set_name("Sonja", "Christopher");

    try
    {
        BT->remove_item(s);
    }
    catch (EmptyTree et)
    {
        cerr << "throwing empty tree error" << endl;
    }

    cout << "full list after removing Sonja Christopher"  << endl;
    BT->inorder(cout);
    cout << "length of BT after removing Sonja Christopher: ";
    cout << BT->get_length() << endl;
    cout << "If list is only BB Andersen with length 1 then SUCCESS!\n\n";
}

// test_remove_item2
// tests removal of an item and then list must be eyeballed to see if correct
void test_remove_item2(BinaryTree *BT)
{
    cout << endl;
    cout << "***** TEST test_remove_item2 **********" << endl;
    Survivor s;
    s.set_name("BB", "Andersen");
    
    try
    {
        BT->remove_item(s);
    }
    catch (EmptyTree et)
    {
        cerr << "throwing empty tree error" << endl;
    }

    cout << "full list after removing BB Andersen:"  << endl;
    BT->inorder(cout);
    cout << "length of BT after removing BB Andersen: ";
    cout << BT->get_length() << endl;
    cout << "If list is empty with length 0 then SUCCESS!\n\n";
}
// test_file2_insert
// tests the insertion of the items from fivesurvivors.txt
// list must be eyeballed to see if correct
void test_file2_insert(BinaryTree *BT)
{
    cout << "***** TEST test_file2_insert (FIVE_SURVIVORS_FILE) *****\n";
    cout << "BST case: if names listed alphabetically and length 5 then";
    cout << " SUCCESS\n";
    cout << "BT case: if names not listed alphabetically and length 5 then";
    cout << " SUCCESS\n";
    ifstream fileIn;
    fileIn.open(FIVE_SURVIVORS_FILE.c_str());
    if (!fileIn.is_open())
    {
        cerr << "Could not add castaways from file\n";
        return;
    }

    while (!fileIn.eof())
    {           
        Survivor s;
        s.generate_next_castaway(fileIn);
        if (s.get_name() != "-1 nolastname")
        {
            BT->insert_item(s); 
        }     
    }

    fileIn.close();

    BT->inorder(cout);
    cout << "length of list: " << BT->get_length() << endl;
}

// test_insert_duplicates
// tests the insertion of dupplicates 
// then list must be eyeballed to see if correct
void test_insert_duplicates(BinaryTree *BT)
{
    cout << endl;
    cout << "***** TEST test_insert_duplicates **********" << endl;
    cout << endl << "before inserts:" << endl << endl;
    BT->inorder(cout);
    cout << "length of list: " << BT->get_length() << endl;
    Survivor s1("Erin", "Lobdell");
    BT->insert_item(s1); 
    Survivor s2("Erin", "Lobdell");
    BT->insert_item(s2); 
    cout << endl << "after inserts" << endl << endl;
    BT->inorder(cout);
    cout << "length of list: " << BT->get_length() << endl;
    cout << "if before and after lists look the same and no duplicates then \
                                                            SUCCESS" << endl;

}
//test_average_age
void test_average_age(BinaryTree *BT)
{
    cout << endl;
    cout << "***** TEST test_average_age **********" << endl;
    cout << "average age: " << BT->average_age();
    cout << endl;
}
//test_atree_height
void test_tree_height(BinaryTree *BT)
{
    cout << endl;
    cout << "***** TEST test_tree_height **********" << endl;
    cout << "tree height: " << BT->get_height() << endl;
}
//test_num_leaves
void test_num_leaves(BinaryTree *BT)
{
    cout << endl;
    cout << "***** TEST test_num_leaves **********" << endl;
    cout << "num leaves: " << BT->get_number_of_leaves() << endl;
}
// test_copy_constructor_empty_tree for binary search tree
// accepts an empty binary search tree and tests the copy constructor with it
void test_copy_constructor_empty_treeBST(BinarySearchTree EmptyBST)
{
    cout << endl;
    //invoke copy constructor
    BinarySearchTree BSTTest = EmptyBST;
    if (BSTTest.is_empty())
        cout << "empty binary search tree constructor test SUCCESS\n";
    else
        cout << "empty binary search tree constructor test FAIL\n";
}

// test_copy_constructor_empty_tree for binary tree
// accepts an empty binary tree and tests the copy constructor with it
void test_copy_constructor_empty_treeBT(BinaryTree EmptyBT)
{
    cout << endl;
    //invoke copy constructor
    BinaryTree BTTest = EmptyBT;
    if (BTTest.is_empty())
        cout << "empty binary tree constructor test SUCCESS\n";
    else
        cout << "empty binary tree constructor test FAIL\n";
}

//test_assignment_empty_treeBST
// accepts an empty binary search tree and tests the assignment operator with it
void test_assignment_empty_treeBST(BinarySearchTree EmptyBST)
{
    cout << endl;
    //invoke assignment operator
    BinarySearchTree BSTTest;
    BSTTest = EmptyBST;
     if (BSTTest.is_empty())
        cout << "empty binary search tree constructor test SUCCESS\n";
    else
        cout << "empty binary search tree constructor test FAIL\n";
}

//test_assignment_empty_treeBT
// accepts an empty binary tree and tests the assignment operator with it
void test_assignment_empty_treeBT(BinaryTree EmptyBT)
{
    cout << endl;
    //invoke assignment operator
    BinaryTree BTTest;
    BTTest = EmptyBT;
     if (BTTest.is_empty())
        cout << "empty binary tree constructor test SUCCESS\n";
    else
        cout << "empty binary tree constructor test FAIL\n";
}

// function test_unbalanced_tree_assignment_operator
// creates an unbalanced tree by inserting items alphabetically into a 
// binary search tree and then invokes assignment eoperator and compares the
// original and copied trees
void test_unbalanced_tree_assignment_operator()
{
    cout << endl;
    cout << "***** test_unbalanced_tree_assignment_operator **********" << endl;

    int num_items = 9;
    BinarySearchTree bt;
    Survivor *vives = new Survivor[num_items];
    for (int i = 0; i < num_items; i++)
    {
        string lname = "Hatch";
        lname += to_string(i+1);
        vives[i].set_name("Richard", lname);
        bt.insert_item(vives[i]);
    }

    //invoke assignment operator
    BinarySearchTree BTTest;
    BTTest = bt;

    cout << endl << "print out of original tree:\n\n";
    bt.inorder(cout);
    cout << endl <<  "print out of copied tree:\n\n";
    BTTest.inorder(cout);
    cout << "if the two trees look identical then SUCCESS\n";

    delete []vives;
}
// function test_unbalanced_tree_copy_constructor
// creates an unbalanced tree by inserting items alphabetically into a 
// binary search tree and then makes a copy compares the copied and original
// trees 
void test_unbalanced_tree_copy_constructor()
{
    cout << endl;
    cout << "***** test_unbalanced_tree_copy_constructor **********" << endl;

    int num_items = 9;
    BinarySearchTree bt;
    Survivor *vives = new Survivor[num_items];
    for (int i = 0; i < num_items; i++)
    {
        string lname = "Hatch";
        lname += to_string(i+1);
        vives[i].set_name("Richard", lname);
        bt.insert_item(vives[i]);
    }

    //invoke copy constructor
    BinarySearchTree BTTest = bt;

    cout << endl << "print out of original tree:\n\n";
    bt.inorder(cout);
    cout << endl <<  "print out of copied tree:\n\n";
    BTTest.inorder(cout);
    cout << "if the two trees look identical then SUCCESS\n";

    delete []vives;
}

// function test_full_tree_assignment_operator
// creates a full tree by insertign exactly 7 items into a binary tree 
// then invokes assignment eoperator and compares the original and copied trees
void test_full_tree_assignment_operator()
{
    cout << endl;
    cout << "***** test_full_tree_assignment_operator **********" << endl;

    int num_items = 7;
    BinaryTree bt;
    Survivor *vives = new Survivor[num_items];
    for (int i = 0; i < num_items; i++)
    {
        string lname = "Hatch";
        lname += to_string(i+1);
        vives[i].set_name("Richard", lname);
        bt.insert_item(vives[i]);
    }

    //invoke assignment operator
    BinaryTree BTTest;
    BTTest = bt;

    cout << endl << "print out of original tree:\n\n";
    bt.inorder(cout);
    cout << endl <<  "print out of copied tree:\n\n";
    BTTest.inorder(cout);
    cout << "if the two trees look identical then SUCCESS\n";

    delete []vives;
}

// function test_full_tree_copy_constructor
// creates a full tree by insertign exactly 7 items into a binary tree 
// then invokes copy constructor and compares the original and copied trees
void test_full_tree_copy_constructor()
{
    cout << endl;
    cout << "***** test_full_tree_copy_constructor **********" << endl;

    int num_items = 7;
    BinaryTree bt;
    Survivor *vives = new Survivor[num_items];
    for (int i = 0; i < num_items; i++)
    {
        string lname = "Hatch";
        lname += to_string(i+1);
        vives[i].set_name("Richard", lname);
        bt.insert_item(vives[i]);
    }

    //invoke copy constructor
    BinaryTree BTTest = bt;

    cout << endl << "print out of original tree:\n\n";
    bt.inorder(cout);
    cout << endl <<  "print out of copied tree:\n\n";
    BTTest.inorder(cout);
    cout << "if the two trees look identical then SUCCESS\n";

    delete []vives;
}

