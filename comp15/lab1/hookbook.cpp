//Effie Kazakos
// January 23
// Comp 15
// Lab1
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Pirate.h"
#include "ArrayList.h"

int main()
{
  Pirate pirate1("Pirate 1");
  Pirate pirate2("Pirate 2");
  Pirate pirate3("Pirate 3");
  Pirate pirate4("Pirate 4");
  Pirate pirate5("Pirate 5");

  ArrayList pArrayList;

  pArrayList.insert_pirate(pirate1);
  pArrayList.insert_pirate(pirate2);
  pArrayList.insert_pirate(pirate3);
  pArrayList.insert_pirate(pirate4);
  pArrayList.insert_pirate(pirate5);

  pArrayList.print();

  ifstream fin;
  fin.open("pirate_names.txt");
  
  if(fin.fail())
    {
      cerr << "failure opening file";   
    }

  for(int i=0; i< 200; i++)
  {
    if(pArrayList.is_full())
    {
    	 break;
    }
    Pirate pirate;
    pirate.generate_pirate_name(fin, 698);
    pirate.assign_pirate_id();
    pirate.print();
    pArrayList.insert_pirate(pirate);
  }
  cout << endl;
  cout << "printing full list: " << endl;
  pArrayList.print();

  return 0;
}
