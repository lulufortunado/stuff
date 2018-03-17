/*
 * Patient.h
 *
 * COMP15
 * Spring 2018
 *
 * Interface for a Patient
 * 
 */

#include <string>
using namespace std;

#ifndef PATIENT_H_
#define PATIENT_H_

enum Priority {ONE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5};

class Patient
{
public:
    Patient();
    Patient(string, string);
    void calculate_priority(bool, bool, double, unsigned, int, bool); 
    //for testing only
    void print_with_time_in(ostream &);

    friend bool operator < (const Patient &, const Patient &);
    friend bool operator > (const Patient &, const Patient &);
    friend bool operator == (const Patient &, const Patient &);
    friend ostream & operator << (ostream &, const Patient &);

private:
    string fname, lname;
    bool head_wound;
    bool chest_pain;
    bool ismax;
    double temp;
    unsigned pulse;
    int time_in;
    Priority priority;
};

#endif
