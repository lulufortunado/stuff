/*
 * Survivor.cpp
 *
 * Implementation for Survivor class
 * 
 * COMP15
 * Spring 2018
 *
 */
#include <iostream>
#include <sstream>
#include "Survivor.h"

// Constructor
Survivor::Survivor()
{
   firstname = "nofirstname";
   lastname = "nolastname";
   hometown = "nocity";
   state = "nostate";
   age = 0;
}

//parameterized constructor  that takes all parameters
Survivor::Survivor(string firstNameIn, string lastNameIn, 
                                    string cityIn, string stateIn, int ageIn)
{
	firstname = firstNameIn;
  lastname = lastNameIn;
  hometown = cityIn;
  state = stateIn;
  age = ageIn;
}

//parameterized constructor that takes only first name and last name
Survivor::Survivor(string firstNameIn, string lastNameIn)
{
  firstname = firstNameIn;
  lastname = lastNameIn;
}


// Destructor
Survivor::~Survivor()
{
   
}

// Function generate_next_castaway
// Input: iftream object by reference
// Returns: none
// Does: reads next line from ifstream input
// and saves it to name member variable
// otherwise generates error to cerr if input 
// ifstream cannot be opened
void Survivor::generate_next_castaway(ifstream& infile)
{
  string check;
  
  if (infile.is_open())
  {
    infile >> firstname;
    infile >> lastname;
    infile >> hometown;
    infile >> state;
    infile >> age;
  }
  else
  {
    throw FileError();
  } 
}

// Function set_name
// Input: string, string
// Returns: none
// Does: sets first and last name to input values
void Survivor::set_name(string firstnameIn, string lastnameIn)
{
	firstname = firstnameIn;
	lastname = lastnameIn;
}

// Function get_name
// Input: none
// Returns: string
// Does: returns firstname + " " + lastname
string Survivor::get_name() const
{
	return firstname + " " + lastname;
}

// Function get_age
// Input: none
// Returns: int
// Does: returns age
int Survivor::get_age() const
{
	return age;
}

// Function print
// Inputs: ostream by reference
// Returns: nothing
// Does: Prints 
// FirstName LastName
// hometown: city, state
// age: age
// to provided out

void Survivor::print(ostream &out) const
{   
	out << firstname << " " << lastname << endl;
	out << "hometown: " << hometown<< ", " << state << endl;
	out << "age: " << age << endl;
}

// Function overloaded == operator 
// Input: Survivor object by reference, Survivor object by reference
// Returns: true if the two input planet objects have the same name,
// false if not
bool operator == (const Survivor &s1, const Survivor &s2)
{
    return (s1.firstname == s2.firstname && s1.lastname == s2.lastname);
}

// Function overloaded > operator 
// Input: Survivor object by reference, Survivor object by reference
// Returns: true if s1 > s2 alphabetically, false if not
bool operator > (const Survivor &s1, const Survivor &s2)
{
    if (s1.lastname == s2.lastname)
    	return (s1.firstname > s2.firstname);
    return (s1.lastname > s2.lastname);
}

// Function overloaded < operator 
// Input: Survivor object by reference, Survivor object by reference
// Returns: true if s1 < s2 alphabetically, false if not
bool operator < (const Survivor &s1, const Survivor &s2)
{
    if (s1.lastname == s2.lastname)
    	return (s1.firstname < s2.firstname);
    return (s1.lastname < s2.lastname);
}
