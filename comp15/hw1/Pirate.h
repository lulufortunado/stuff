/*
 * Pirate.h
 * COMP15
 * Spring 2018
 * Effie Kazakos
 * Interface for a Pirate class
 * yo ho ho
 */

#include <fstream>
#include <ostream>
#include <string>
using namespace std;

#ifndef PIRATE_H_
#define PIRATE_H_


class Pirate
{
public:
    Pirate();
    Pirate(string);
    void print(ostream &) const;
    void generate_next_pirate(ifstream &);
    void assign_pirate_id();
    void generate_next_pirate();
    friend bool operator == (const Pirate &, const Pirate &);
private:
    int pirate_id;
    string name;
    static int pirate_count;
};

#endif
