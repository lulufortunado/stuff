/*
 * list-driver.cpp
 *
 * Practice problem for COMP15
 * Spring 2018
 */

#include "LLPractice.h"
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

const int LIST_LENGTH = 10;

int main()
{
	srand(time(NULL));

	// Create a LinkedList object
	LLPractice my_list;

	// Add 10 randomly generated integers to the LinkedList
	for (int i = 0; i < LIST_LENGTH; i++)
	{
		int r = rand() % 20;
		my_list.insert(r);
	}

    // Print all the elements
    my_list.print();

	// Check that the length of the linked list is 10
	if (my_list.get_length() == LIST_LENGTH)
	{
		cout << "Success! Size of list is 10.\n";
	}
	else
	{
		cout << "Failure: Size of list is " 
            << my_list.get_length() << endl;
	}

    // Delete the value at index 4
	int index = 4;
	my_list.delete_value_at(index);
	if (my_list.get_length() == LIST_LENGTH -1)
	{
		cout << "Success! Element was deleted\n";
	}
	else
	{
		cout << "Failure: After delete, the list "
             << "has length " << my_list.get_length() << endl;
	}
    my_list.print();

    // Put a new element at the beginning
    int value = 18;
    my_list.insert(value);

    if (my_list.get_length() == LIST_LENGTH && 
        my_list.get_value_at(0) == 18)
    {
        cout << "Success! Element added at beginning\n";
    }
    else
    {
        cout << "Failed to insert element\n";
    }
    my_list.print();


    // Delete every element in the list 
	my_list.make_empty();

	if (my_list.get_length() == 0)
	{
		cout << "Success! List was cleared.\n";
	}
	else
	{
		cout << "Failure: Size of list is " 
             << my_list.get_length() 
             << " after make_clear was called.\n";
	}

    return 0;
}
