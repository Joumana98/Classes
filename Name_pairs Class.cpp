#include "../../std_lib_facilites.h"

class Name_pairs
{
public:

	class Invalid {}; // used to throw errors

	// No need for constructor, by default the vectors are empty

	//mutators
	void read_names(); // read a series of names
	void read_ages(); // promts the user to enter an age for each name
	void sortPairs(); // sorts names in alphabetical order and reorganizes tha age vector


	// accessors
	void print() const; // prints out one pair per line in the orer determined by the name vector



private:

	vector <string> name;
	vector <double> age;

	int findIndex(string, vector<string>); // only accessed by another member function
};

int main()
{
	Name_pairs list;
	list.read_names();
	list.read_ages();
	cout << "Before sorting: " << endl;
	list.print();

	cout << endl;
	list.sortPairs();
	cout << "After sorting: " << endl;
	list.print();

	return 0;
}


void Name_pairs::read_names()
{
	string n;
	cout << "Enter a set of names. To finish input, enter \"|\": ";
	cin >> n;
	while (n != "|")
	{
		name.push_back(n);
		cin >> n;
	}
	cout << endl;
}

void Name_pairs::read_ages()
{
	double a;
	for (int i = 0; i < name.size(); i++)
	{
		cout << "Enter " << name[i] << "\'s age: ";
		cin >> a;
		age.push_back(a);
	}
	cout << endl;

}

int Name_pairs::findIndex(string name, vector<string> sorted)
{
	for (int i = 0; i < sorted.size(); i++)
	{
		if (sorted[i] == name)
			return i;
	}
}

void Name_pairs::sortPairs()
{
	// sort name
	vector<string> prev = name;
	sort(name.begin(), name.end());

	// sort age
	int curP;
	int prevP;
	vector<double> prevAge = age;

	for (int i = 0; i < prev.size(); i++)
	{
		prevP = i;
		curP = findIndex(prev[i], name);
		age[curP] = prevAge[prevP];
	}
}




void Name_pairs::print() const
{
	for (int i = 0; i < name.size(); i++)
		cout << "(" << name[i] << "," << age[i] << ")" << endl;
}