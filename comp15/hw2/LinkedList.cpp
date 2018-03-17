/*
 * LinkedList.cpp
 * COMP15
 * Spring 2018
 * Homework 2
 * Effie Kazakos
 * 
 * Implementation for Linked List of Planets
 *
 * What is an astronaut's favorite candy bar?
 *
 * A mars bar!
 */

#include "LinkedList.h"
#include <iostream>
using namespace std;

// Default constructor
// resets length, head and curr_pos
LinkedList::LinkedList()
{
    length = 0;
    head = NULL;
    curr_pos = NULL;
}

// Destructor
// Does: Deallocates all the allocated NodeTypes 
// in the list, and sets the value of head to NULL
// make_empty() does this
LinkedList::~LinkedList()
{
    make_empty();
}

// Copy constructor
// this uses our overloaded assignment operator
LinkedList::LinkedList(const LinkedList &l)
{  
    *this = l;
}

// Assignment operator
LinkedList & LinkedList::operator = (const LinkedList &l)
{
    length = l.length;
    curr_pos = NULL;
    if (l.head == NULL)
        head = NULL;
    else
    {
        head = new NodeType;
        head->info = l.head->info;
        head->next = NULL;
        NodeType *curr = head;
        NodeType *orig = l.head;
        while (orig->next != NULL)
        {
            curr->next = new NodeType;
            curr->next->info = orig->next->info;
            curr->next->next = NULL;
            orig = orig->next;
            curr = curr->next;
        }
    }
    return *this;
}

// Function make_empty
// Inputs: none
// Returns: none
// Does: empties list and deallocates
// memory
void LinkedList::make_empty()
{
    NodeType *temp = head;

    while (head != NULL) {
        temp = head;
        head = temp->next;
        delete temp;
    }

    head = NULL;
}

// Function insert_planet
// Input: Planet object
// Returns: None
// Does: Adds Planet to beginning of array, increases length
void LinkedList::insert_planet(Planet p)
{
    NodeType *new_planet = new NodeType;
    new_planet->info = p;
    new_planet->next = head;

    head = new_planet;
    length++;
}

// Function delete_planet
// Input: Planet object
// Returns: None
// Does: Deletes first instance planet from linked 
// list if found. If planet not found we return
// out of function before deleting the temp
// pointer and changing length. Length is decreased 
// by 1 if delete happens.
// First if is special case of our found planet to 
// be the head node.
void LinkedList::delete_planet(Planet p)
{
    NodeType *temp = head, *prev;
 
    if (temp != NULL && temp->info == p)
    {
        temp = head;
        head = temp->next;
    }
    else
    {
        while (temp != NULL && temp->info != p)
        {
            prev = temp;
            temp = temp->next;
        }
     
        if (temp == NULL) 
        {
            return;
        }
     
        prev->next = temp->next;
    }
 
    length--;
    delete temp;

}

// Function find_planet
// Inputs: Planet object, bool by reference, NodeType pointer by reference
// Returns: Planet object
// Does: Looks for passed planet in linked list, modifies bool found if found
// and modifies location pointer to point to the found planet
// returns the object from the list and not the passed one
// (In case they're different)
Planet LinkedList::find_planet(Planet p, bool &found) const
{
    NodeType *location = head;
    found = false;

    while (location != NULL)
    {
        if (location->info == p)
        {
            found = true;
            return location->info;
        }
        location = location->next;
    }
    
    return p;
}

// Function get_next_planet
// Inputs: none
// Returns: none
// Does: Returns the Planet object at the current pos
//       Wraps around to beginning if we're at the end
//       Returns a default planet if empty
Planet LinkedList::get_next_planet()
{
    if (length == 0)
    {
        Planet p;
        return p;
    }
    if (curr_pos == NULL)
        curr_pos = head;
    else
        curr_pos = curr_pos->next;
    return curr_pos->info;
}

// Function get_length, const
// Inputs: none
// Returns: int, length of list
int LinkedList::get_length() const
{
    return length;
}

// Function print, const
// Inputs: ostream object
// Returns: none
// Does: prints every element in the list
void LinkedList::print(ostream &out) const
{
    NodeType *location = head;
    while (location != NULL)
    {
        (location->info).print(out);
        out << endl;
        location = location->next;
    }
}

// Function reset_list
// Inputs: none
// Returns: none
// Does: sets curr_pos back to initial
// state
void LinkedList::reset_list()
{
    curr_pos = NULL;
}

// Function is_full
// Inputs: none
// Returns: bool
// Does: returns true if list is
// full, false if not
bool LinkedList::is_full() const
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



