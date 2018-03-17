/*
 * test-more-files.cpp
 *
 * Some BASIC functionality testing
 * on the Binary Tree class.
 * 
 * It can lull you into a false sense of
 * security, though. 
 *
 * Don't fall for it!
 * 
 * Write more testing code!
 * 
 * WILLLLSOOOOONNNNNN!!!!!
 *
 * COMP15
 * Spring 2018
 *
 */

#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "Survivor.h"
using namespace std;

void test_get_length(BinaryTree *, int);
void test_insert(BinaryTree *, int);
void test_insert_duplicates(BinaryTree *, int);
void test_preorder(BinaryTree *);
void test_inorder(BinaryTree *);
void test_postorder(BinaryTree *);
void test_find(BinaryTree *);
void test_find_notthere(BinaryTree *);
void test_remove(BinaryTree *, int);
void test_remove2(BinaryTree *, int);
void test_get_left(BinaryTree *);
void test_num_leaves(BinaryTree *);
void test_copy_constructor();
void test_assignment_operator();


int main()
{
    BinaryTree *BT = new BinaryTree;
    test_get_length(BT, 0);
    test_insert(BT, 5);
    test_preorder(BT);
    test_inorder(BT);
    test_postorder(BT);

    test_num_leaves(BT);
    cout << "if num leaves is 3 then SUCCESS" << endl;
    
    test_find(BT);    
    test_remove(BT, 2);

    test_num_leaves(BT);
    cout << "if num leaves is 1 then SUCCESS" << endl;

    test_get_left(BT);
    test_insert_duplicates(BT, 5);
    test_copy_constructor();
    test_assignment_operator();
    test_remove2(BT, 0);

    test_num_leaves(BT);
    cout << "if num leaves is 0 then SUCCESS" << endl;

    test_find_notthere(BT); 
    test_remove(BT, 0);
    
    delete BT;

    return 0;
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

// Function test_insert_duplicates
// Parameters: BT pointer, int for # of inserts
// Returns void
// Does: tests inserting a duplicate 
// prints success if all the inserts worked
void test_insert_duplicates(BinaryTree *bt, int num_items)
{
    cout << endl << "testing for inserting duplicates" << endl;
    test_insert(bt, num_items);
    cout << endl;
    bt->inorder(cout);
    cout << "Expected Hatches: 3 2 5 4 1\n";
    cout << "Did that look right? If so then SUCCESS!\n\n";
}

// Function test_find
// Attempts to find an existing and a
// non-existing item
void test_find(BinaryTree *BT)
{
    Survivor there("Richard", "Hatch1"), 
        notthere("Tom", "Hanks");
    bool found;

    BT->find_item(there, found);


    if (found)
        cout << "test find (nonexisting): SUCCESS\n";
    else
        cout << "test find (nonexisting): FAIL\n";

    BT->find_item(notthere, found);

    if (!found)
        cout << "test find (nonexisting): SUCCESS\n";
    else
        cout << "test find (nonexisting): FAIL\n";
}

// Function test_find_notthere
// Attempts to find two nonexisting items
void test_find_notthere(BinaryTree *BT)
{
    Survivor notthere1("Richard", "Hatch1"), 
        notthere2("Tom", "Hanks");
    bool found;

    BT->find_item(notthere1, found);


    if (!found)
        cout << "test find (existing item): SUCCESS\n";
    else
        cout << "test find (existing item): FAIL\n";

    BT->find_item(notthere2, found);

    if (!found)
        cout << "test find (nonexisting): SUCCESS\n";
    else
        cout << "test find (nonexisting): FAIL\n";
}

// Print a preorder traversal
void test_preorder(BinaryTree *BT)
{
    cout << "Begin preorder test.\n";
    BT->preorder(cout);
    cout << "Expected Hatches: 1 2 4 5 3\n";
    cout << "Did that look right? If so then SUCCESS!\n\n";
}

// Print an inorder traversal
void test_inorder(BinaryTree *BT)
{
    cout << "Begin inorder test.\n";
    BT->inorder(cout);
    cout << "Expected Hatches: 4 2 5 1 3\n";
    cout << "Did that look right? If so then SUCCESS!\n\n";
}

// Print a postorder traversal
void test_postorder(BinaryTree *BT)
{
    cout << "Begin postorder test.\n";
    BT->postorder(cout);
    cout << "Expected Hatches: 4 5 2 3 1\n";
    cout << "Did that look right? If so then SUCCESS!\n\n";
}

// Function: test remove
// Remove a leaf node, a rooto, a node in the deepest leaf
// and a node that's already been removed
void test_remove(BinaryTree *BT, int new_length)
{
    Survivor leaf("Richard", "Hatch3"), 
        root("Richard", "Hatch1"),
        deepest("Richard", "Hatch5"),
        alreadyremoved("Richard", "Hatch5");

    try
    {
        BT->remove_item(leaf);
        BT->remove_item(root);
        BT->remove_item(deepest);
        BT->remove_item(alreadyremoved);
    }
    catch (EmptyTree et)
    {
        cerr << et.what();
    }

    if (BT->get_length() == new_length)
        cout << "test remove SUCCESS\n";
    else
        cout << "test remove FAIL\n";

   BT->inorder(cout);
}

//test_remove2 to empty tree
void test_remove2(BinaryTree *BT, int new_length)
{
    cout << endl;
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
        cerr << et.what();
    }

    if (BT->get_length() == new_length)
        cout << "test remove all items SUCCESS\n";
    else
        cout << "test remove FAIL\n";

   BT->inorder(cout);
}

