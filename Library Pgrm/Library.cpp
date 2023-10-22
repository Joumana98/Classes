#include "Library.h"

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
	checked = false;
}
void Book::checkOut()
{
	checked = true;
}

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

//------------------------------------------------------------------------------------------------------------

Patron::Patron() : name{ "" }, cardNumber{ 0 }, fees{ 0.0 }
{

}

Patron::Patron(string pat, int card, double f)
{
	name = pat;
	cardNumber = card;
	fees = f;
}

string Patron::getName() const
{
	return name;

}
int Patron::getCardNumber() const
{
	return cardNumber;
}
double Patron::getFees() const
{
	return fees;
}

void Patron::setFees(double f)
{
	fees = f;
}

bool checkIfOwed(const Patron& p)
{
	if (p.getFees() > 0)
		return true;
	return false;
}

//-------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------

void Library::addBook(const Book& b)
{
	books.push_back(b);
}

void Library::addPatron(const Patron& p)
{
	patrons.push_back(p);
}

bool Library::bookInLibrary(const Book& b) const
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i] == b)
			return true;
	}
	return false;
}

bool Library::patronInLibary(const Patron& p) const
{
	//suppose that the card Number is unique of each user
	for (int i = 0; i < patrons.size(); i++)
	{
		if (patrons[i].getCardNumber() == p.getCardNumber())
			return true;
	}
	return false;
}


void Library::bookCheckout(Book& b, const Patron& p, const Date& d)
{
	// make sure that both user and the book are in library
	if (b.getChecked() == true || !bookInLibrary(b))
		throw AbsentBook{};
	if (!patronInLibary(p))
		throw AbsentPatron{};

	//make sure that the user owes no fee
	if (checkIfOwed(p))
		throw feeOwed{};

	//In case of no error, create a transaction and add it to the vector
	Transaction t = { b,p,d };
	transactions.push_back(t);
	b.checkOut();
	cout << "Book \"" << b.getTitle() << "\" is checked out." << endl;
}

vector<Patron> Library::owedPatrons() const
{
	vector<Patron> owers;
	for (int i = 0; i < patrons.size(); i++)
	{
		if (checkIfOwed(patrons[i]))
			owers.push_back(patrons[i]);
	}

	return owers;

}