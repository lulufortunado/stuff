/* 
 * Planet.cpp
 * COMP15
 * Spring 2018
 * Homework 2
 * Effie Kazakos
 *
 * Interface for a Planet class
 * with green cheese on top
 */

#include "Planet.h"

// Default constructor
// sets name to default value
Planet::Planet()
{
    name = "Unplanet";
}

// Parameterized constructor
// sets name to passed parameter
Planet::Planet(string n)
{
    name = n;
}

// Function print 
// Input: ostream object by reference
// Returns: planet name to provided 
// output stream
void Planet::print(ostream &out) const
{
    out << name;
}

// Function overloaded == operator 
// Input: Planet object by reference, Planet object by reference
// Returns: true if the two input planet objects have the same name,
// false if not
bool operator == (const Planet &p1, const Planet &p2)
{
    return (p1.name == p2.name);
}

// Function overloaded != operator 
// Input: Planet object by reference, Planet object by reference
// Returns: false if the two input planet objects have the same name,
// true if not
bool operator != (const Planet &p1, const Planet &p2)
{
    return (p1.name != p2.name);
}