// test_get_left
// Makes sure we correclty find the leftmost node
void test_get_left(BinaryTree *bt)
{
    TreeItem t = bt->get_leftmost();
    Survivor s;
    s.set_name("Richard", "Hatch2");
    if (t == s)
        cout << "test get_left SUCCESS\n";
    else
        cout << "test get_left FAIL\n";
}

void test_num_leaves(BinaryTree *BT)
{
    cout << endl;
    cout << "testing number of leaves" << endl;
    cout << "num leaves: " << BT->get_number_of_leaves() << endl;
}

// test_copy_constructor
// tests copy constructor
// output of original and copied trees must be eyeballed to see if correct
void test_copy_constructor()
{
    cout << endl << "testing copy constructor" << endl;
    Survivor s1;
    s1.set_name("Person", "One");
    Survivor s2;
    s2.set_name("Person", "Two");
    
    BinaryTree BST6;
    BST6.insert_item(s1);
    BST6.insert_item(s2);
    
    //invoke copy constructor
    BinaryTree BST5 = BST6;
    
    cout << endl << "*** original tree: ***" << endl;
    BST6.inorder(cout);
    cout  << endl << "*** copied tree: ***" << endl;
    BST5.inorder(cout);
    cout <<"if the original tree and copied tree look the same, then SUCCESS";
    cout << endl;
}

// test_assignment_operator
// tests assignment operator
// output of original and copied trees must be eyeballed to see if correct
void test_assignment_operator()
{
    cout << endl << "testing assignment operator" << endl;

    BinaryTree BT6;
    Survivor s1;
    s1.set_name("BST6Person", "One");
    Survivor s2;
    s2.set_name("BST6Person", "Two");
    BT6.insert_item(s1);
    BT6.insert_item(s2);
    

    BinaryTree BT5; 
    Survivor p1;
    p1.set_name("BST5Person", "One");
    Survivor p2;
    p2.set_name("BST5Person", "Two");
    Survivor p3;
    p3.set_name("BST5Person", "Three");
    BT5.insert_item(p1);
    BT5.insert_item(p2);
    BT5.insert_item(p3);

    //invoke assignment operator
    BT5 = BT6;
    
    cout << endl << "*** original tree: ***" << endl;
    BT6.inorder(cout);
    cout  << endl << "*** copied tree: ***" << endl;
    BT5.inorder(cout);
    cout <<"if the original tree and copied tree look the same,"; 
    cout << "then SUCCESS" << endl;
}





