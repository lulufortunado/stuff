/*
 * Pirate.cpp
 * COMP15
 * Spring 2018
 * Effie Kazakos
 * Implarrrrrrmentation of a Pirate
 */

#include <iostream>
#include <cstdlib>
#include "Pirate.h"
using namespace std;

int Pirate::pirate_count = 0;

// Default constructor
// Input: none
// Does: assigns default pirate_id
// and name
Pirate::Pirate()
{
    pirate_id = -1;
    name = "Cap'n Hook";
}

// Parameterized constructor
// Input: string
// Does: assigns name member 
// variable to provided name
// and assigns new pirate_id
Pirate::Pirate(string n)
{
    assign_pirate_id();
    name = n;
}

// Function print
// Input: ostream object by reference
// Returns: none
// Does: Prints pirate_id and name to ostream
// provided 
void Pirate::print(ostream &outobject) const
{
    outobject << pirate_id << " "
      << name;
}

// Function generate_next_pirate
// Input: iftream object by reference
// Returns: none
// Does: reads next line from ifstream input
// and saves it to name member variable
// otherwise generates error to cerr if input 
// ifstream cannot be opened
void Pirate::generate_next_pirate(ifstream& infile)
{
  if (infile.is_open())
  {
    getline(infile, name);
  }
  else
  {
    cerr << "Unable to open file"; 
  }   
}

// Function assign_pirate_id
// Input: none
// Returns: none
// Does: increments the static pirate_count 
// member variable and assigns pirate_id to it
void Pirate::assign_pirate_id()
{
    pirate_id = pirate_count++;
}

// Function Pirate object == operater overload
// Input: Pirate by reference, Pirate by reference
// Returns: boolean
// Does: compares the pirate_id values of the two
// pirate objects provided and returns true if 
// they are equal and false if not
bool operator == (const Pirate &p1, const Pirate &p2)
{
    return (p1.pirate_id == p2.pirate_id);
}

