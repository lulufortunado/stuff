/*
 * COMP15
 * Spring 2018
 * Demo'ing how we call a stack-sum operation
 */

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Stack.h"
using namespace std;

const int MAX_STACK = 5;

int main()
{
    srand(time(NULL));

    // Push a bunch of random elements onto a stack
    Stack s;
    for (int i = 0; i < MAX_STACK; i++)
    {
        try 
        {
           double item = rand() % 50;
           cout << "Pushing " << item << endl;;     
           s.push(item);
        }
        catch(FullStack e)
        {
            cerr << e.what() << endl;
            return 1;
        }
    }

    // Calculate and report the sum
    ItemType sum = s.sum();
    cout << "\nGot sum: " << sum << endl << endl;

    // Sanity check by dismantling the stack and announcing 
    // each element; should be reverse order of pushes above
    for (int i = 0; i < MAX_STACK; i++)
    {
        try 
        {
            ItemType item = s.top();
            s.pop();
            cout << "Popped " << item << endl;
        }
        catch(EmptyStack e)
        {
            cerr << e.what() << endl;
            return 1;
        }

    }

    return 0;
}

