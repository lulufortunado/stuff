#include "Pirate.h"

using namespace std;

const string FILE_SENT = "-1";

Pirate::Pirate()
{
	name = "";
}

Pirate::Pirate(string nameParam)
{
	name = nameParam;
}

string Pirate::get_name() const
{
	return name;
}

void Pirate::set_ID(int idParam)
{
	ID = idParam;
}

int Pirate::get_ID() const
{
	return ID;
}

int Pirate::getCount()
{
	return Counter<Pirate>::getCount();
}

void Pirate::generate_pirate_name(ifstream& infile, int listnum)
{
	string curr_pirate;
	int count = 0;


	while (infile >> curr_pirate && count < listnum - 1)
	{
		//infile >> curr_pirate;
		// Look for -1 sentinel
		if (curr_pirate != FILE_SENT)
		{
			count++;
		}
	}

	cout << "requested index: " << listnum << " pirate name: " << curr_pirate << endl;

	//infile.open(filename.c_str());
	// Error check
	// if (!infile.is_open())
	// {
	// 		return FAIL;
	// }
	//cout << "nameIndex: " << nameIndex << endl;

	//return 0;
}
// Pirate& Pirate::operator=( const Pirate& other ) {
// 	cout << "in overloaded assignment operator" << endl;
// 	name = other.name;
// 	cout << "name: " << name << endl;
// 	return *this;
// }
