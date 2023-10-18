// Exercise 2 & 3

#include <iostream>
#include <string>

using namespace std;

class dayType
{
public:
	bool setDay(string d);
	void printDay() const;
	string getDay() const;
	dayType nextDay() const;
	dayType prevDay() const;
	dayType calculateDay(int d) const;
	dayType(string = " ");

private:
	string day;
};

//----------------------------------------------------------------------------------------------------------

int main()
{
	dayType current;
	string d;

	cout << "Enter the current day: ";
	cin >> d;
	if (current.setDay(d))

	{
		cout << endl;
		cout << "The current day is: ";
		current.printDay();
		cout << endl;

		cout << "The next day is: ";
		dayType next = current.nextDay();
		next.printDay();
		cout << endl;

		cout << "The previous day is: ";
		dayType prev = current.prevDay();
		prev.printDay();
		cout << endl;

		int n;
		cout << "Enter an integer: " << endl;
		cin >> n;
		dayType fut = current.calculateDay(n);
		cout << "After " << n << " days, it'll be ";
		fut.printDay();
		cout << endl;
	}

	return 0;
}

//-----------------------------------------------------------------------------------------------------------

bool dayType::setDay(string d)
{
	bool isValid = true;
	if (d == "mon" || d == "Mon" || d == "Monday")
	{
		day = "Mon";
		return isValid;
	}

	else if (d == "tue" || d == "Tue" || d == "Tuesday")
	{
		day = "Tue";
		return isValid;
	}
	else if (d == "wed" || d == "Wed" || d == "Wednesday")
	{
		day = "Wed";
		return isValid;
	}
	else if (d == "thu" || d == "Thu" || d == "Thursday")
	{
		day = "Thu";
		return isValid;
	}
	else if (d == "fri" || d == "Fri" || d == "Friday")
	{
		day = "Fri";
		return isValid;
	}
	else if (d == "sat" || d == "Sat" || d == "Saturday")
	{
		day = "Sat";
		return isValid;
	}
	else if (d == "sun" || d == "Sun" || d == "Sunday")
	{
		day = "Sun";
		return isValid;
	}
	else
	{
		isValid = false;
		cout << "Invalid Input!" << endl;
		return isValid;
	}
}


void dayType::printDay() const
{
	cout << day << endl;
}


string dayType::getDay() const
{
	return day;
}

dayType::dayType(string d)
{
	if (d != " ")
		setDay(d);

}

dayType dayType::nextDay() const
{
	if (day == "Mon")
		return dayType("Tue");

	else if (day == "Tue")
		return dayType("Wed");

	else if (day == "Wed")
		return dayType("Thu");

	else if (day == "Thu")
		return dayType("Fri");

	else if (day == "Fri")
		return dayType("Sat");

	else if (day == "Sat")
		return dayType("Sun");

	else if (day == "Sun")
		return dayType("Mon");

}


dayType dayType::prevDay() const
{
	if (day == "Mon")
		return dayType("Sun");

	else if (day == "Tue")
		return dayType("Mon");

	else if (day == "Wed")
		return dayType("Tue");

	else if (day == "Thu")
		return dayType("Wed");

	else if (day == "Fri")
		return dayType("Thu");

	else if (day == "Sat")
		return dayType("Fri");

	else if (day == "Sun")
		return dayType("Sat");

}

dayType dayType::calculateDay(int d) const
{
	dayType next = dayType(day);
	for (int i = 0; i < d; i++)
		next = next.nextDay();

	return next;
}