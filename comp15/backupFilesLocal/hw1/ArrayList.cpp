/*
 * Array.cpp
 * COMP15
 * Spring 2018
 *
 * Implementation for Arrrrrrray of Pirates
 */
#include <iostream>
#include <assert.h>

#include "ArrayList.h"

using namespace std;

// Default constructor
// Length and current position default to 0
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
// Does: Looks for pirate in the array, modifies bool found if found
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
// Does: Adds Pirate to end of array, increases length
// returns if pirate is found to already be in list
void ArrayList::insert_pirate(Pirate p)
{
    for(int i=0; i < length; i++)
    {
        if(p == pirates[i])
        {
            return;
        }
    }
    // avoid segmentation fault error by expanding array 
    // in the case that the array length is greater than the
    // current capacity 
    if(length > capacity - 1)
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
// that has double the capacity, copying the old
// contents into it, and pointing the pirates
// pointer to it and deleting the old array 
void ArrayList::expand_array()
{
    //set the new array capacity to expand to a bigger array
    capacity *= 2;

    cout << "Expand to " << capacity << endl;
    //create a new pointer and a new array with a bigger size
    //and point the new pointer to it
    Pirate* new_pirates = new Pirate[capacity];
    //copy the contents of the old array into this new one
    for (int i= 0; i < length; i++)
    {
        new_pirates[i] = pirates[i];
    }
    //delete the original array to free up the memory
    delete [] pirates;
    //update our pirates pointer to point to the
    //newly-allocated larger array
    pirates = new_pirates;
}

// Function shrink_array
// Inputs: Nothing
// Returns: Nothing
// Does: contracts array by half by creating a new 
// array with half the capacity of the original array,
// copies the contents of the old array into it (this
// assumes that the orignal array is no more than half
// full), points the piratas pointer to the new smaller 
// array and deletes the old array
void ArrayList::shrink_array()
{
    //set the new array capacity to shrink to half of current
    // capacity
    capacity = capacity/2;

    cout << "Contract to " << capacity << endl;
    //create a new pointer and a new array with a smaller
    //(half) size and point the new pointer to it
    Pirate* new_pirates = new Pirate[capacity];
    //copy the contents of the old array into this new one
    for (int i= 0; i < length; i++)
    {
        new_pirates[i] = pirates[i];
    }
    //delete the original array to free up the memory
    delete [] pirates;
    //update our pirates pointer to point to the
    //newly-allocated larger array
    pirates = new_pirates;
}
// Function delete_pirate
// Inputs: Pirate object
// Returns: Nothing
// Does: Deletes pirate, shifts everything else over
void ArrayList::delete_pirate(Pirate p)
{
    bool pirateFound = false;
    int location;

    p = find_pirate(p, pirateFound, location);

    if(pirateFound)
    {
        while (location < (length-1))
        {
            pirates[location] = pirates[location+1];
            location++;
        }

        length--;
    }

    if(length < capacity/2)
    {
        shrink_array();
    }
}

// Function get_next_pirate
// Input: None
// Returns: Pirate object
// Does: Returns pirate at curr_pos
//       Increments curr_pos, but wraps around
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
// Input: none, const
// Returns: none
// Does: Prints array from 0 to length
void ArrayList::print(ostream &outobject) const 
{
    pirates[0].print(outobject);

    for (int i = 1; i < length; i++)
    {
        pirates[i].print(outobject << ", ");
    }
}

// Function get_length
// Input: none, oncst
// Returns: int
// Does: Returns the value in length attribute
int ArrayList::get_length() const
{
    return length;
}
