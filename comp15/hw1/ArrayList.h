/*
 * ArrayList.h
 * COMP15
 * Spring 2018 
 * Effie Kazakos
 * Interface for Array of Pirates, matey
 */

#include "Pirate.h"

#ifndef ARRAY_H_
#define ARRAY_H_

const int MAX_PIRATES = 100;

class ArrayList
{
public:
    // Default constructor
    ArrayList();
    // Destructor
    ~ArrayList();

    // The basic operations:
    // Insert, Delete, and Find
    Pirate find_pirate(Pirate, bool &, int &) const;
    void insert_pirate(Pirate);
    void delete_pirate(Pirate);
   
    // Shrink and expand array
    void expand_array();
    void shrink_array();

    //return next pirate in array
    Pirate get_next_pirate();

    // Start over at the beginning of the list
    void make_empty();
    void reset_array();

    // Return some basic info
    int get_length() const;

    // Print the array
    void print(ostream &) const;

private:
    int capacity;
    int length;
    Pirate* pirates;
    int curr_pos;
};

#endif
