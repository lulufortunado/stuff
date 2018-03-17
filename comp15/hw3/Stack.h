/*
 * Stack.h
 * COMP15
 * Spring 2018
 * Homework 3
 * Effie Kazakos
 *
 * Interface for Stack 
 * for Reverse Polish Notation 
 * (RPN) calculator
 */
#include <exception>
#include <fstream>
using namespace std;

#ifndef STACK_H_
#define STACK_H_

// class Fullstack
// we can throw our custom FullStack excpetion anywhere we want
class FullStack : public exception{
public:
    const char * what() const throw() {return "Oh no, the stack is full!\n";}; 
};
// class EmptyStack
// we can throw our custom EmptyStack excpetion anywhere we want
class EmptyStack : public exception{
public:
    const char * what() const throw() {return "Oh no, the stack is empty!\n";}; 
};

//struct used for our linked list stack node
struct NodeType
{
    double value;
    NodeType *next;
};

class Stack
{
public:
    // Default constructor
    Stack();

    // Destructor
    ~Stack();

    //Copy constructor
    Stack(const Stack &);

    // Assignment Operator
    Stack & operator = (const Stack &);

    // top, push and pop operations
    double top() const;
    void push(double);
    void pop();

    // Puts top_pos pointer back to
    // initial state
    void reset_stack();
    
    // Empty list and deallocate memory
    void make_empty();

    //determines if list is full or not
    bool is_full() const;

    //determines if list is empty or not
    bool is_empty() const;
    
    // Return some basic info
    int get_size() const;

    // Print value of top element
    void print_top(ostream &) const;

private:
    int length;
    NodeType *head;
};


#endif
