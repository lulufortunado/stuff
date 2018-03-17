/*
 * Stack.h
 * COMP15
 * Spring 2018
 *
 * Demo'ing using auxiliary structures for some
 * fancy stack operations
 *
 * Apart from sum functions, it's just exactly like a regular
 * stack data structure
 */

#include <exception>
#include "Queue.h"
using namespace std;

#ifndef STACK_H_
#define STACK_H_

// Custom exception classes
class FullStack : public exception 
{
public:
    const char *what() const throw() 
    { 
        return "NO CAN HAZ INPUTS";}
    };

class EmptyStack : public exception 
{
public:
    const char *what() const throw() 
    { 
        return "NO disassemble stack FIIIIVE!!!!"; 
    } 
};

class Stack
{
public:
    Stack();
    ~Stack();
    Stack(const Stack &);
    Stack & operator = (const Stack &);

    void push(ItemType);
    void pop();
    ItemType top() const;
    int get_size() const;

    bool is_full() const;
    bool is_empty() const;
    void make_empty();

    // These are new! Everything else is old
    ItemType sum();
    ItemType sum_alt();
private:
    NodeType *top_ptr;
    int size;
};


// Helper function to get the sum
ItemType sum_helper(Stack);


#endif
