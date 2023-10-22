#include "../../std_lib_facilites.h"
#include "../../Ch3/Library.h"

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

	string name;
	int number;
	double fees;

	cout << "Enter Patron's name: " << endl;
	getline(cin, name);
	cout << "Enter his card Number: " << endl;
	cin >> number;
	cout << "Enter his owed fees: " << endl;
	cin >> fees;

	Patron p{ name,number,fees };
	Patron p2{ "John",2,0 };

	Library L1;
	L1.addBook(b1);
	L1.addBook(b2);
	L1.addPatron(p);
	L1.addPatron(p2);


	//L1.bookCheckout(b1, p, { 2023,12,12 });
	L1.bookCheckout(b2, p, { 2023,12,12 });
	L1.bookCheckout(b2, p2, { 2023,12,13 });

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

catch (Library::AbsentBook)
{
	cerr << "Absent Book" << endl;
}

catch (Library::AbsentPatron)
{
	cerr << "Absent Patron" << endl;
}

catch (Library::feeOwed)
{
	cerr << "Patron owes fees" << endl;
}

