/*
 * Stack.cpp
 * COMP15
 * Spring 2018
 *
 * Implementation for a stack class
 *
 * Added a few functions to sum all the values
 * in a stack, demo'ing how we use auxiliary data 
 * structures. 
 */

#include "Stack.h"

// Default constructor
Stack::Stack()
{
    top_ptr = NULL;
    size = 0;
}

// Destructor
Stack::~Stack()
{
    NodeType *temp_ptr;
    while (top_ptr != NULL)
    {
        temp_ptr = top_ptr;
        top_ptr = top_ptr->next;
        delete temp_ptr;
    }
}

// Copy constructor
Stack::Stack(const Stack &s)
{
    size = s.size;
    if (s.top_ptr == NULL)
        top_ptr = NULL;
    else
    {
        top_ptr = new NodeType;
        top_ptr->info = s.top_ptr->info;
        top_ptr->next = NULL;
        NodeType *curr = top_ptr;
        NodeType *orig = s.top_ptr;
        while (orig->next != NULL)
        {
            curr->next = new NodeType;
            curr->next->info = orig->next->info;
            curr->next->next = NULL;
            orig = orig->next;
            curr = curr->next;
        }
    }
}

// Assignment operator
Stack & Stack::operator = (const Stack &s)
{
    size = s.size;
    NodeType *temp;
    while (top_ptr != NULL)
    {
        temp = top_ptr;
        top_ptr = top_ptr->next;
        delete temp;
    }
    if (s.top_ptr == NULL)
        top_ptr = NULL;
    else
    {
        top_ptr = new NodeType;
        top_ptr->info = s.top_ptr->info;
        top_ptr->next = NULL;
        NodeType *curr = top_ptr;
        NodeType *orig = s.top_ptr;
        while (orig->next != NULL)
        {
            curr->next = new NodeType;
            curr->next->info = orig->next->info;
            curr->next->next = NULL;
            orig = orig->next;
            curr = curr->next;
        }
    }
    return (*this);
}

// Push item onto the stack
// Throw exception if full
void Stack::push(ItemType item)
{
    if (is_full())
        throw FullStack();
    else
    {
        NodeType *location;
        location = new NodeType;
        location->info = item;
        location->next = top_ptr;
        top_ptr = location;
        size++;
    }
}

// Pop an item off the stack. Do not return a value.
// Throw exception if empty
void Stack::pop()
{
    if (is_empty())
        throw EmptyStack();
    else
    {
        NodeType *tmp_ptr;
        tmp_ptr = top_ptr;
        top_ptr = top_ptr->next;
        delete tmp_ptr;
        size--;
    }
}
// Return the value of the top element on the stack.
// Do not modify the stack.
// Throw exception if empty
ItemType Stack::top() const
{
    if (is_empty())
        throw EmptyStack();
    else
        return top_ptr->info;
}

// Get the current size of the satck
int Stack::get_size() const
{
    return size;
}

// Check for stack fullness
bool Stack::is_full() const
{
    NodeType *location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}

// Check for stack emptiness
bool Stack::is_empty() const
{
    return (top_ptr == NULL);
}

// Clear the stack and deallocate memory
void Stack::make_empty()
{
    NodeType *temp_ptr;

    while (top_ptr != NULL)
    {
        temp_ptr = top_ptr;
        top_ptr = top_ptr->next;
        delete temp_ptr;
    }

    top_ptr = NULL;
    size = 0;
}

// Function: sum
// Input: none
// Returns: sum of all elements in the stack
// Uses auxiliary structures to
// store elements so we can restore the original stack
ItemType Stack::sum()
{
    ItemType sum = 0;
    Stack s;
    while (!is_empty())
    {
        s.push(top());
        sum += top();
        pop();
    }
    while (!s.is_empty())
    {
        push(s.top());
        s.pop();
    }
    return sum;

}

// Function alt_sum
// Another way to do the sum without disassembling the stack
ItemType Stack::sum_alt()
{

/*    ItemType sum = 0;
    Stack s = *this;
    
    while (!s.is_empty())
    {
        sum += s.top();
        s.pop();
    }    

    return sum;
*/

    ItemType sum = 0;
    int count = 0;
    Queue q;
    while (!is_empty())
    {
        ItemType x = top();
        sum += x;
        q.enqueue(x);
        pop();
        count++;
    }

    ItemType *ray = new ItemType[count];
    count = 0;
    while (!q.is_empty())
    {
        ray[count] = q.dequeue();
        count++;
//        push(q.dequeue());
    }
    for (int i = count-1; i >= 0; i--)
    {
       push(ray[i]);
    }
    return sum;
}


