/*
 * Stack.cpp
 * COMP15
 * Spring 2018
 * Homework 3
 * Effie Kazakos
 * 
 * Implementation for Stack 
 * for Reverse Polish Notation 
 * (RPN) calculator
 */

#include "Stack.h"
#include <iostream>
using namespace std;

// Default constructor
// resets length, head and top_pos
Stack::Stack()
{
    length = 0;
    head = NULL;
}

// Destructor
// Does: Deallocates all the allocated NodeTypes 
// in the list, and sets the value of head to NULL
// make_empty() does this
Stack::~Stack()
{
    make_empty();
}

// Copy constructor
Stack::Stack(const Stack &s)
{  
    length = s.length;
    if (s.head == NULL)
        head = NULL;
    else
    {
        head = new NodeType;
        head->value = s.head->value;
        head->next = NULL;
        NodeType *curr = head;
        NodeType *orig = s.head;
        while (orig->next != NULL)
        {
            curr->next = new NodeType;
            curr->next->value = orig->next->value;
            curr->next->next = NULL;
            orig = orig->next;
            curr = curr->next;
        }
    }
}

// Assignment operator
Stack & Stack::operator = (const Stack &s)
{
    length = s.length;
    if (s.head == NULL)
        head = NULL;
    else
    {
        head = new NodeType;
        head->value = s.head->value;
        head->next = NULL;
        NodeType *curr = head;
        NodeType *orig = s.head;
        while (orig->next != NULL)
        {
            curr->next = new NodeType;
            curr->next->value = orig->next->value;
            curr->next->next = NULL;
            orig = orig->next;
            curr = curr->next;
        }
    }
    return *this;
}

// Function top
// Inputs: none
// Returns: double
// Does: Returns the value of the element on 
// the top of the stack. If stack is empty
// we throw our own EmptyStack exception
double Stack::top() const
{
    if (is_empty())
    {
        throw EmptyStack();
    }
    else
    {
        return head->value;
    }
}

// Function push
// Inputs: double
// Returns: nothing
// Does: Pushes the provided value
// onto the stack and updates length. 
// First checks if stack is full 
// and throws our own FullStack
// exception if it is.
void Stack::push(double value) 
{    
    if (is_full())
    {
        throw FullStack();
    }
    else
    {
        NodeType *new_head = new NodeType;
        new_head->value = value;
        new_head->next = head;
        head = new_head;
        length++;
    }
}

// Function pop
// Inputs: nothing
// Returns: nothing
// Does: Removes the element on the 
// top of the stack and updates length
// if stack is empty we throw our
// own EmptyStack and do not do anything
// to stack
void Stack::pop() 
{  
    if (is_empty())
    {
        throw EmptyStack();
    }
    else
    {
        NodeType *temp = head;
        head = head->next;
        delete temp;
        length--;
   }
}

// Function make_empty
// Inputs: none
// Returns: none
// Does: empties list and deallocates
// memory
void Stack::make_empty()
{
    NodeType *temp = head;

    while (head != NULL) {
        temp = head;
        head = temp->next;
        delete temp;
    }
    length = 0;
    head = NULL;
}

// Function get_size, const
// Inputs: none
// Returns: int, length of list
int Stack::get_size() const
{
    return length;
}

// Function print_top, const
// Inputs: ostream object
// Returns: none
// Does: outputs top() value
// to provided out in a try/catch
// if top() throws EmptyStack exception
// we don't print any value, we output
// the exception message
void Stack::print_top(ostream &out) const
{
    try
    {
        out << top() << endl;
    }
    catch (EmptyStack ese)
    {
        out << "You want to print but the stack is empty." << endl;
    }
}

// Function reset_stack
// Inputs: none
// Returns: none
// Does: sets head back to initial
// state
void Stack::reset_stack()
{
    head = NULL;
}

// Function is_full
// Inputs: none
// Returns: bool
// Does: returns true if list is
// full, false if not
bool Stack::is_full() const
{
    try
    {
        NodeType *node = new NodeType;
        delete node;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}

// Function is_empty
// Inputs: none
// Returns: bool
// Does: returns true if list is
// empty
bool Stack::is_empty() const
{
    if (head == NULL) 
    {
        return true;
    }

    return false;
}



