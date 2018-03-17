/*
 * ArrayList.h
 * COMP15
 * Spring 2018 
 *
 * Interface for Array of integers
 */


#ifndef ARRAY_H_
#define ARRAY_H_

const int MAX_INTS = 100;

class ArrayList
{
public:
    // Default constructor
    ArrayList();

    // The basic operations:
    // Insert, Delete, and Find
    int find(int) const;
    void insert(int);
    void remove(int);

private:
    int length;
    int ray[MAX_INTS];
};

#endif
