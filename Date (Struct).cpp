#include "../../std_lib_facilites.h"

struct Date
{
	int y;
	int m;
	int d;
	class Invalid {};
	Date(int yy, int mm, int dd);// guarantee initialization with constructor, check for validity as well
	void is_valid(int yy, int mm, int dd);
	Date add_day(const Date& day);


};

void Date::is_valid(int yy, int mm, int dd)
{
	// check for year
	if (yy <= 0)
		throw Invalid{};

	// check for month
	if (mm <= 0 || mm > 12)
		throw Invalid{};

	// check for day
	if (dd <= 0)
		throw Invalid{};

	int day_in_month = 31;
	switch (mm)
	{
	case 2:
		day_in_month = 28; // ignore leap year where number of days in feb is 29
	case 4:
	case 6:
	case 9:
	case 11:
		day_in_month = 30;
		break;
	}
	if (dd > day_in_month)
		throw Invalid{};
}

Date::Date(int yy, int mm, int dd) : y{ yy }, m{ mm }, d{ dd }
{
	is_valid(yy, mm, dd);

}

Date Date::add_day(const Date& day)
{
	Date next = day;

	int max = 31;
	switch (day.m)
	{
	case 2:
		max = 28; // ignore leap year where number of days in feb is 29
	case 4:
	case 6:
	case 9:
	case 11:
		max = 30;
		break;
	}

	if (day.d == max)
	{
		next.d = 1;
		next.m++;
	}
	else
		next.d++;

	if (next.m > 12)
	{
		next.m = 1;
		next.y++;
	}

	is_valid(next.y, next.m, next.d);
	return next;


}

int main()
try {
	Date today{ 1978,11,32 };

	Date tomorrow = today;
	tomorrow = tomorrow.add_day(tomorrow);

	cout << "Today: " << today.y << " " << today.m << " " << today.d << endl;
	cout << "Tomorrow: " << tomorrow.y << " " << tomorrow.m << " " << tomorrow.d << endl;

	return 0;
}
catch (Date::Invalid)
{
	cerr << "Invalid date";
}