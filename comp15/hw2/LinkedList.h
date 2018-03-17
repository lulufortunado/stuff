/*
 * LinkedList.h
 * COMP15
 * Spring 2018
 * Homework 2
 * Effie Kazakos
 *
 * Interface for Linked List of Planets
 *
 * What is an astronaut's favorite candy bar?
 *
 * A milky way!
 */

#include "Planet.h"
#include <fstream>

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

class LinkedList
{
public:
    // Default constructor
    LinkedList();

    // Destructor
    ~LinkedList();

    //Copy constructor
    LinkedList(const LinkedList &);

    // Assignment Operator
    LinkedList & operator = (const LinkedList &);

    // The basic operations:
    // Insert, delete, and find
    void insert_planet(Planet);
    void delete_planet(Planet);
    Planet get_next_planet();
    Planet find_planet(Planet, bool &) const;

    // Puts curr_pos pointer back to
    // initial state
    void reset_list();
    
    // Empty list and deallocate memory
    void make_empty();

    //determines if list is full or not
    bool is_full() const;
    
    // Return some basic info
    int get_length() const;

    // Print the list
    void print(ostream &) const;

private:
    int length;
    NodeType *head;
    NodeType *curr_pos;
};

#endif
