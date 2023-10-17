#include <iostream>

using namespace std;


class cashRegister
{
public:
	int getCurrentBalance() const;
	// Function to show the current amount in the cash regsiter
	// Postcondition: value of cashOnHand is returned

	void acceptAmount(int amountIn);
	// Function to accept money from customer and add it to the cash register
	// Postcndition: adds amountIn to cashOnHand

	cashRegister(int cashIn = 500);
	// Constructor: initializes the value of cashOnHand to the specified value
	// Postcondition: if no valur is specified, cashOnhan will be intialized to 500

private:
	int cashOnHand;
};

class dispenserType
{
public:
	int getNoOfItems() const;
	// Function to shown the number of items in the machine
	// Postcodtion: return numberOfItems
	int getCost() const;
	// Function that shows the cost of an item
	// Postcondition: returns cost
	void makeSale();
	// Function to reduce the number of items by 1
	// Postconditon: numberOfItems--;
	dispenserType(int setNo = 50, int setCost = 50);
	// Constructor: initializes the number of items and the cost to the given values
	// Postcondition: if no values are provided,the variables will be initialized to the default values

private:
	int numberOfItems;
	int cost;
};

//------------------------------------------------------------------------------------------------

void showSelection()
{
	cout << "***Welcome to the Candy Machine***" << endl;
	cout << "To select an item, enter " << endl;
	cout << "1 for Candy" << endl;
	cout << "2 for Chips" << endl;
	cout << "3 for Gum" << endl;
	cout << "4 for Cookies" << endl;
	cout << "9 to exit" << endl;
}

void sellProduct(dispenserType& product, cashRegister& pCounter)
{
	int amount;
	int amount2;

	if (product.getNoOfItems() == 0)
		cout << "Sorry, this item is sold out!" << endl;
	else
	{
		cout << "Please deposit " << product.getCost() << " cents." << endl;
		cin >> amount;
		if (amount < product.getCost())
		{
			cout << "You must deposit " << product.getCost() - amount << " cents" << endl;
			cin >> amount2;
			amount = amount + amount2 < product.getCost();
		}
		if (amount >= product.getCost())
		{
			pCounter.acceptAmount(product.getCost());
			product.makeSale();
			cout << "Collect your item at the bottom and enjoy!" << endl;

		}
		else
			cout << "The amount is not enough, collect what you deposited." << endl;
	}
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;

}

int main()
{

	cashRegister counter;
	dispenserType candy(100, 50);
	dispenserType chips(100, 65);
	dispenserType gum(75, 45);
	dispenserType cookies(100, 85);

	int choice;
	showSelection();
	cin >> choice;
	while (choice != 9)
	{
		switch (choice)
		{
		case 1:
			sellProduct(candy, counter);
			break;
		case 2:
			sellProduct(chips, counter);
			break;
		case 3:
			sellProduct(gum, counter);
			break;
		case 4:
			sellProduct(cookies, counter);
			break;
		default:
			cout << "Invalid selection!" << endl;
		}
		showSelection();
		cin >> choice;

	}


	return 0;
}

//--------------------------------------------------------------------------------------------

int cashRegister::getCurrentBalance() const
{
	return cashOnHand;
}

void cashRegister::acceptAmount(int amountIn)
{
	cashOnHand += amountIn;
}

cashRegister::cashRegister(int cashIn)
{
	if (cashIn >= 0)
		cashOnHand = cashIn;
	else
		cashOnHand = 500;
}

//--------------------------------------------------------------------------------------------

int dispenserType::getNoOfItems() const
{
	return numberOfItems;
}

int dispenserType::getCost() const
{
	return cost;
}

void dispenserType::makeSale()
{
	numberOfItems--;
}

dispenserType::dispenserType(int setNo, int setCost)
{
	if (setNo >= 0)
		numberOfItems = setNo;
	else
		numberOfItems = 50;

	if (setCost >= 0)
		cost = setCost;
	else
		cost = 50;
}
