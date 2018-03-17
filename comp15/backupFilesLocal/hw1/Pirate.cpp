/*
 * Pirate.cpp
 * COMP15
 * Spring 2018
 *
 * Implarrrrrrmentation of a Pirate
 */

#include <iostream>
#include <cstdlib>
#include "Pirate.h"
using namespace std;

int Pirate::pirate_count = 0;

Pirate::Pirate()
{
    pirate_id = -1;
    name = "Cap'n Hook";
}

Pirate::Pirate(string n)
{
    assign_pirate_id();
    name = n;
}
// Function print
// Input: ostream, const
// Returns: none
// Does: Prints pirate_id and name to ostream
// provided, and only for valid pirate_id > -1
// so we don't print out our pirate created in
// default constructor
void Pirate::print(ostream &outobject) const
{
    if(pirate_id > -1)
    {
      outobject << pirate_id << " "
         << name;
    }
}

void Pirate::generate_pirate_name(ifstream &infile, int range)
{
    string pname;
    int rando = rand() % range;
    int count = 0;

    infile.clear();
    infile.seekg(0, ios::beg);
    while (getline(infile, pname))
    {
        if (count == rando)
        {
            name = pname;
            break;
        }
        count++;
    }
}

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

void Pirate::assign_pirate_id()
{
    pirate_id = pirate_count++;
}

bool operator == (const Pirate &p1, const Pirate &p2)
{
    return (p1.pirate_id == p2.pirate_id);
}

