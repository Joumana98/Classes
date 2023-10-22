// Hearder file containing decalartions

#include "../std_lib_facilites.h"

class Date
{
public:

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

//-----------------------------------------------------------------------------------------------------------

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

bool operator== (const Book& b1, const Book& b2);
bool operator!= (const Book& b1, const Book& b2);
ostream& operator<< (ostream& os, const Book& b);

//-----------------------------------------------------------------------------------------------------------

class Patron
{
public:

	//Constructors
	Patron();
	Patron(string, int, double);

	//Accessors
	string getName() const;
	int getCardNumber() const;
	double getFees() const;

	//Mutators

	void setFees(double);


private:

	string name;
	int cardNumber;
	double fees;
};

bool checkIfOwed(const Patron& p);

//---------------------------------------------------------------------------------------------------------
struct Transaction
{
	Book b;
	Patron p;
	Date d;
};

class Library
{
public:

	class AbsentBook {};// to report erros
	class AbsentPatron {};
	class feeOwed {};


	//mutators
	void addBook(const Book&);
	void addPatron(const Patron&);
	void bookCheckout(Book&, const Patron& p, const Date& d);

	// accessors
	vector<Patron> owedPatrons() const;
	bool bookInLibrary(const Book&) const;
	bool patronInLibary(const Patron&) const;

private:
	vector <Book> books;
	vector <Patron> patrons;
	vector <Transaction> transactions;

};