/*
 * Planet.h
 * COMP15
 * Spring 2018
 *
 * Interface for a Planet class
 */

#include <fstream>
#include <string>
using namespace std;

#ifndef PLANET_H_
#define PLANET_H_

class Planet
{
public:
    Planet();
    Planet(string);
    void print(ostream &) const;
    friend bool operator == (const Planet &, const Planet &);
private:
    string name;
};

struct NodeType
{
    Planet info;
    NodeType *next;
};

#endif
