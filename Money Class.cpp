#include "../../std_lib_facilites.h"

class money
{
public:
	//throw error
	class Invalid {};

	// constructors
	money();
	money(long int); // accept amounts in USD cents
	money(double, string); // accept amounts in a certain currency

	// accessors
	long int getCents() const;
	double getAmount() const;
	string getCurrency() const;
	double toDollars() const; // convert from cents to dollars
	void print(); //output in dollars

	money add(const money& m) const;
	money subtract(const money& m) const;

	//mutators
	void setCents(double); // input in any valid currency, converted to cents
	void setCurrency(string);

private:
	long int cents; // the amount is USD cents
	double amount; // the original amount
	string currency; // the original currency
};


istream& operator>> (istream& in, money& m)
{
	string cur;
	double val;
	in >> cur >> val;
	if (!in)
		return in;
	m = money{ val,cur };
	return in;
}

ostream& operator<< (ostream& out, money m)
{
	out << "USD " << m.toDollars();
	return out;


}

//---------------------------------------------------------------------------------------------------------

int main()
try {

	money m1;
	cout << "Enter the currency followed by the amount of money: ";
	cin >> m1;
	cout << "The amount in cents is: " << m1.getCents() << endl;
	cout << "The amount in dollars is: " << m1 << endl;

	cout << "Enter the currency followed by the amount of money: ";
	money m2;
	cin >> m2;
	cout << "The amount in cents is: " << m2.getCents() << endl;
	cout << "The amount in dollars is: ";
	m2.print();
	cout << endl;

	cout << endl;
	money sum = m1.add(m2);
	cout << "The sum of the two amounts of money is: " << sum << endl;

	cout << endl;
	money sub = m1.subtract(m2);
	cout << "The subtraction of the two amounts of money is: ";
	sub.print();
	cout << endl;

	return 0;
}
catch (money::Invalid)
{
	cerr << "Invalid amount of money." << endl;
	return 1;
}

//--------------------------------------------------------------------------------------------------------
money::money() : cents{ 0 }, amount{ 0 }, currency{ " " }
{

}

money::money(long int c)
{
	if (c < 0)
		throw Invalid{};
	cents = c;

	currency = "USD";
	amount = toDollars();
}

money::money(double val, string cur)
{
	setCurrency(cur);

	if (val < 0)
		throw Invalid{};
	amount = val;

	setCents(val);
}

void money::setCurrency(string cur)
{
	//most used currencies are allowed in this program
	// U.S.Dollar, Euro,Japanese Yen,Great British Pound, The Australian Dollar, Canadian Dollar
	if (cur != "USD" && cur != "EUR" && cur != "JPY" && cur != "GBP" && cur != "AUD" && cur != "CAD")
		throw Invalid{};
	currency = cur;
}

void money::setCents(double val)
{
	// convert to USD
	// 1 EUR = 1.05 USD
	// 1 JPY = 0.0066 USD
	// 1 GBP = 1.21 USD
	// 1 AUD = 0.63 USD
	// 1 CAD = 0.72 UDS

	double dollars;
	if (currency == "USD")
		dollars = val;
	else if (currency == "EUR")
		dollars = 1.05 * val;
	else if (currency == "JPY")
		dollars = 0.0066 * val;
	else if (currency == "GBP")
		dollars = 1.21 * val;
	else if (currency == "AUD")
		dollars = 0.63 * val;
	else if (currency == "CAD")
		dollars = 0.72 * val;

	// use the 4/5 rounding rule

	double c = dollars * 100;
	if (c - static_cast<long int> (c) >= 0.5)
		cents = static_cast<long int> (c) + 1;
	else
		cents = static_cast<long int> (c);
}

double money::toDollars() const
{
	return static_cast <double>(cents) / 100.0;
}

long int money::getCents() const
{
	return cents;
}
double money::getAmount() const
{
	return amount;
}

string money::getCurrency() const
{
	return currency;
}

void money::print()
{
	cout << "USD " << toDollars();
}

money money::add(const money& m) const
{
	// add any two amounts from any valid currencies
	return money{ cents + m.cents };
}

money money::subtract(const money& m) const
{
	// subtract any two amounts from any valid currencies
	return money{ abs(cents - m.cents) };
}