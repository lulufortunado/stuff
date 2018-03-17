/*
 * RPNCalc.h
 * COMP15
 * Spring 2018
 * Homework 3
 * Effie Kazakos
 *
 * Interface
 * for Reverse Polish Notation 
 * (RPN) calculator
 */
#include "Stack.h"
#include <fstream>
#include <string>
using namespace std;

#ifndef RPNCALC_H_
#define RPNCALC_H_

class RPNCalc
{
public:
    // Default constructor
    RPNCalc();

    // Destructor
    ~RPNCalc();

    //runs the calculator
    void run();

    //performs pop of top 2 values and saves them
    void pop_top_two_values(double & , double &);

    //does stack pop with try/catch
    void do_pop();

    //does stack push with try/catch
    void do_push(double);

    //determines if parameter is type double
    bool is_double(string);

    //handlers for input cases 
    bool handle_file_in(string);
    bool handle_input(string);

    // Print given string to given output
    void print(ostream &, string) const;

private:
    Stack s;

};

#endif
