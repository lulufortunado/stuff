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


    cout << "get_value_at(1): " << my_list.get_value_at(1) << endl;

    cout << "delete_value_at(0): " << endl;

    my_list.delete_value_at(0);

    cout << "new list:" << endl;

     my_list.print();

	return 0;
}