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

LinkedList<int> insert(LinkedList<int>);
LinkedList<int> delete_one(LinkedList<int>);
LinkedList<int> make_empty(LinkedList<int>);

int main()
{
	srand(time(NULL));

	// Create a LinkedList object and insert some values
    // (Secretly testing copy constructor as well)
	LinkedList<int> my_list;
    my_list = insert(my_list);
    my_list.print(cout);

    // Delete one in the middle and print again
    my_list = delete_one(my_list);
    my_list.print(cout);

    // Delete every element in the list 
    my_list = make_empty(my_list);

    return 0;
}

LinkedList<int> insert(LinkedList<int> my_list)
{
	// Add 10 randomly generated integers to the LinkedList
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
    return my_list;
}

LinkedList<int> delete_one(LinkedList<int> my_list)
{
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
    return my_list;
}

LinkedList<int> make_empty(LinkedList<int> my_list)
{
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
    return my_list;
}
