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

}

// Parameterized constructor
Patient::Patient(string f, string l)
{
    fname = f;
    lname = l;
}

// Function: calculate_priority
// Inputs: bool, bool, double, unsigned, int, bool
// Returns: int
// Does: takes in data and sets patient properties to them, and determines 
// priority value based on spefific criteria, and sets patent priority
// member variable to it. The prioritization also depends on the value of 
// ismaxIn. If ismaxIn is true, the highest priority is FIVE and lowest ONE.
// If ismaxIn is false, the priority order is reversed.
void Patient::calculate_priority(bool chestpainIn, bool headwoundIn, 
                double tempIn, unsigned pulseIn, int timeinIn, bool ismaxIn) 
{    
    chest_pain  = chestpainIn;
    head_wound  = headwoundIn;
    temp        = tempIn;
    pulse       = pulseIn;
    time_in     = timeinIn;
    ismax       = ismaxIn;


    if ((head_wound && pulse < 90) || (chest_pain && pulse < 90)
                                                || (head_wound && chest_pain))
    {
        if (ismax) 
            priority = FIVE;
        else
            priority = ONE;
    }
    else if ((head_wound && pulse >= 90) || (chest_pain && pulse >= 90))
    {
        if (ismax)  
            priority = FOUR;
        else
            priority = TWO;
    }
    else if (!head_wound && !chest_pain && temp > 100 && pulse < 90)
    {
            priority = THREE;
    }
    else if ( pulse < 90 || temp > 100)
    {
        if (ismax) 
            priority = TWO;
        else
            priority = FOUR;
    }
    else
    {
        if (ismax)
            priority = ONE;
        else
            priority = FIVE;
    }

}

// Overloading comparison operators
// The operator compares the priority of the patients. 
// If the patients have the same priority the 
// the tie-breaker is time_in. 
// If ismax is false then this operator is being used by 
// by the minHeap class in heapify_up and heapify_down
// so the smallest priority goes to the top of the heap, and if 
// p1.priority == p2.priority the patient with the smaller time_in goes to 
// the top
bool operator < (const Patient &p1, const Patient &p2)
{

    bool minheap = false;
    minheap = !p1.ismax && !p2.ismax;

    if (p1.priority == p2.priority)
    {
        if (p1.time_in < p2.time_in)
        {
            if (minheap)
            {
                return true;
            }
            else
            {
                return false;
            }
            
        }
        else
        {
            if (minheap)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }

    if (p1.priority < p2.priority)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// Overloading comparison operators
// The operator compares the priority of the patients. 
// If the patients have the same priority the 
// the tie-breaker is time_in. 
// If ismax is true then this operator is being used by 
// the maxHeap class in heapify_up and heapify_down
// so the slargest priority goes to the top of the heap, and if 
// p1.priority == p2.priority the patient with the smaller time_in goes to 
// the top.
bool operator > (const Patient &p1, const Patient &p2)
{
    bool maxheap = false;
    maxheap = p1.ismax && p2.ismax;

    if (p1.priority == p2.priority)
    {
        if (p1.time_in < p2.time_in)
        {
            if (maxheap)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (maxheap)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }

    if (p1.priority > p2.priority)
    {
        return true;
    }
    else 
    {
        return false;    
    }
}

// Overloading comparison operator
// Patients are considered equal if they have the same priority and time in
bool operator == (const Patient &p1, const Patient &p2)
{
    if (p1.priority == p2.priority && p1.time_in == p2.time_in)
    {
        return true;
    }
    return false;    
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


