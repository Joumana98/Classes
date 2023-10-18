#include <iostream>
#include <string>

using namespace std;

class bookType
{
public:
	void setTitle(string name);
	string getTitle() const;
	bool checkTitle(string name)const;
	void setAuthor(string author);
	void setAuthorsNb(int n);
	int getAuthorsNb() const;
	string getAuthor(int index) const;
	void printAuthors() const;
	void setPublisher(string name);
	string getPublisher() const;
	void setISBN(int value);
	int getISBN() const;
	void setPrice(double p);
	double getPrice() const;
	void setCopies(int count);
	int getCopies() const;
	void addCopies(int nb);
	void subtractCopies(int nb);
	bookType();

private:
	string title;
	string authors[4];
	int authorsNb;
	string publisher;
	int ISBN;
	double price;
	int copiesInStock;

};

//-----------------------------------------------------------------------------------------------------------

int findBook(const bookType books[], string name)
{
	for (int i = 0; i < 100; i++)
	{
		if (books[i].getTitle() == name)
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

int main()
{
	bookType books[100];
	int booksNumber = 0;

	string addB;
	cout << "To enter a new book, enter \"add\": " << endl;
	cin >> addB;
	while (addB == "add" && booksNumber < 100)
	{
		addBook(books, booksNumber);

		booksNumber++;
		cout << "To enter a new book, enter \"add\": " << endl;
		cin >> addB;
	}

	bool purchase;
	double bill = 0.0;
	cout << "To purchase a book, enter 1. Otherwise, enter 0:";
	cin >> purchase;

	while (purchase)
	{
		string bookTitle;
		cout << "Enter a book title: ";
		cin >> bookTitle;
		int index = findBook(books, bookTitle);
		if (index != -1)
		{
			cout << "There are " << books[index].getCopies() << " copies of this book" << endl;
			cout << "Its price is " << books[index].getPrice() << endl;
			cout << "The names of authors:";
			books[index].printAuthors();
			cout << "The publisher is: " << books[index].getPublisher() << endl;
			cout << "ISBN= " << books[index].getISBN() << endl;
		}
		else
			cout << "Book is not found!" << endl;

		bool buy;
		double cBill = 0.0;
		if (books[index].getCopies() > 0)
		{
			cout << "Enter 1 to purchase copies of this book, and 0 otherwise." << endl;
			cin >> buy;
			if (buy == 1)
			{
				int nb;
				cout << "Enter the number of copies you want to buy." << endl;
				cin >> nb;
				if (nb <= books[index].getCopies())
					books[index].subtractCopies(nb);
				else
				{
					cout << "Only " << books[index].getCopies() << " are available and will be sold to you." << endl;
					nb = books[index].getCopies();
				}
				cBill = nb * books[index].getPrice();
			}
		}

		bill += cBill;

		cout << endl;
		cout << "To purchase a book, enter 1. Otherwise, enter 0:";
		cin >> purchase;
	}
	cout << endl;
	cout << "The total bill is " << bill << endl;

	return 0;
}

//-----------------------------------------------------------------------------------------------------------

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
		cout << "Invalid number of authors." << endl;
}

void bookType::setAuthor(string author)
{
	if (authorsNb < 4)
	{
		authors[authorsNb] = author;
		authorsNb++;
	}
	else
		cout << "The maximun number of authors allowed is 4." << endl;

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
		cout << "Index out of range" << endl;
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
	ISBN = value;
}

int bookType::getISBN() const
{
	return ISBN;
}

void bookType::setPrice(double p)
{
	price = p;
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
		cout << "Invalid number of copies!" << endl;
}

int bookType::getCopies() const
{
	return copiesInStock;
}

void bookType::addCopies(int nb)
{
	copiesInStock += nb;
}
void bookType::subtractCopies(int nb)
{
	copiesInStock -= nb;
}
bookType::bookType()
{
	title = "";
	for (int i = 0; i < 4; i++)
		authors[i] = "";
	authorsNb = 0;
	publisher = "";
	ISBN = 0;
	price = 0;
	copiesInStock = 0;
}