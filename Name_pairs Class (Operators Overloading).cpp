// Exercise 3 & 4

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
	vector<string> getNames() const;
	vector<double> getAges() const;



private:

	vector <string> name;
	vector <double> age;

	int findIndex(string, vector<string>); // only accessed by another member function
};

ostream& operator<< (ostream& os, const Name_pairs& list)
{
	vector <string> tempName = list.getNames();
	vector <double> tempAge = list.getAges();

	for (int i = 0; i < tempName.size(); i++)
		os << "(" << tempName[i] << "," << tempAge[i] << ")" << endl;

	return os << endl;

}

bool operator== (const Name_pairs& first, const Name_pairs& sec)
{
	vector<string> fNames = first.getNames();
	vector<string> sNames = sec.getNames();

	vector<double> fAges = first.getAges();
	vector<double> sAges = sec.getAges();

	if (fNames.size() != sNames.size())
		return false;
	for (int i = 0; i < fNames.size(); i++)
	{
		if (fNames[i] != sNames[i] || fAges[i] != sAges[i])
			return false;
	}

	return true;

}

bool operator!= (const Name_pairs& first, const Name_pairs& sec)
{
	if (!(first == sec))
		return true;
	return false;
}

int main()
{
	Name_pairs list;
	list.read_names();
	list.read_ages();
	cout << "Before sorting: " << endl;
	cout << list;

	cout << endl;
	list.sortPairs();
	cout << "After sorting: " << endl;
	cout << list;

	Name_pairs list2;
	list2.read_names();
	list2.read_ages();
	if (list == list2)
		cout << "Same Name_pairs" << endl;
	if (list != list2)
		cout << "Different Name_pairs" << endl;

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

vector<string> Name_pairs::getNames() const
{
	return name;
}
vector<double> Name_pairs::getAges() const
{
	return age;
}