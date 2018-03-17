/*
 * Array.cpp
 * COMP15
 * Spring 2018
 * Effie Kazakos
 * Implementation for Arrrrrrray of Pirates
 */
#include <iostream>

#include "ArrayList.h"

using namespace std;

// Default constructor
// Length and current position default to 0
// Initialize capacity member variable to
// const MAX_PIRATES and pirates member 
// pointer to new array with this 
// capacity
ArrayList::ArrayList()
{ 
    length = 0;
    curr_pos = 0;
    capacity = MAX_PIRATES;  
    pirates = new Pirate[MAX_PIRATES];
}
// Destructor
// Delete dynamic array 
ArrayList::~ArrayList()
{
    delete [] pirates;
}

// Function find_pirate
// Inputs: Pirate object, bool by reference, int by reference
// Returns: Pirate object
// Does: Looks for passed pirate in the array, modifies bool found if found
// and modifies int arrayLocation if found to index of array 
// where pirate found, returns the object from the list and not the passed one
// (In case they're different.)
Pirate ArrayList::find_pirate(Pirate p, bool &found, int &arrayLocation) const
{
    int location = 0;
    arrayLocation = -1;

    while ((location < length) && !found)
    {
        if (p == pirates[location])
        {
            found = true;
            arrayLocation = location;
            p = pirates[location];
            break;
        }

        location++;
    }
    return p;
}

// Function insert_pirate
// Inputs: Pirate object
// Returns: Nothing
// Does: Adds Pirate to end of array, avoids 
// segmentation fault by increasing length
// if the length exceeds capacity,
// returns if pirate is found to already be 
// in list
void ArrayList::insert_pirate(Pirate p)
{
    for (int i=0; i < length; i++)
    {
        if (p == pirates[i])
        {
            return;
        }
    }
    if (length > capacity - 1)
    {
       expand_array();
    }

    pirates[length] = p;
    length++;  
}
// Function expand_array
// Inputs: Nothing
// Returns: Nothing
// Does: expands array by creating a new array
// that has double the capacity. We double capacity
// ('capacity' is our member variable to keep 
// track of it), copy the old contents into it,
// and point the pirates pointer to it 
// (pirates is our member pointer) and delete
// the old array to free up memory
void ArrayList::expand_array()
{
    capacity *= 2;

    cout << "Expand to " << capacity << endl;

    Pirate* new_pirates = new Pirate[capacity];

    for (int i= 0; i < length; i++)
    {
        new_pirates[i] = pirates[i];
    }

    delete [] pirates;
    pirates = new_pirates;
}

// Function shrink_array
// Inputs: Nothing
// Returns: Nothing
// Does: shrinks array by creating a new array
// that has half the capacity. We halve the capacity
// ('capacity' is our member variable to keep 
// track of it), copy the old contents into it,
// and point the pirates pointer to it 
// (pirates is our member pointer) and delete
// the old array to free up memory
void ArrayList::shrink_array()
{
    capacity = capacity/2;

    cout << "Contract to " << capacity << endl;

    Pirate* new_pirates = new Pirate[capacity];
    
    for (int i= 0; i < length; i++)
    {
        new_pirates[i] = pirates[i];
    }

    delete [] pirates;
    pirates = new_pirates;
}
// Function delete_pirate
// Inputs: Pirate object
// Returns: Nothing
// Does: Looks for pirate, and if found, deletes
// it by shifting everything else over. Whether
// pirate is found or not, checks if array is
// less than half capacity and if so calls
// shrink_array() to shrink array in half.
void ArrayList::delete_pirate(Pirate p)
{
    bool pirateFound = false;
    int location;

    p = find_pirate(p, pirateFound, location);

    if (pirateFound)
    {
        while (location < (length-1))
        {
            pirates[location] = pirates[location+1];
            location++;
        }

        length--;
    }

    if (length < capacity/2)
    {
        shrink_array();
    }
}

// Function get_next_pirate
// Input: None
// Returns: Pirate object
// Does: Returns pirate at curr_pos
// Increments curr_pos, but wraps around
Pirate ArrayList::get_next_pirate()
{
    Pirate p = pirates[curr_pos];
    curr_pos = (curr_pos + 1) % length;
    return p;
}

// Function make_empty
// Input: none
// Returns: none
// Does: sets length to 0 (memory not modified)
void ArrayList::make_empty()
{
    length = 0;
}

// Function reset_array
// Input: none
// Returns: none
// Does: sets curr_pos to 0 
void ArrayList::reset_array()
{
    curr_pos = 0;
}

// Function print
// Input: ostream object by reference
// Returns: none
// Does: Prints array from 0 to length
// if length is 0 returns out of function, doesn't 
// print. A zero-length array will have a dummy 
// pirate in the first position, with pirate_id 
// of -1 and we don't want to print that
void ArrayList::print(ostream &outobject) const 
{
    if (length < 1)
    {
        return;
    }

    pirates[0].print(outobject);

    for (int i = 1; i < length; i++)
    {
        pirates[i].print(outobject << ", ");
    }
}

// Function get_length
// Input: none
// Returns: int
// Does: Returns the value in length attribute
int ArrayList::get_length() const
{
    return length;
}
