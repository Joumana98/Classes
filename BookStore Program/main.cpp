#include "../std_lib_facilites.h"
#include "BookStore.h"


int main()
try {

	// add books in the book store
	bookType books[1000];
	int booksNumber = 0;

	string addB;
	cout << "To enter a new book, enter \"add\": " << endl;
	cin >> addB;
	while (addB == "add" && booksNumber < 1000)
	{
		addBook(books, booksNumber);

		booksNumber++;
		cout << "To enter a new book, enter \"add\": " << endl;
		cin >> addB;
	}
	cout << endl;

	// add members to the book store

	memberType members[500];
	int membersNb = 0;

	string addM;
	cout << "To enter a new member, enter \"add\": " << endl;
	cin >> addM;
	while (addM == "add" && membersNb < 500)
	{
		addMember(members, membersNb);

		membersNb++;
		cout << "To enter a new member, enter \"add\": " << endl;
		cin >> addM;
	}

	// purchase operation

	int ID;
	bool isMember = false;
	int i = 0;

	cout << "If you are a member, enter your membership ID, otherwise enter -1." << endl;
	cin >> ID;
	if (ID != -1) {
		i = findMember(members, ID);
		if (i != -1)
			isMember = true;
		else
			cout << "Membership ID is not found!" << endl;
	}

	bool purchase;
	double bill = 0.0;
	double discount = MembershipDiscount;
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
		}
		else
			cout << "Book is not found!" << endl;

		bool buy;
		if (books[index].getCopies() > 0)
		{
			cout << "Enter 1 to purchase a copy of this book, and 0 otherwise." << endl;
			cin >> buy;
			if (buy == 1)
				books[index].subtractCopies(1);
		}

		//update bill

		if (isMember == true)
		{
			members[i].setBooks(members[i].getBooksNb() + 1); // update the number of books purchased

			if (members[i].getBooksNb() < DiscNb)
				bill = bill + books[index].getPrice() * (1 - discount); // get 5% discount on each book

			else if (members[i].getBooksNb() == DiscNb) // member purchased 11 books
			{
				discount = bill * 0.1;// update the discount rate
				members[i].setBooks(0); // update the number of books purchased
				bill = 0; // reset the amount spent
			}
			members[i].setAmount(bill);
		}
		else
			bill += books[index].getPrice();


		cout << endl;
		cout << "To purchase a book, enter 1. Otherwise, enter 0:";
		cin >> purchase;
	}

	// Display the final bill
	cout << "The total bill is " << bill << endl;

	return 0;
}
catch (memberType::Invalid)
{
	cerr << "Invalid Input for memberType" << endl;
}

catch (bookType::Invalid)
{
	cerr << "Invalid Input for bookType" << endl;
}
