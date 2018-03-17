#include "LinkedList.h"
#include <iostream>
using namespace std;

// Function to reverse a linked list
void reverse_list(LinkedList &, LinkedList &);

// User string to stop entering planets
const string STOP = "done";

int main()
{
    // Make a list of planets and prompt user for names
	LinkedList planets;

	string name;
	do
	{
		cout << "Enter a planet (or \"done\" to stop)\n";
		cin >> name;
        cout << endl;

		if(name != STOP)
		{
			Planet p(name);
			planets.insert_planet(p);
		}
	} while (name != STOP);


    // Print in default order (backwards)
    cout << "List of planets, default:\n";
    planets.print(cout);	

    LinkedList planets_reversed;
    reverse_list(planets, planets_reversed);

    // Print in reverse order
    cout << "List of planets, in correct order:\n";
    planets_reversed.print(cout);	


    return 0;	
}

// YOUR CODE HERE
// This function should take the elements of l
// and put them in reverse order into l2
// No need to return anything; both are passed by reference
void reverse_list(LinkedList &l, LinkedList &l2)
{
	int listLength = l.get_length();
	for(int i=0; i < listLength; i++)
	{
		l2.insert_planet(l.get_next_planet());
	}
	
}
