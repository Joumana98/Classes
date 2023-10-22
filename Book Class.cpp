#include "../../std_lib_facilites.h"

class Date
{
public:

	class Invalid {};
	class Invalid {};

	Date();
	Date(int yy, int mm, int dd);
	void is_valid(int yy, int mm, int dd);
	void printDate() const;
	int year() const;
	int month() const;
	int day() const;

private:
	int y;
	int m;
	int d;


};

enum class Genre
{
	fiction, nonfiction, periodial, biography, children, none
};


class Book
{
public:

	class InvalidISBN {};

	Book(); //default constructor
	Book(string, string, string, Date, bool, Genre); // Constructor

	//accessors
	string getISBN() const;
	string getTitle() const;
	string getAuthor() const;
	Date getCopyright() const;
	bool getChecked() const;
	Genre getGenre() const;
	void printInfo() const;

	//mutators
	void setInfo(string, string, string, Date, bool, Genre);
	void checkIn();
	void checkOut();

private:

	string ISBN;
	string title;
	string author;
	Date copyright;
	bool checked;
	Genre bookGenre;

	bool valid_ISBN(); // only called by member functions
	int getPart(string&, int);
	bool valid_part(const string& part);
};

bool operator== (const Book& b1, const Book& b2)
{
	if (b1.getISBN() == b2.getISBN())
		return true;
	else
		return false;
}

bool operator!= (const Book& b1, const Book& b2)
{
	if (!(b1 == b2))
		return true;
	else
		return false;
}

ostream& operator<< (ostream& os, const Book& b)
{
	os << "ISBN: " << b.getISBN() << endl;
	if (os)
		os << "Title: " << b.getTitle() << endl;
	else
		return os;
	if (os)
		os << "Author: " << b.getAuthor() << endl;
	return os;

}

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------

int main()
try {

	Book b1{ "5123-13-0-b","First Book","author 1",{2000,1,1},true,Genre::fiction };
	Book b2{ "5123-13-0-c","Second Book","author 2",{1998,5,7},false,Genre::children };

	cout << b1;
	cout << endl;
	cout << b2;

	cout << endl;
	if (b1 == b2)
		cout << "Books have the same ISBN." << endl;
	if (b1 != b2)
		cout << "Books have different ISBN." << endl;





	return 0;
}
catch (Date::Invalid)
{
	cerr << "Invalid date." << endl;
}

catch (Book::InvalidISBN)
{
	cerr << "Invalid ISBN" << endl;
}

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------

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

Date::Date() : y{ 0 }, m{ 0 }, d{}
{ }

Date::Date(int yy, int mm, int dd) : y{ yy }, m{ mm }, d{ dd }
{
	is_valid(yy, mm, dd);

}

void Date::printDate() const
{
	cout << y << " " << m << " " << d << endl;

}

int Date::year() const
{
	return y;
}

int Date::month() const
{
	return m;
}

int Date::day() const
{
	return d;
}

//------------------------------------------------------------------------------------------------------------

int Book::getPart(string& part, int index)
{
	char c = ISBN[index];

	int i = index + 1;
	while (c != '-' && i < ISBN.size())
	{
		part += c;
		c = ISBN[i];
		i++;

	}
	// string should be followed by -
	if (c != '-')
		throw InvalidISBN{};

	//cout << part << endl;

	return i;
}

bool Book::valid_part(const string& part)
{
	// checks if a string is an integer

	if (part.size() == 0)
		return false;

	for (int i = 0; i < part.size(); i++)
	{
		if (!isdigit(part[i]))
			return false;
	}

	return true;

}

bool Book::valid_ISBN()
{
	// form n-n-n-x where n:integer and x:digit or letter
	string n = "";
	int index = 0;
	for (int i = 0; i < 3; i++)
	{
		n = "";
		index = getPart(n, index);
		if (!valid_part(n))
			return false;
	}

	if (ISBN.size() - (index + 1) > 0)
		return false;

	char x = ISBN[index];
	//cout << x << endl;

	if (!isdigit(x) && !isalpha(x))
		return false;

	return true;
}

Book::Book(string isbn, string t, string auth, Date cr, bool c, Genre g)
{
	ISBN = isbn;
	if (valid_ISBN())
	{
		title = t;
		author = auth;
		copyright = cr;
		checked = c;
		bookGenre = g;
	}
	else
		throw InvalidISBN{};

}

const Book& default_book()
{
	static Book bb{ "","","",Date{0,0,0}, false,Genre::none };
	return bb;

}

Book::Book() : ISBN{ default_book().ISBN }, title{ default_book().title }, author{ default_book().author },
copyright{ default_book().copyright }, checked{ default_book().checked },
bookGenre{ default_book().bookGenre }

{

}

string Book::getISBN() const
{
	return ISBN;
}
string Book::getTitle() const
{
	return title;
}
string Book::getAuthor() const
{
	return author;
}
Date Book::getCopyright() const
{
	return copyright;
}
bool Book::getChecked() const
{
	return checked;
}
Genre Book::getGenre() const
{
	return bookGenre;
}
void Book::printInfo() const
{
	cout << "ISBN: " << ISBN << endl;
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Copyright date: ";
	copyright.printDate();
	cout << endl;
	cout << "Book is checked: " << checked << endl;
	cout << "Genre: " << int(bookGenre) << endl;

}

void Book::setInfo(string isbn, string t, string auth, Date cr, bool c, Genre g)
{
	ISBN = isbn;
	if (valid_ISBN())
	{
		title = t;
		author = auth;
		copyright = cr;
		checked = c;
		bookGenre = g;
	}
	else
		throw InvalidISBN{};

}

void Book::checkIn()
{
	checked = true;
}
void Book::checkOut()
{
	checked = false;
}