#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "ArrayList.h"

using namespace std;

const int FAIL = -1;

int main()
{
  //string filename;

  Pirate pirate1;
  cout << "declared one pirate" << endl;
  cout << "pirate count: " << pirate1.getCount() << endl;
  Pirate pirate2("Madame Cheng");
  cout << "declared second pirate" << endl;
  cout << "pirate1 count: " << pirate1.getCount() << endl;
  cout << "pirate2 count: " << pirate2.getCount() << endl;
  Pirate pirate3("Pirate 3");
  ArrayList array_list1;

  array_list1.insert_pirate(pirate1);
  array_list1.insert_pirate(pirate2);
  array_list1.insert_pirate(pirate3);

  cout << "pirate1 count: " << pirate1.getCount() << endl;
  cout << "pirate2 count: " << pirate2.getCount() << endl;
  cout << "pirate3 count: " << pirate3.getCount() << endl;

  //Prompt user for filename
  //cout << "What is the name of your pirate name file?\n";
  //cin >> filename;

  ifstream fin;
  //fin.open(filename.c_str()); // C-style string required
  fin.open("pirate-names.txt");

  // Error check
  if (fin.fail())
  {
      return FAIL;
  }
  else
  {
    Pirate pirate3;
    pirate3.generate_pirate_name(fin, 2);
    fin.close();
  }

  return 0;
}
