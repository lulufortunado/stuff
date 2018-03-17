/*
 * vegas-topological.cpp
 *
 * COMP15
 * Spring 2018
 * March 15, 2018
 *
 * Prints a valid topological sort
 * of how you can get to VEGAS BABY
 */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "LinkedList.h"
using namespace std;

const int NUM_VERTICES = 9;

void read_adj_from_file(char *, LinkedList<string>[]);
void print_topo(LinkedList<string> []);
int find_no_deps(LinkedList<string> [], int);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Usage: ./vegas-topo [infilename]\n";
        return 1;
    }

    LinkedList<string> dependencies[NUM_VERTICES];
    read_adj_from_file(argv[1], dependencies);
    print_topo(dependencies);

    return 0;
}

// Function read_adj_from_file
// Input: file name, array of Linked Lists
// Returns: void
// Does: opens input file by name, reads in adjancency list
//       of dependencies.
void read_adj_from_file(char *fname, LinkedList<string> tasks[])
{
    ifstream infile;
    infile.open(fname);
    if (!infile.is_open())
    {
        cerr << "Could not open input file for reading\n";
        exit(1);
    }
    int counter = 0;
    while (!infile.eof())
    {
        string line;
        getline(infile, line);

        if (line == "-1")
            break;
        else if (counter < NUM_VERTICES)
        {
            stringstream ss(line);
            while (!ss.eof())
            {
                string tmp;
                ss >> tmp;
                if (tmp == "-1")
                    break;
                tasks[counter].insert(tmp);
            }
            counter++;
        }
    }
    infile.close();
}

// Function print_topo
// Input: 1d array of linked lists of strings
// Returns: nothing
// Does: Finds and prints one (of many) valid
//       topological sort from the given adjacency lists.
//       Expected structure of each linked list:
//       C1->C2->C3 (C3 is a dependency for C1 and C2)
void print_topo(LinkedList<string> deps[])
{
    // Find a class in the list that has no depdencies
    // Print it once found, and then remove its whole 
    // linked list from the array
    for (int i = 0; i < NUM_VERTICES; i++)
    {
        int index = find_no_deps(deps, NUM_VERTICES - i);

        if (index == -1)
            return;

        string valid = deps[index].get_last_element();
        cout << valid << endl;

        // Remove the linked list from the array
        for (int j = index; j < NUM_VERTICES - 1; j++)
            deps[j] = deps[j+1];
    }
}

// Function find_no_deps
// Input: linked list array of strings, length
// Returns: int, the position in the array of a linked list
//          whose last element has no dependencies
int find_no_deps(LinkedList<string> deps[], int length)
{
    for (int i = 0; i < length; i++)
    {
        bool has_dep = false;
        string pre_req = deps[i].get_last_element();
    
        // This task is possibly a pre-req for something
        // else, but is anything else a pre-req for me?
        for (int j = 0; j < length; j++)
        {
            bool found = false;
            pre_req = deps[j].find(pre_req, found);
            if (i != j && found)
            {
                has_dep = true;
                break;
            }
        }
        if (!has_dep)
            return i;
    }
    return -1;
}

