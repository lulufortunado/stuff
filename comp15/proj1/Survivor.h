/*
 * Survivor.h
 *
 * Interface for Survivor
 *
 * COMP15
 * Spring 2018
 *
 */
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#ifndef SURVIVOR_H_
#define SURVIVOR_H_

// this custom error is thrown in generate_next_castaway() if
// input file can't be opened
class FileError : public exception
{
public:
    const char * what() const throw() { return "File cannot be opened!\n"; }
};


class Survivor
{
public:
    //default constructor
    Survivor();

    //parameterized constructor2
    Survivor(string, string, string, string, int);
    Survivor(string, string);
    
    //destructor
    ~Survivor();

    //prints survivor information
    void print(ostream &) const;

   // void generate_next_castaway(ifstream&); 
    
    void generate_next_castaway(ifstream&); 
    void set_name(string, string);
    string get_name() const;
    int get_age() const;

    //overloaded comparison operators
    friend bool operator == (const Survivor &, const Survivor &);
    friend bool operator > (const Survivor &, const Survivor &);
    friend bool operator < (const Survivor &, const Survivor &);


private:
    string firstname;
    string lastname;
    string hometown;
    string state;
    int age;
};

#endif
