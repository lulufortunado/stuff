	/*
 * RPNCalc.cpp
 * COMP15
 * Spring 2018
 * Homework 3
 * Effie Kazakos
 * 
 * Implementation
 * for Reverse Polish Notation 
 * (RPN) calculator
 *
 */
#include "RPNCalc.h"
#include <iostream>
using namespace std;

// user input consts
const char STOP 		= 'Q';
const char PRINT 		= 'P';
const char CLEAR 		= 'C';
const char FILEIN		= 'F';
const char PLUS 		= '+';
const char MINUS 		= '-';
const char TIMES 		= '*';
const char DIVBY 		= '/';


// Default constructor
// make the stack we have initialized empty
RPNCalc::RPNCalc()
{
	s.make_empty();
}

// Destructor
// make sure we empty the stack we have 
// been using
RPNCalc::~RPNCalc()
{
	s.make_empty();
}
// Function run
// Inputs: nothing
// Returns: nothing
// Does: Does (RPN) calculation on user input into cin, and
// cin can also specify a file name that contains characters 
// to be read into RPN calculator (if user inputs 'f filename.txt'
// into cin). Reads inputs directly from cin or from file, 
// until the user hits the STOP character in standard cin indicated by the
// const char declarations above, or if user hit Ctrl-D (cin.eof()),
// or if handle_input returns false which happens if
// a STOP character input is encountered in an input file.
// handle_input returns true for all other inputs.
// Lets user know when we are exiting out of calculator.
void RPNCalc::run()
{
	bool continue_input = true;
	string input;
	char inputchar;
	
	cout << "Enter doubles, \"+\", \"-\", \"*\", \"/\" (or \"Q\" to stop)\n";
	cout << "or file name ('f filename.txt') to read characters from\n";

	do
	{
        cin >> input;

        inputchar = toupper(input[0]);

        if(cin.eof() || inputchar == STOP)
        {
        	continue_input = false;
        	break;
        }

        continue_input = handle_input(input);

	} while (continue_input);


	print(cout, "Exiting out of calculator");

}

// Function handle_input
// Inputs: string input
// Returns: bool
// Does: Switch stetement to perform correct operation
// based on user input (const char declarations at
// top of file are the ones referred to here).
// Returns true if we could continue accepting input,
// false if not. handle_input only returns false if 
// a STOP character is encountered in an input
// file because STOP input in cin is handled
// in our while loop in run(). If user inputs character
// different than the consts listed above or a something
// that's not a double data type, we let the user know and
// await next inputs. When the input is a double datatype
// we push it onto the stack. When the input is an operator
// we pop the two top values of the stack, do the specified 
// operation on the two values, and push the result onto
// th stack.
bool RPNCalc::handle_input(string input)
{
	bool continue_input = true;
	double popped1;
	double popped2;

	char inputchar = toupper(input[0]);

	switch (inputchar) {
        case PLUS: 
        	pop_top_two_values(popped1, popped2);
        	do_push(popped2 + popped1);
        	break;       	
        case MINUS: 
        	pop_top_two_values(popped1, popped2);
        	do_push(popped2 - popped1);
        	break;
        case TIMES: 
        	pop_top_two_values(popped1, popped2);
        	do_push(popped2 * popped1);
        	break;        	
        case DIVBY: 
        	pop_top_two_values(popped1, popped2);
        	do_push(popped2 / popped1);
        	break; 
        case CLEAR:
        	s.make_empty();
        	print(cout, "Stack has been cleared.");
        	break;
        case PRINT:
        	s.print_top(cout);
        	break;
        case FILEIN:
        	cin >> input;
        	continue_input = handle_file_in(input);
        	break;
        default:    
        	if (!is_double(input))
			{ 
				print(cout, "Command " + input + " not implemented ");
			}
			else
			{
				do_push(stod(input));
			}
	}
	return continue_input;
}

// Function pop_top_two_values
// Inputs: double by reference, double by reference
// Returns: nothing
// Does: pops the top two elements in the stack and saves the values
// to the provided parameter variables, p1 and p2
// we have the s.top() calls in try/catch blocks because
// s.top() throws an EmptyStack error if stack is
// empty
void RPNCalc::pop_top_two_values(double& p1, double& p2)
{
	try
	{
		p1 = s.top();
		do_pop();
	}
	catch (EmptyStack ese)
    {
        print(cerr, "cannot get top value because the stack is empty");
    }
	try
	{
		p2 = s.top();
		do_pop();
	}
	catch (EmptyStack ese)
    {
        print(cerr, "cannot get top value because the stack is empty");
    }
}

// Function do_push
// Inputs: double
// Returns: nothing
// Does: does a stack push in a try/catch
// to make sure to catch error if stack 
// is full 
void RPNCalc::do_push(double value)
{
	try
	{
    	s.push(value); 	
    }
    catch (FullStack fs)
	{
		print(cerr, "cannot do push because the stack is full");
	}
}

// Function do_pop
// Inputs: none
// Returns: nothing
// Does: does a stack pop in a try/catch
// to make sure to catch error if stack 
// is empty
void RPNCalc::do_pop()
{
	try
	{
		s.pop();
	}
	catch (EmptyStack ese)
	{
		print(cerr, "cannot do pop because the stack is empty");
	}
}


// Function is_double
// Inputs: string
// Returns: boolean
// Does: accepts string input and 
// returns true if it is successfully 
// converted to a double, false if not
bool RPNCalc::is_double(string in)
{	
	bool is_double = false;
	double op;

	try
	 {
	     op = stod(in);
	     is_double = true;
	     
	 }
	 catch (invalid_argument exception)
	 {
	     is_double = false;
	 }

	 return is_double;
}

// Function handle_file_in
// Inputs: string
// Returns: boolean
// Does: handles the case of reading input from
// a file which happens when user puts FILEIN character 
// into cin. It opens the file whose name is passed
// into input, and continues to read from the file 
// and handles the input characters with handle_input.
// If the input int the file contains a FILEIN character,
// then handle_file_in is called again to handle the 
// new file name (e.g. if file just opened contains a 
// line that says "f file_name.txt"). Otherwise we call
// handle_input to handle all other inputs. If the STOP 
// character is encountered in file being read in, we
// stop reading from file and return false. In all other
// cases we return true to say we want to keep reading.
bool RPNCalc::handle_file_in(string input)
{	
	bool continue_input = true;
	char inputchar; 
	string filenameIn;
	int i = 1;

	while (input[i] == ' ')
	{
		i++;
	}
	filenameIn = input.substr(i-1);

	ifstream infile;

    infile.open(filenameIn.c_str());

	if (!infile.is_open())
	{
	    print(cerr, "Could not open file " + filenameIn + "for reading");
	    return continue_input;
	}  
	print(cout, "Reading from file " + filenameIn);

	while (infile >> input)
    {   
    	inputchar = toupper(input[0]);  

       	if(inputchar == STOP)
       	{
       		continue_input = false;
       		break;
       	}
       	else if (inputchar == FILEIN)
       	{
       		infile >> input;
       		handle_file_in(input);
       	}
       	else
       	{
       		handle_input(input);   
       	}    	
    }

    infile.close();
    return continue_input;
	
}

// Function print
// Inputs: ostream by reference, string
// Returns: nothing
// Does: prints the provided string to the provided
// output
void RPNCalc::print(ostream &out, string outstring) const
{
    out << outstring << endl;
}




