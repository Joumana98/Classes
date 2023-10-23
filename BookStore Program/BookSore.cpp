#include "../std_lib_facilites.h"
#include "BookStore.h"

memberType::memberType() : name{ "" }, memberID{ 0 }, booksNb{ 0 }, amountSpent{ 0 }
{

}

memberType::memberType(string n, int ID, int b, double amount)
	:name{ n }, memberID{ ID }, booksNb{ b }, amountSpent{ amount }
{
	if (b < 0 || ID < 0 || amount < 0)
		throw Invalid{};
}

string memberType::getName() const
{
	return name;
}

int memberType::getID() const
{
	return memberID;
}

int memberType::getBooksNb() const
{
	return booksNb;
}

double memberType::getAmount() const
{
	return amountSpent;
}

void memberType::printInfo() const
{
	cout << "Name: " << name << endl;
	cout << "ID: " << memberID << endl;
	cout << "Number of books bought: " << booksNb << endl;
	cout << "Amount spent: " << amountSpent << endl;
}

void memberType::setName(string n)
{
	name = n;
}

void memberType::setID(int ID)
{
	if (ID >= 0)
		memberID = ID;
	else
		throw Invalid{};

}

void memberType::setBooks(int b)
{
	if (b >= 0)
		booksNb = b;
	else
		throw Invalid{};

}
void memberType::setAmount(double amount)
{
	if (amount >= 0)
		amountSpent = amount;
	else
		throw Invalid{};

}
void memberType::addBook(int b, double amount)
{
	if (b >= 0)
		booksNb += b;
	else
		throw Invalid{};
	if (amount >= 0)
		amountSpent += amount;
	else
		throw Invalid{};
}
void memberType::removeBook(int b, double amount)
{
	if (b >= 0 && b <= booksNb)
		booksNb -= b;
	else
		throw Invalid{};
	if (amount >= 0 && amount <= amountSpent)
		amountSpent -= amount;
	else
		throw Invalid{};
}

//------------------------------------------------------------------------------------------------------------

bookType::bookType() : title{ "" }, authorsNb{ 0 }, publisher{ "" }, ISBN{ 0 }, price{ 0 }, copiesInStock{ 0 }
{
	for (int i = 0; i < 4; i++)
		authors[i] = "";
}

bookType::bookType(string name, const string auth[], int nb, string pub, int isbn, double p, int cp)
	:title{ name }, authorsNb{ nb }, publisher{ pub }, ISBN{ isbn }, price{ p }, copiesInStock{ cp }
{
	for (int i = 0; i < 4; i++)
		authors[i] = auth[i];
	if (nb < 0 || isbn < 0 || p < 0 || cp < 0)
		throw Invalid{};
}


void bookType::setTitle(string name)
{
	title = name;
}

string bookType::getTitle() const
{
	return title;
}

bool bookType::checkTitle(string name)const
{
	if (title == name)
		return true;
	else
		return false;
}

void bookType::setAuthorsNb(int n)
{
	if (n > 0)
		authorsNb = n;
	else
		throw Invalid{};
}

void bookType::setAuthor(string author)
{
	if (authorsNb < 4)
	{
		authors[authorsNb] = author;
		authorsNb++;
	}
	else
	{
		cout << "The maximun number of authors allowed is 4." << endl;
		throw Invalid{};
	}

}
int bookType::getAuthorsNb() const
{
	return authorsNb;
}

string bookType::getAuthor(int index) const
{
	if (index < 4)
		return authors[index];
	else
	{
		cout << "Index out of range" << endl;
		throw Invalid{};
	}
}

void bookType::printAuthors() const
{
	for (int i = 0; i < authorsNb; i++)
		cout << authors[i] << " ";
	cout << endl;
}

void bookType::setPublisher(string name)
{
	publisher = name;
}

string bookType::getPublisher() const
{
	return publisher;
}

void bookType::setISBN(int value)
{
	if (value >= 0)
		ISBN = value;
	else
	{
		cout << "Invalid ISBN" << endl;
		throw Invalid{};
	}

}

int bookType::getISBN() const
{
	return ISBN;
}

void bookType::setPrice(double p)
{
	if (p >= 0)
		price = p;
	else
		throw Invalid{};
}

double bookType::getPrice() const
{
	return price;
}

void bookType::setCopies(int count)
{
	if (count >= 0)
		copiesInStock = count;
	else
	{
		cout << "Invalid number of copies!" << endl;
		throw Invalid{};
	}
}

int bookType::getCopies() const
{
	return copiesInStock;
}

void bookType::addCopies(int nb)
{
	if (nb >= 0)
		copiesInStock += nb;
	else
		throw Invalid{};
}
void bookType::subtractCopies(int nb)
{
	if (nb >= 0 && nb <= copiesInStock)
		copiesInStock -= nb;
	else
		throw Invalid{};
}
//--------------------------------------------------------------------------------------------------------------

//helper functions

int findBook(const bookType books[], string name)
{
	for (int i = 0; i < 1000; i++)
	{
		if (books[i].getTitle() == name)
			return i;
	}
	return -1;
}

int findMember(const memberType members[], int ID)
{
	for (int i = 0; i < 500; i++)
	{
		if (members[i].getID() == ID)
			return i;
	}
	return -1;
}

void addBook(bookType books[], int booksNb)
{
	cin.ignore();
	string btitle;
	cout << "Enter the title:";
	getline(cin, btitle);
	books[booksNb].setTitle(btitle);

	int authorsNo;
	cout << "Enter the number of authors of this book: ";
	cin >> authorsNo;
	if (authorsNo > 4)
	{
		cout << "The numer of authors should not exceed 4!";
		throw bookType::Invalid{};
	}

	string bAuthors[4];
	string name;
	cin.ignore();
	for (int i = 0; i < authorsNo; i++)
	{
		books[booksNb].setAuthorsNb(i + 1);
		cout << "Enter the name of author " << i + 1 << " : ";
		getline(cin, name);
		books[booksNb].setAuthor(name);
	}

	string publish;
	cout << "Enter the name of the publisher:";
	getline(cin, publish);
	books[booksNb].setPublisher(publish);

	int iSBN;
	cout << "Enter ISBN:";
	cin >> iSBN;
	books[booksNb].setISBN(iSBN);

	double price;
	cout << "Enter the book's price:";
	cin >> price;
	books[booksNb].setPrice(price);

	int copies;
	cout << "Enter the available number of copies:";
	cin >> copies;
	books[booksNb].setCopies(copies);

}

void addMember(memberType members[], int membersNb)
{
	memberType m;

	string n;
	cin.ignore();
	cout << "Enter the member's name: " << endl;
	getline(cin, n);
	m.setName(n);

	int ID;
	cout << "Enter the member's ID: " << endl;
	cin >> ID;
	m.setID(ID);

	int b;
	cout << "Enter the number of books purchased: " << endl;
	cin >> b;
	m.setBooks(b);

	double amount;
	cout << "Enter the amount spent: " << endl;
	cin >> amount;
	m.setAmount(MembershipFee + amount);

	members[membersNb] = m; //copy constructor;

}
