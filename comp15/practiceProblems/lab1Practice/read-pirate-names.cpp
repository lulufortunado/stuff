#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Read a list of pirate names from a file, store in array
// Write an updated list of pirates FROM array to file
int read_pirates(string, string []);
int write_pirates(string, string, string [], int);
void print_pirates(string [], int);

const int MAX_PIRATES = 10;
const int FAIL = -1;
const string FILE_SENT = "-1";

int main()
{
    // Variables for filename and list of pirates
    string filename;
    string pirates[MAX_PIRATES];

    // Prompt user for filename
    cout << "What is the name of your pirate name file?\n";
    cin >> filename;

    // Call function to open, read, return # pirates
    int num_pirates = read_pirates(filename, pirates);
    cout << "num_pirates: " << num_pirates <<endl;

    if (num_pirates == FAIL)
    {
        cerr << "Error reading file\n";
        return FAIL;
    }
    print_pirates(pirates, num_pirates);

    return 0;
}

// Function to read a list of pirates from a file
// Input: filename, array of pirates
// Returns: number of pirates found
// Does: opens the input file, reads pirates
//   stores each pirates in the given array
int read_pirates(string filename, string pirates[])
{
    ifstream infile;
    infile.open(filename.c_str()); // C-style string required

    // Error check
    if (!infile.is_open())
    {
        return FAIL;
    }

    // Declare an array of pirates that we'll store file data in
    string curr_pirate;
    int count = 0;

    // Iterate through the file, populating the array as we go
    // We don't know how many pirates are in the file, so use a while loop
    while (!infile.eof())
    {
        infile >> curr_pirate;
        // Look for -1 sentinel
        if (curr_pirate != FILE_SENT)
        {
            pirates[count++] = curr_pirate;
        }
    }

    // Close the input file
    infile.close();

    // Return the number of pirates we read in
    return count;
}

// Function print_pirates
// Print all pirates in the given string array
void print_pirates(string pirates[], int count)
{
    cout << "There are " << count << " pirates\n";
    for (int i = 0; i < count; i++)
        cout << pirates[i] << endl;
}
