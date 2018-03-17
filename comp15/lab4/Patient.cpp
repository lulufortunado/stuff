/*
 * Patient.cpp
 *
 * Implementation for Patient class
 * 
 * COMP15
 * Spring 2018
 * Lab 4
 */

#include <iostream>
#include "Patient.h"
using namespace std;

// Default constructor
Patient::Patient()
{
    fname = "Jane";
    lname = "Doe";
    chest_pain = false;
    head_wound = false;
    temp = 98.6;
    pulse = 0;
    priority = FIVE;
}

// Parameterized constructor
Patient::Patient(string f, string l)
{
    fname = f;
    lname = l;
}
void Patient::calculate_priority(bool chestPainIn, bool headIn, double tempIn, unsigned pulseIn) 
{
    chest_pain = chestPainIn;
    head_wound = headIn;
    temp = tempIn;
    pulse = pulseIn;


    if (pulse > 140 || head_wound)
    {
        priority = ONE;
    }
    else if(temp > 100)
    {
        priority = TWO;
    }
    else if (chest_pain)
    {
         priority = THREE;
    }
    else if (pulse < 30)
    {
        priority = FOUR;
    }
    else{
        priority = FIVE;
    }
}

// Overloading comparison operators
bool operator < (const Patient &p1, const Patient &p2)
{
    return (p1.priority < p2.priority);
}

bool operator > (const Patient &p1, const Patient &p2)
{
    return (p1.priority > p2.priority);
}

// Print the patient
ostream & operator << (ostream &out, const Patient &p)
{
    out << p.fname << " " << p.lname << endl;
    out << ((p.head_wound) ? "Head wound\n" : "");
    out << ((p.chest_pain) ? "Chest pain\n" : "");
    out << "Pulse: " << p.pulse << endl;
    out << "Temp: " << p.temp << endl;
    out << "PRIORITY " << p.priority << endl;
    return out;
}


