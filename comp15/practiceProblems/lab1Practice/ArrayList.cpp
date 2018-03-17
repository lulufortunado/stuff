/*
 * Array.cpp
 * COMP15
 * Spring 2018
 *
 * Implementation for ArrayList of ints
 */

#include "ArrayList.h"

// Default constructor
// Length and current position default to 0
ArrayList::ArrayList()
{
    length = 0;
}

// Function find
// Inputs: integer
// Returns: Position of first instance of the int found
// Does: Iterates through the array until the given int is found
//       returns -1 if not found
int ArrayList::find(int target) const
{
    int location = 0;

    while (location < length)
    {
        if (target == ray[location])
        {
            return location;
        }
        location++;
    }
    return -1;
}

// Function insert
// Inputs: integer
// Returns: Nothing
// Does: Adds Pirate to end of array, increases length
void ArrayList::insert(int item)
{
    ray[length] = item;
    length++;
}

// Function remove
// Inputs: Integer
// Returns: Nothing
// Does: Deletes first instance of int, shifts everything else over
void ArrayList::remove(int target)
{
    int location = 0;

    while (location < length)
    {
        if (target == ray[location])
            break;
        else 
            location++;
    }
    if (location == length)
        return;

    while (location < (length-1))
    {
       ray[location] = ray[location+1];
       location++;
    }
    length--;
}


