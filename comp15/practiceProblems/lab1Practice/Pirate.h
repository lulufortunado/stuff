#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Counter.h"

using namespace std;

#ifndef PIRATE_H_
#define PIRATE_H_

class Pirate {
	public:
		Pirate();
		Pirate( string name );
		//Assignment operator
    //Pirate& operator=(const Pirate& p);
		string get_name() const;
		int get_ID() const;
		void set_ID(int id);
		static int getCount();
		void generate_pirate_name(ifstream& infile, int listnum );

	private:
		Counter<Pirate> counter;
		string name;
		int ID;
};

#endif
