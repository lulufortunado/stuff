/*
 * survivor-driver.cpp
 *
 * 
 * 
 * COMP15
 * Spring 2018
 *
 */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "BinarySearchTree.h"
#include "Survivor.h"
using namespace std;

// Input files
const string STOWAWAYS_FILE = "stowaways.txt";
const string CASTAWAYS_FILE = "castaways.txt";
const string fileName[2] = {STOWAWAYS_FILE, CASTAWAYS_FILE};

//function declarations
BinaryTree*& round_one(BinaryTree *&, BinaryTree *&);
void round_two(BinaryTree *&);
void insert_survivors(string, BinaryTree *);

//main passes the returned winning BinaryTree to round_two
int main()
{   
	BinaryTree *BT  = new BinaryTree;
	BinaryTree *BST = new BinarySearchTree;
	BinaryTree *WBT = round_one(BT, BST);


	if (!WBT->is_empty())
	{
		round_two(WBT);
	}

   	delete BT;
   	delete BST;

	return 0;
}

// Function round_one
// Input: BinaryTree * by reference, BinaryTree * by reference
// Returns: BinaryTree * 
// Does: randomly picks one of the two files, stowaways.txt and 
// castaways.txt, to be put into a Binary Tree, and the other
// to by put in a Binary Search Tree. The number of leaves of
// each tree is comparedand the one with the smaller number
// of leaves is declared the winner, and the winning tree is
// returned as a BinaryTree *. Returns the round one winner to the 
// This function also handles the edge cases of one or both lists
// beign empty

BinaryTree*& round_one(BinaryTree *&BT, BinaryTree *&BST)
{
	srand (time(NULL));

	int randIndex = rand() % 2;
	int otherIndex = abs(randIndex - 1);
	int bt_num_leaves;
	int bst_num_leaves;

	insert_survivors(fileName[randIndex], BT);
	insert_survivors(fileName[otherIndex], BST);

	bt_num_leaves = BT->get_number_of_leaves();
	bst_num_leaves = BST->get_number_of_leaves();

	if (bt_num_leaves == 0 && bst_num_leaves == 0)
	{
		cout << "There is no one from round one. End of game." << endl;
		return BT;
	}
	else if (bt_num_leaves == 0 && bst_num_leaves == 1)
	{
		cout << "Loser had " << bt_num_leaves << " leaves" << endl;
		cout << "ROUND ONE WINNER: BST\n";
		BST->print_the_tree(cout);
		return BST;		
	}
	else if (bt_num_leaves == 1 && bst_num_leaves == 0)
	{
		cout << "Loser had " << bst_num_leaves << " leaves" << endl;
		cout << "ROUND ONE WINNER: BT\n";
		BT->print_the_tree(cout);
		return BT;
	}

	cout << endl;

	if (bt_num_leaves < bst_num_leaves)
	{
		cout << "Loser had " << bst_num_leaves << " leaves" << endl;
		cout << "ROUND ONE WINNER: BT\n";	
		BT->print_the_tree(cout);
		return BT;
	}
	else if (bst_num_leaves < bt_num_leaves)
	{
		cout << "Loser had " << bt_num_leaves << " leaves" << endl;
		cout << "ROUND ONE WINNER: BST\n";
		BST->print_the_tree(cout);
		return BST;
	}
	else if (bt_num_leaves == bst_num_leaves)
	{
		cout << "Loser had " << bst_num_leaves << " leaves" << endl;
		cout << "ROUND ONE WINNER: BT\n";
		BT->print_the_tree(cout);
		return BT;
	}

	throw NumLeavesError();
}

// Function round_two
// Input: BinaryTree * by reference
// Returns: nothing
// Does: recursive funtion that accepts winning BinaryTree from
// round one and recursively removes people in the tree with 
// age furthest from the average age in the tree 
void round_two(BinaryTree *&BT)
{
	if (BT == NULL)
	{
		return;
	}

	int avgAge 				= BT->average_age();
	TreeItem rightmost 		= BT->get_rightmost();
	TreeItem leftmost 		= BT->get_leftmost();
	int leftmostage 		= leftmost.get_age();
	int rightmostage 		= rightmost.get_age();

	TreeItem winner;
	TreeItem loser;

	cout << endl << "Average age this round " << avgAge << endl;

	if(rightmostage == leftmostage)
	{
		winner = rightmost;
		loser = leftmost;
	}
	else if (abs(rightmostage - avgAge) < abs(leftmostage - avgAge))
	{
		winner = rightmost;
		loser = leftmost;
	}
	else
	{
		winner = leftmost;
		loser = rightmost;
	}
	try
	{		
		if (BT->get_length() > 1)
		{
			BT->remove_item(loser);
			cout << "Voted off the island:" << endl;
			loser.print(cout);
		}

	}
	catch (EmptyTree et)
	{
		cerr << "There is no one left to vote off the island!\n";
	}
	
	if (BT->get_length() == 1)
	{
		cout << endl << "WINNING SURVIVOR:" << endl;
		winner.print(cout);
		cout << endl;
		return;
	}

	round_two(BT);
}
// Function insert_survivors
// Input: string, BinaryTree * by reference
// Returns: none
// Does: opens the file passed in the fileName input and 
// inserts all the names in it into the passed in BinaryTree 
void insert_survivors(string fileName, BinaryTree *BT)
{
	string firstword;
	ifstream fileIn;
    fileIn.open(fileName.c_str());

    if (!fileIn.is_open())
    {
        cerr << "Could not add survivors from file\n";
        return;
    }

    while (!fileIn.eof())
    {           
        Survivor s;

        try
        {
        	s.generate_next_castaway(fileIn);
        }
        catch(FileError fe)
        {
        	cerr << "file " << fileName << " could not be opened\n";
        	return;
        }
        

        if (s.get_name() != "-1 nolastname")
        {      
        	try
        	{
        		BT->insert_item(s); 
        	}
        	catch (FullTree ft)
        	{
        		cerr << "FullTree error caught on insert_item" << endl;
        	}
            
        }    
    }

    fileIn.close();
}
