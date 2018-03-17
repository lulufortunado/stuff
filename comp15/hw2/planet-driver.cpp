/*
 * planet-driver.cpp
 * COMP15
 * Spring 2018
 * Homework 2
 * Effie Kazakos
 *
 * Astro-driver for your planets
 */

#include "LinkedList.h"
#include <iostream>
using namespace std;

// Input and output files
const string PLANET_FILE = "planet-names.txt";
const string OUTPUT_ONE = "planets-reversed.txt";
const string OUTPUT_TWO = "missing-keplers.txt";
const string OUTPUT_THREE = "original-order.txt";

// Const for failure and success
const int FAIL = -1;
const int SUCCESS = 0;
const int NUM_KEPLERS = 1500;

// Function to reverse a linked list
LinkedList reverse_list(LinkedList);

// HW2 functions to generate output files
int reverse_all_planets(LinkedList &);
int remove_keplers(LinkedList &);
int original_order(LinkedList);

int main()
{
    LinkedList planets;

    // HW2, Step One
    // Read in all the planets and print in reverse order
    int num_planets = reverse_all_planets(planets);
    if (num_planets == FAIL)
    {
        cerr << "Failed to reverse planets, exiting\n";
        return FAIL;
    }
    cout << "Read in " << num_planets << " planets from outer space\n";

    // HW2, Step Two
    // Get rid of some of the Kepler planets
    if (remove_keplers(planets) == FAIL)
    {
        cerr << "Failed to remove Keplers, exiting\n";
        return FAIL;
    }
    cout << "Removed Keplers\n";

    // HW2, Step Three
    // Print the Kepler-less list, in original order
    if (original_order(planets) == FAIL)
    {
        cerr << "Failed to put planets in their correct order\n";
        return FAIL;
    }
    cout << "Done!\n";
              
	return 0;	
}

// Function reverse_list
// Input: linked list, by value
// returns: linked list
// Does: puts the elements from the given
//       list into another, new list and returns it
LinkedList reverse_list(LinkedList l)
{
    LinkedList l2;
    int length = l.get_length();
    for (int i = 0; i < length; i++)
    {
        Planet p = l.get_next_planet();
        if (!l2.is_full())
            l2.insert_planet(p);
    }
    return l2;
}

// Function reverse_all_planets
// Input: linked list of planets
// Returns: -1 if failure, or the # of planets added
// Does: reads in from the planet file
//       adds planets from file to the existing list
int reverse_all_planets(LinkedList &planets)
{
    int counter = 0;

    // Read in original planet list from file
    ifstream infile;
    infile.open(PLANET_FILE.c_str());
    if (!infile.is_open())
    {
        cerr << "Could not add planets from file\n";
        return -1;
    }

    while (!infile.eof())
    {
        string planet_name = "";
        getline(infile, planet_name);
        if (planet_name == "")
            break;
        Planet p(planet_name);
        if (!planets.is_full())
            planets.insert_planet(p);
        counter++;
    }
    infile.close();

    // Print the untouched list; it'll be backwards
    ofstream outfile;
    outfile.open(OUTPUT_ONE.c_str());
    if (!outfile.is_open())
    {
        cerr << "Failed to open file for writing\n";
        return FAIL;
    }
    planets.print(outfile);
    outfile.close();
    return counter;
}

// Function remove_keplers
// Input: Linked list of planets (reference)
// Returns: -1 for failure, 0 otherwise
// Does: prints the same planets in the same order
//       without a bunch of kepler planets
int remove_keplers(LinkedList &planets)
{
    for (int i = 0; i < NUM_KEPLERS; i++)
    {
        string kep = "Kepler-";
        kep += to_string(i);
        kep += "b";
        Planet p(kep);
        planets.delete_planet(p);
    }

    // Print the keperless-list
    ofstream outfile;
    outfile.open(OUTPUT_TWO.c_str());
    if (!outfile.is_open())
    {
        cerr << "Failed to open file for writing\n";
        return FAIL;
    }
    planets.print(outfile);
    outfile.close();
    return 1;
}

// Function original_order
// Input: LinkedList of planets
// Returns: -1 if failure, 1 otherwise
// Does: reverses the list of planets
//       to get back to the correct order
int original_order(LinkedList planets)
{
    LinkedList l2 = reverse_list(planets);
    ofstream outfile;
    outfile.open(OUTPUT_THREE.c_str());
    if (!outfile.is_open())
    {
        cerr << "Failed to open file for writing\n";
        return FAIL;
    }
    l2.print(outfile);
    outfile.close();
    return SUCCESS;
}
