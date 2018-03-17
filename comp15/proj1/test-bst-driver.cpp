/*
 * test-bst-driver.cpp
 *
 * Tests BASIC functionality of the BinarySearchtree class
 * Just the stuff from starter code.
 * 
 * Write your own tests.
 *
 * Have you written some tests?
 * 
 * Now write some more tests.
 * 
 * That's not enough tests.
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
const string STOWAWAYS_FILE = "stowaways.txt";
const string CASTAWAYS_FILE = "castaways.txt";


// Test functions for the BST operations
void test_get_length(BinaryTree *, int);
void test_insert(BinaryTree *, int);
void test_preorder(BinaryTree *);
void test_inorder(BinaryTree *);
void test_postorder(BinaryTree *);
void test_get_left(BinaryTree *);
void test_ct_file_insert(BinaryTree *);
void test_print_root(BinaryTree *);
void test_remove_root(BinaryTree *);
void test_remove_with_one_child(BinaryTree *);
void test_remove_with_no_children(BinaryTree *);
void test_remove_with_two_children(BinaryTree *);
void test_remove_with_two_children2(BinaryTree *);
void test_remove_all(BinaryTree *, int);
void test_find(BinaryTree *);
void test_remove_leaf(BinaryTree *);
void test_average_age(BinaryTree *);
void test_num_leaves(BinaryTree *);
void test_tree_height(BinaryTree *);
void test_remove_two_more(BinaryTree *);
void test_insert_new_survivor(BinaryTree *);
void test_copy_constructor();
void test_assignment_operator();


int main()
{
    BinaryTree *BST = new BinarySearchTree;
    test_get_length(BST, 0);
    test_insert(BST, 5);
    test_preorder(BST);
    test_inorder(BST);
    test_postorder(BST);
    test_get_left(BST);
    test_remove_all(BST, 0);
    test_find(BST);
    test_remove_with_two_children(BST);
    BinaryTree *BST2 = new BinarySearchTree;
    test_ct_file_insert(BST2);
    test_num_leaves(BST2);
    test_tree_height(BST2);
    test_print_root(BST2);
    test_remove_root(BST2);
    test_remove_with_one_child(BST2);
    test_remove_with_no_children(BST2);
    test_average_age(BST2);
    BinaryTree *BST4 = new BinarySearchTree;
    test_ct_file_insert(BST4);
    test_remove_with_two_children(BST4);
    test_remove_with_two_children2(BST4);
    test_remove_leaf(BST4);
    test_remove_two_more(BST4);
    test_insert_new_survivor(BST4);
    test_copy_constructor();
    test_assignment_operator();
   

    cout << endl; 

    delete BST;
    delete BST2;
    delete BST4;

    return 0;
}



// Function test_insert
// Parameters: BT pointer, int for # of inserts
// Returns void
// Does: prints success if all the inserts worked
void test_insert(BinaryTree *bt, int num_items)
{
    Survivor *vives = new Survivor[num_items];
    for (int i = 0; i < num_items; i++)
    {
        string lname = "Hatch";
        lname += to_string(i+1);
        vives[i].set_name("Richard", lname);
        bt->insert_item(vives[i]);
    }
    if (bt->get_length() == num_items)
    {
        cout << "test insert SUCCESS!\n";
    }
    else
    {
        cout << "test insert FAIL\n";
    }
    delete []vives;
}

// Function test_get_length
// Parameters: BT pointer, int for expected length
void test_get_length(BinaryTree *bt, int num_items)
{
    if (bt->get_length() == num_items)
    {
        cout << "test get length SUCCESS!\n";
    }
    else
    {
        cout << "test get length FAIL\n";
    }
}

// Print a preorder traversal
void test_preorder(BinaryTree *BT)
{
    cout << "Begin preorder test.\n";
    BT->preorder(cout);
    cout << "Expected Hatches: 1 2 3 4 5\n";
    cout << "Did that look right? If so then SUCCESS!\n\n";
}

// Print an inorder traversal
void test_inorder(BinaryTree *BT)
{
    cout << "Begin inorder test.\n";
    BT->inorder(cout);
    cout << "Expected Hatches: 1 2 3 4 5\n";
    cout << "Did that look right? If so then SUCCESS!\n\n";
}

// Print a postorder traversal
void test_postorder(BinaryTree *BT)
{
    cout << "Begin postorder test.\n";
    BT->postorder(cout);
    cout << "Expected Hatches: 5 4 3 2 1\n";
    cout << "Did that look right? If so then SUCCESS!\n\n";
}

// test_get_left
// Makes sure we correclty find the leftmost node
void test_get_left(BinaryTree *bt)
{
    TreeItem t = bt->get_leftmost();
    Survivor s;
    s.set_name("Richard", "Hatch1");
    if (t == s)
        cout << "test get_left SUCCESS\n";
    else
        cout << "test get_left FAIL\n";
}

// test_ct_file_insert
// inserts the castaways.txt file and tprints the output
void test_ct_file_insert(BinaryTree *BT)
{
    cout << endl << "***** TEST test_ct_file_insert (CASTAWAYS_FILE) *****\n";
    cout << "test_st_file_insert if names listed alphabetically then SUCCESS\n";
    
    ifstream fileIn;
    fileIn.open(CASTAWAYS_FILE.c_str());
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
    cout << "look at output to check if correct\n";
}

// test_print_root
// tests the root of the tree by printing it and it must haev a certain value
void test_print_root(BinaryTree *BT)
{
    cout << endl;
    cout << "***** TEST test_print_root *****\n";
    cout << "test_print root if name is Sonja Christopher WalnutCreek CA 63"; 
    cout << "then SUCCESS\n";
    BT->print_root(cout);
}

// test_remove_root
// removes the root and prints the tree to be sure the new list is printed
// alpbahetically with only root missing
void test_remove_root(BinaryTree *BT)
{
    cout << endl;
    cout << "***** TEST test_remove_root ***** \n";

    cout << "length of BT before removing root: " << BT->get_length() << endl;
    Survivor s;
    s.set_name("Sonja", "Christopher");
    cout <<"print_root if root says Sonja Christopher WalnutCreek CA 63 then \
    SUCCESS\n";
    BT->print_root(cout);    
    try
    {
        BT->remove_item(s);
    }
    catch (EmptyTree et)
    {
        cerr << et.what() << endl;
    }
    cout <<"print_root if new root says Gretchen Cordy Clarksville TN 38"; 
    cout << "then SUCCESS\n";
    BT->print_root(cout);
    cout << "length of BT after removing root: " << BT->get_length() << endl;
    cout <<"print in order if order alphabetical with only Sonja Christopher \
    missing then SUCCESS\n"; 
    cout <<"if old length 36 and new length 35 then SUCCESS\n";
    BT->inorder(cout);
}

// test_remove_with_one_child
// removes a node with one child and prints tree to be sure it is alpahbetical
// with only this node missing
void test_remove_with_one_child(BinaryTree *BT)
{
    cout << endl;
    cout << "***** TEST test_remove_with_one_child **********" << endl;
    cout << "removing Jeff Varner\n";
    cout << "*** full list printed:\n";
    Survivor s;
    s.set_name("Jeff", "Varner");
    BT->remove_item(s);
    cout << "full list after removing Jeff Varner"  << endl;
    BT->inorder(cout);
    cout << "if everyone in alphabetical order and Jeff missing then SUCCESS\n";
    cout << "length of BT after removing Jeff: " << BT->get_length() << endl;

    cout << endl;
    cout << "now removing Kel Gleason" << endl;
    s.set_name("Kel", "Gleason");
    try
    {
        BT->remove_item(s);
    }
    catch (EmptyTree et)
    {
        cerr << et.what() << endl;
    }
    cout << "full list after removing KEl Gleason"  << endl;
    BT->inorder(cout);
    cout << "if everyone in alphabetical order and Kel missing then SUCCESS\n";
    cout << "length of BT after removing Kel: " << BT->get_length() << endl;
}

// test_remove_with_two_children
// removes a node with two children and prints tree to be sure it is 
// alpahbetical with only this node missing
void test_remove_with_two_children(BinaryTree *BT)
{
    cout << endl;
    cout << "***** TEST test_remove_with_two_children **********" << endl;
    cout << "full list before removing Joel Klug"  << endl;
    BT->inorder(cout);
    cout << endl;
    Survivor s;
    s.set_name("Joel", "Klug");
    cout << "full list after removing Joel Klug"  << endl;
    try
    {
        BT->remove_item(s);
    }
    catch (EmptyTree et)
    {
        cerr << et.what() << endl;
    }
    BT->inorder(cout);
    cout << "length of BT after removing Joel Klug: " \
    << BT->get_length() << endl;
}
// test_remove_with_two_children2
// another test that removes a node with two children and prints tree 
// to be sure it is alpahbetical with only this node missing
void test_remove_with_two_children2(BinaryTree *BT)
{
    cout << endl;
    cout << "***** TEST test_remove_with_two_children2 **********" << endl;
    Survivor s;
    s.set_name("Dirk", "Been");
    try
    {
        BT->remove_item(s);
    }
    catch (EmptyTree et)
    {
        cerr << et.what() << endl;
    }
    cout << "full list after removing Dirk Been"  << endl;
    BT->inorder(cout);
    cout << "length of BT after removing Dirk Been: "; 
    cout << BT->get_length() << endl;
}

// test_remove_with_no_children
// removes a node with no children and prints tree to be sure it is alpahbetical
// with only this node missing
void test_remove_with_no_children(BinaryTree *BT)
{
    cout << endl;
    cout << "***** TEST test_remove_with_no_child **********" << endl;
    Survivor s;
    s.set_name("Kimmi", "Kappenberg");
    try
    {
        BT->remove_item(s);
    }
    catch (EmptyTree et)
    {
        cerr << et.what() << endl;
    }
    BT->inorder(cout);
    cout << "if everyone in alphabetical order and Kimmi missing then \
    SUCCESS\n";
    cout << "length of BT after removing Kimmi: " << BT->get_length() << endl;
}

// test_average_age
// make sure average age is calculated correctly
void test_average_age(BinaryTree *BT)
{
    cout << endl;
    cout << "***** TEST test_average_age **********" << endl;
    cout << "average age: " << BT->average_age();
    cout << endl;
    cout << "if average is 34.5 then GREAT SUCCESS!!" << endl;
}

// test_num_leaves
// make sure the number of leaves is counted correctly
void test_num_leaves(BinaryTree *BT)
{
    cout << endl;
    cout << "***** TEST test_num_leaves **********" << endl;
    cout << "num leaves: " << BT->get_number_of_leaves() << endl;
    cout << "if number is 10 then SUCCESS!!" << endl;
}

// test_tree_height
// make sure the tree height is correct
void test_tree_height(BinaryTree *BT)
{
    cout << endl;
    cout << "***** TEST test_tree_height **********" << endl;
    cout << "tree height: " << BT->get_height()  << endl;
    cout << "if tree height is 8 then SUCCESS!!" << endl;
}

// test_remove_leaf (same as test_remove_with_no_children but with different
// node) removes a node with no children and prints tree to be sure 
// it is alpahbetical with only this node missing
// this is a test that needs to be checked by looking at output
void test_remove_leaf(BinaryTree *BT)
{
    cout << endl;
    cout << "***** TEST test_remove_leaf **********" << endl;
    Survivor s;
    s.set_name("Carl", "Bilancione");
    try
    {
        BT->remove_item(s);
    }
    catch (EmptyTree et)
    {
        cerr << et.what() << endl;
    }
    cout << "full list after removing Carl Bilancione"  << endl;
    BT->inorder(cout);
    cout << "length of BT after removing Carl Bilancione: ";
    cout << BT->get_length() << endl;
    cout << "look at output to check if correct\n";
}

// test_remove_two_more
// test removing 2 more nodes - making sure results are correct
// this is a test that needs to be checked by looking at output
void test_remove_two_more(BinaryTree *BT)
{
    cout << endl;
    cout << "***** TEST test_remove_two_more **********" << endl;
    Survivor s;
    s.set_name("Greg", "Buis");
    Survivor s2;
    s2.set_name("Rudy", "Boesch");
    try
    {
        BT->remove_item(s);
        BT->remove_item(s2);
    }
    catch (EmptyTree et)
    {
        cerr << et.what() << endl;
    }
    cout << "full list after removing Greg Buis and Rudy Boesch"  << endl;
    BT->inorder(cout);
    cout << "removed Greg Buis and Rudy Boesch"  << endl;
    cout << "length of BT after removing both: " << BT->get_length() << endl;
    cout << "look at output to check if correct\n";
}

// test_insert_new_survivor
// tests that new list includes new survivor and checks length of new list
// this is a test that needs to be checked by looking at output
void test_insert_new_survivor(BinaryTree *BT)
{
    cout << endl;
    cout << "***** TEST test_insert_new_survivor **********" << endl;
    Survivor s;
    s.set_name("Aaron", "Andersen");
    try
    {
        BT->insert_item(s); 
    }
    catch (FullTree ft)
    {
        cerr << "FullTree error caught on insert_item" << endl;
    }
    cout << "full list after inserting Aaron Andersen"  << endl;
    BT->inorder(cout);
    cout << "length of BT after inserting Aaron Andersen: " ;
    cout << BT->get_length() << endl;
    cout << "look at output to check if correct\n";
}

// test_remove_all
// test that removes all nodes from list and makes sure length is zero
void test_remove_all(BinaryTree *BT, int new_length)
{
    cout << endl;
    cout << "***** TEST test_remove_all **********" << endl;
    Survivor s1("Richard", "Hatch1"), 
        s2("Richard", "Hatch2"),
        s3("Richard", "Hatch3"),
        s4("Richard", "Hatch4"),
        s5("Richard", "Hatch5");

    try
    {
        BT->remove_item(s1);
        BT->remove_item(s2);
        BT->remove_item(s3);
        BT->remove_item(s4);
        BT->remove_item(s5);
    }
    catch (EmptyTree et)
    {
        cerr << et.what() << endl;
    }

    if (BT->get_length() == new_length)
        cout << "test remove SUCCESS\n";
    else
        cout << "test remove FAIL\n";

   BT->inorder(cout);
}

// Function test_find
// Attempts to find items
// non-existing item
void test_find(BinaryTree *BT)
{
    Survivor notthere1("Richard", "Hatch1"), 
        notthere2("Tom", "Hanks");
    bool found;
    BT->find_item(notthere1, found);

    if (!found)
        cout << "test find (nonexisting): SUCCESS\n";
    else
        cout << "test find (nonexisting): FAIL\n";

    BT->find_item(notthere2, found);
    if (!found)
        cout << "test find (nonexisting): SUCCESS\n";
    else
        cout << "test find (nonexisting): FAIL\n";
}

// test_copy_constructor
// compares the original and copied lists to make sure they are the same
void test_copy_constructor()
{
    cout << endl << "testing copy constructor" << endl;
    Survivor s1;
    s1.set_name("Person", "One");
    Survivor s2;
    s2.set_name("Person", "Two");
    BinarySearchTree BST6;

    try
    {
        BST6.insert_item(s1);
        BST6.insert_item(s2);
    }
    catch (FullTree ft)
    {
        cerr << "FullTree error caught on insert_item" << endl;
    }

    //invoke copy constructor
    BinarySearchTree BST5 = BST6;

    cout << endl << "*** original tree: ***" << endl;
    BST6.inorder(cout);
    cout  << endl << "*** copied tree: ***" << endl;
    BST5.inorder(cout);
    cout <<"if the original tree and copied tree look the same,";
    cout << "then SUCCESS" << endl;
}

// test_assignment_operator
// compares the original and copied lists to make sure they are the same
void test_assignment_operator()
{
    cout << endl << "testing assignment operator" << endl;

    BinarySearchTree BST6;
    Survivor s1;
    s1.set_name("BST6Person", "One");
    Survivor s2;
    s2.set_name("BST6Person", "Two");


    try
    {
        BST6.insert_item(s1);
        BST6.insert_item(s2);
    }
    catch (FullTree ft)
    {
        cerr << "FullTree error caught on insert_item" << endl;
    }

    BinarySearchTree BST5; 
    Survivor p1;
    p1.set_name("BST5Person", "One");
    Survivor p2;
    p2.set_name("BST5Person", "Two");
    Survivor p3;
    p3.set_name("BST5Person", "Three");

    try
    {
        BST5.insert_item(p1);
        BST5.insert_item(p2);
        BST5.insert_item(p3);
    }
    catch (FullTree ft)
    {
        cerr << "FullTree error caught on insert_item" << endl;
    }

    //invoke assignment operator
    BST5 = BST6;
    
    cout << endl << "*** original tree: ***" << endl;
    BST6.inorder(cout);
    cout  << endl << "*** copied tree: ***" << endl;
    BST5.inorder(cout);
    cout <<"if the original tree and copied tree look the same,"; 
    cout << "then SUCCESS" << endl;
}


