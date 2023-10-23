#include "../std_lib_facilites.h"

const double MembershipFee = 10.0;
double MembershipDiscount = 0.05;

const int DiscNb = 11;

class memberType
{

public:
	// throw errors
	class Invalid {};

	//constructors
	memberType();
	memberType(string, int, int, double);

	// accessors
	string getName() const;
	int getID() const;
	int getBooksNb() const;
	double getAmount() const;
	void printInfo() const;

	//mutators
	void setName(string);
	void setID(int);
	void setBooks(int);
	void setAmount(double);
	void addBook(int, double);
	void removeBook(int, double);



private:
	string name;
	int memberID;
	int booksNb;
	double amountSpent;

};

class bookType
{
public:

	//throw error
	class Invalid {};

	//construtor
	bookType();
	bookType(string, const string[], int, string, int, double, int);

	//mutators
	void setTitle(string name);
	void setPublisher(string name);
	void setAuthor(string author);
	void setAuthorsNb(int n);
	void setISBN(int value);
	void setPrice(double p);
	void setCopies(int count);
	void addCopies(int nb);
	void subtractCopies(int nb);

	// accessors
	string getTitle() const;
	bool checkTitle(string name)const;
	int getAuthorsNb() const;
	string getAuthor(int index) const;
	string getPublisher() const;
	int getISBN() const;
	double getPrice() const;
	int getCopies() const;
	void printAuthors() const;

private:
	string title;
	string authors[4];
	int authorsNb;
	string publisher;
	int ISBN;
	double price;
	int copiesInStock;

};

int findBook(const bookType books[], string name);
int findMember(const memberType members[], int ID);
void addBook(bookType books[], int booksNb);
void addMember(memberType members[], int membersNb);


