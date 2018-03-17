/*
 * list-driver.cpp
 *
 * Practice problem for COMP15
 * Spring 2018
 *
 * Put some templates up in here
 */

#include "LinkedList.h"
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

const int LIST_LENGTH = 10;

LinkedList<double> insert(LinkedList<double>);
LinkedList<double> delete_one(LinkedList<double>);
LinkedList<double> make_empty(LinkedList<double>);

int main()
{
	srand(time(NULL));

	// Create a LinkedList object and insert some values
    // (Secretly testing copy constructor as well)
	LinkedList<double> my_list;
    my_list = insert(my_list);
    my_list.print(cout);

    // Delete one in the middle and print again
    my_list = delete_one(my_list);
    my_list.print(cout);

    // Delete every element in the list 
    my_list = make_empty(my_list);

    return 0;
}

// Function insert
// Adds LIST_LENGTH randomly-generated elements
// checks that the length of the list matches
// Prints success or failure
// Returns the modified Linked List object
LinkedList<double> insert(LinkedList<double> my_list)
{
	for (int i = 0; i < LIST_LENGTH; i++)
	{
		int r = rand() % 20;
        try
        {
    		my_list.insert(r);
        }
        catch (FullList fle)
        {
            cerr << fle.what();
            return my_list;
        }
	}
	if (my_list.get_length() == LIST_LENGTH)
		cout << "Success! Size of list is 10.\n";
	else
		cout << "Failure: Size of list is " 
            << my_list.get_length() << endl;
    return my_list;
}

// Function delete_one
// Removes the item at index 4
// Checks that the length has decreased by 1
// Prints success or failure
// Returns the list object
LinkedList<double> delete_one(LinkedList<double> my_list)
{
	int index = 4;
    int old_length = my_list.get_length();
    my_list.delete_value_at(index);

	if (my_list.get_length() == old_length -1)
		cout << "Success! Element was deleted\n";
	else
		cout << "Failure: After delete, the list "
             << "has length " << my_list.get_length() << endl;

    return my_list;
}

// Function make_empty
// Clear the list and check that length is 0
// Print success or failure
// Return the modified list
LinkedList<double> make_empty(LinkedList<double> my_list)
{
	my_list.make_empty();
	if (my_list.get_length() == 0)
		cout << "Success! List was cleared.\n";
	else
	{
		cout << "Failure: Size of list is " 
             << my_list.get_length() 
             << " after make_clear was called.\n";
	}
    return my_list;
}
