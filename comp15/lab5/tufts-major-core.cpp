/*
 * tufts-major.cpp
 *
 * COMP15
 * Spring 2018
 * Lab 5
 *
 * Print out all the ways you could complete
 * the comp sci major (core courses only)
 */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "LinkedList.h"
using namespace std;

const int NUM_CORE = 7;

void read_majors_from_file(char *, LinkedList<string>[]);
void print_legitimate_permutations_in_file(char *, LinkedList<string>[]);
int find_deps(LinkedList<string> deps[], string, int &);


// Get arguments from the command line first!
// Expected usage: ./major tufts-major-core.txt all-possible-orders.txt
int main(int argc, char* argv[])
{
    
    if (argc != 3)
    {
        cerr << "Usage: ./major [infilename] [infilename]\n";
        return 1;
    }

    LinkedList<string> dependencies[NUM_CORE];

    // Note that this function call passes argv[1]
    // that's second command-line argument, tufts-major-core.txt
    read_majors_from_file(argv[1], dependencies);

    // reads in all-possible-order.txt (second argument) which is file
    // with all possible permutations, and prints out the permutation
    // row that is a legitmate permutation by using the dependencies 
    // linked list created in read_majors_from_file function
    //print_legitimate_permutations_in_file(argv[2], dependencies);

    print_legitimate_permutations_in_file(argv[2], dependencies);

    return 0;
}

// Function read_majors_from_file
// Input: file name, array of Linked Lists
// Returns: void
// Does: opens input file by name, reads in adjancency list
//       of course dependencies.
void read_majors_from_file(char *fname, LinkedList<string> courses[])
{

    ifstream infile;
    infile.open(fname);
    if (!infile.is_open())
    {
        cerr << "Could not open input file for reading\n";
        exit(1);
    }
    int course_counter = 0;
    while (!infile.eof())
    {
        string line;
        getline(infile, line);

        if (line == "-1")
            break;
        else if (course_counter < NUM_CORE)
        {
            stringstream ss(line);
            while (!ss.eof())
            {
                string tmp;
                ss >> tmp;
                if (tmp == "-1")
                    break;
                courses[course_counter].insert(tmp);
            }
            course_counter++;
        }
    }
    infile.close();
}

// Function find_deps
// Input: dependency linked list array, string pre_req, int & find_deps_count
// Returns: int
// Does: Finds the provided course (pre_req) in the provided adjacency list
// deps, to see if it matches a last elements in deps, where last element 
// is a prerequisite (it has dependencies in its array). If it matches, then
// we look to see if it has dependencies by looking for it in all other 
// arrays in deps (adjacency list). If it has no other dependencies we
// delete the row where it is the last element (where 
// pre_req == deps[i].get_last_element(). In this case we update the 
// find_deps_count counter. If it does have other dependencies we don't do
// anything, we just decrement the find_deps_count counter.
// 

int find_deps(LinkedList<string> deps[], string pre_req, int& find_deps_count)
{
    
    // Find a class in the list that has no depdencies
    // Print it once found, and then remove its whole 
    // linked list from the array
    int dependencies_index = -1;
    bool has_dep = false;

    for (int i = 0; i < NUM_CORE; i++)      
    {
        
        if (pre_req == deps[i].get_last_element())
        {
            dependencies_index = i;
        }
    }

    if (dependencies_index == -1)
    {
        return find_deps_count;
    }
  

    for (int j = 0; j < NUM_CORE; j ++)
    {
        bool found = false;
     
        pre_req = deps[j].find(pre_req, found);
        if ((j != dependencies_index && found) )
        {
            has_dep = true;
            break;
        }        
    }

    if (!has_dep)
    {
        for (int j = dependencies_index; j < NUM_CORE - 1; j++)
            deps[j] = deps[j+1];

        find_deps_count++;
    }
    else
    {
        find_deps_count--;
    }

    return find_deps_count;
    
}



// Function print_legitimate_permutations_in_file
// Input: array of Linked Lists
// Returns: void
// Does: Reads the filename line by line and stores each line in an array.
// When one line is finished being read in and stored in array, we loop 
// through the array and call find_deps for each course (each element in 
// array). If find_deps returns -1 we break out of the loop because this 
// means a dependency was found and we could not do a deletion in the 
// adjacency list. If find_deps returns something other than -1 we print it.
void print_legitimate_permutations_in_file(char *fname,
                                             LinkedList<string> dependencies[])
{
   
    LinkedList<string> dependencies_copy[NUM_CORE];

    for (int i = 0; i < NUM_CORE; i++)
    {
        dependencies_copy[i] = dependencies[i];
    }

    ifstream infile;
    infile.open(fname);
    if (!infile.is_open())
    {
        cerr << "Could not open input file for reading\n";
        exit(1);
    }

    while (!infile.eof())
    {       
        string courses[NUM_CORE];
        string line;
        int course_counter = 0;

        getline(infile, line);

        if (line == "-1")
            break;
        else if (course_counter < NUM_CORE)
        {
            stringstream ss(line);
            while (!ss.eof())
            {
                string tmp;
                ss >> tmp;
                if (tmp == "-1")
                    break;

                if (tmp.length() > 0)
                {
                    courses[course_counter]=tmp;
                    course_counter++;
                }
            }
            
        }

        LinkedList<string> dependencies_copy[NUM_CORE];

        for (int i = 0; i < NUM_CORE; i++)
        {
            dependencies_copy[i] = dependencies[i];
        }

        int find_deps_results;
        int find_deps_count = 0;

        for (int i = 0; i < NUM_CORE; i++)
        {        
            find_deps_results = find_deps(dependencies_copy, courses[i], 
                                                               find_deps_count);
            if (find_deps_results == -1)
            {
                break;
            }
        }
        
        if (find_deps_results != -1)
        {
            for (int i = 0; i < NUM_CORE; i++)
            {
                cout << courses[i] << " ";
            }  
            cout << endl; 
        }

    }

    infile.close();

}
