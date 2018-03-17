/*
 * COMP15
 * Spring 2018
 * Queue Practice Problems
 */

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Queue.h"
using namespace std;

const int MAX_QUEUE = 5;

int main()
{
    srand(time(NULL));

    // Create a queue, and enqueue a bunch of ints
    // onto it.
    Queue q;
    for (int i = 0; i < MAX_QUEUE; i++)
    {
        try 
        {
           int item = rand() % 50;
           cout << "Enqueuing " << item << endl;;     
           q.enqueue(item);
        }
        catch(FullQueue e)
        {
            cout << e.what() << endl;
        }
    }

    // Now dequeue each item and print as we go
    // It should print in FIFO order
    for (int i = 0; i < MAX_QUEUE+1; i++)
    {
        try 
        {
            int item;
            q.dequeue(item);
            cout << "Dequeued " << item << endl;         
        }
        catch(EmptyQueue e)
        {
            cout << e.what() << endl;
        }
    }

    return 0;
}

