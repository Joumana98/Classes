#include <iostream>
#include <string>

using namespace std;

class romanType
{
public:
	bool setRoman(char c);
	// Function to set the value of roman
	// PostCondition: roman=c
	char getRoman() const;
	// Function to return the valur of roman
	void romanToDecimal();
	// Function to convert the roman value and assign the corresponding value to decimal
	// Postcondition: decimal is set to the appropriate value according to romn value
	int getDecimal() const;
	// Function to return decimal
	void print() const;
	// Function to print Roman or decimal value according to the user request
	romanType(char = ' ', int = 0);
	// Constructor
	// Postcondition: If the values of roman and decimal are not specified, they are set to the default values
	// If the provided values of romn and decimal do not match, output the approprite error message

private:
	char roman;
	int decimal;

};

//------------------------------------------------------------------------------------------------------------

int main()
{
	romanType literal;
	string romanNumber;
	int decimalNumber = 0;
	int prev = 0;
	bool isValid = true;

	cout << "Enter a number in Roman literals." << endl;
	cin >> romanNumber;
	for (int i = romanNumber.size() - 1; i >= 0; i--)
	{
		isValid = literal.setRoman(romanNumber[i]);
		if (isValid == true)
		{
			// If a symbol is written after a larger symbol, it needs to be added to the larger symbol
			// If a symbol is written before a smaller symbol, it needs to be substracted from the larger symbol
			literal.romanToDecimal();
			if (literal.getDecimal() < prev)
				decimalNumber -= literal.getDecimal();
			else
			{
				decimalNumber += literal.getDecimal();
				prev = literal.getDecimal();
			}

		}
		else
			break;
	}
	if (isValid == true)
	{
		cout << "The Number entered is: " << romanNumber << endl;
		cout << "The equivalent number in decimal literals is: " << decimalNumber << endl;
	}

	return 0;
}
//--------------------------------------------------------------------------------------------------------
bool romanType::setRoman(char c)
{
	switch (c)
	{
	case 'M':
	case 'D':
	case 'C':
	case 'L':
	case 'X':
	case 'V':
	case 'I':
		roman = c;
		return true;
	default:
		cout << "Invalid Roman numeral" << endl;
		return false;
	}
}

char romanType::getRoman() const
{
	return roman;
}

void romanType::romanToDecimal()
{
	switch (roman)
	{
	case'M':
		decimal = 1000;
		break;
	case 'D':
		decimal = 500;
		break;
	case 'C':
		decimal = 100;
		break;
	case 'L':
		decimal = 50;
		break;
	case 'X':
		decimal = 10;
		break;
	case 'V':
		decimal = 5;
		break;
	case 'I':
		decimal = 1;
		break;
	}
}

int romanType::getDecimal() const
{
	return decimal;
}

void romanType::print() const
{
	char c;
	cout << "To print Roman Literal, enter r or R. To print Decimal Literal, enter d or D" << endl;
	cin >> c;
	switch (c)
	{
	case 'r':
	case 'R':
		cout << roman << endl;
	case 'd':
	case 'D':
		cout << decimal << endl;
	default:
		cout << "Invalid input" << endl;
	}
}


romanType::romanType(char c, int d)
{
	if (c != ' ')
	{
		setRoman(c);
		romanToDecimal();
		if (d != decimal)
			cout << "Imcompatible roman and decimal numerals." << endl;
	}
	else
		d = 0;
}