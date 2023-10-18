#include <iostream>

using namespace std;

class personType
{
public:
	void print() const;
	void setName(string, string, string);
	void setFirstName(string);
	void setMiddleName(string);
	void setLastName(string);
	string getFirstName() const;
	string getMiddleName() const;
	string getLastName() const;
	bool nameIsEqual(const personType& person) const;
	bool lastIsEqual(const personType& person) const;
	personType(string = "", string = "", string = "");


private:
	string firstName;
	string middleName;
	string lastName;
};

int main()
{
	string first, middle, last;
	cout << "Enter the full name of the first person: ";
	cin >> first >> middle >> last;
	personType person1(first, middle, last);

	cout << "Enter the full name of the second person: ";
	cin >> first >> middle >> last;
	personType person2(first, middle, last);

	if (person1.nameIsEqual(person2))
		cout << "The two persons have the same first name." << endl;
	if (person1.lastIsEqual(person2))
		cout << "The two persons have the same last name." << endl;

	return 0;
}

void personType::print() const
{
	cout << firstName << " " << middleName << " " << lastName;
}

void personType::setName(string first, string middle, string last)
{
	firstName = first;
	middleName = middle;
	lastName = last;
}

string personType::getFirstName() const
{
	return firstName;
}

string personType::getMiddleName() const
{
	return middleName;
}


string personType::getLastName() const
{
	return lastName;
}

personType::personType(string first, string middle, string last)
{
	firstName = first;
	middleName = middle;
	lastName = last;
}

void personType::setFirstName(string first)
{
	firstName = first;
}
void personType::setMiddleName(string middle)
{
	middleName = middle;
}

void personType::setLastName(string last)
{
	lastName = last;
}

bool personType::nameIsEqual(const personType& person) const
{
	if (firstName == person.firstName)
		return true;
	else
		return false;

}

bool personType::lastIsEqual(const personType& person) const
{
	if (lastName == person.lastName)
		return true;
	else
		return false;

}