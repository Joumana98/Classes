#include "../../std_lib_facilites.h"

class rational
{
public:
	// throw error
	class Invalid {};

	//constructors
	rational();
	rational(int, int);

	//accessors
	int getNumerator() const;
	int getDenominator() const;

	rational add(const rational&) const;
	rational subtract(const rational&) const;
	rational multiply(const rational&) const;
	rational divide(const rational&) const;
	bool isEqual(const rational&) const;
	double toDouble() const;

	void print() const;


	//mutators
	void assign(int, int);


private:
	void reduce();

	int numerator;
	int denominator;
};

//-----------------------------------------------------------------------------------------------------------

void printResult(const rational& r1, const rational& r2, char c)
{
	rational result;
	switch (c)
	{
	case '+':
		result = r1.add(r2);
		r1.print();
		cout << "+";
		r2.print();
		break;

	case '-':
		result = r1.subtract(r2);
		r1.print();
		cout << "-";
		r2.print();
		break;

	case '*':
		result = r1.multiply(r2);
		r1.print();
		cout << "*";
		r2.print();
		break;

	case '/':
		result = r1.divide(r2);
		r1.print();
		cout << "/";
		r2.print();
		break;

	default:
		cout << "Invalid Operation." << endl;
	}
	cout << "=" << result.toDouble() << endl;

}

//-----------------------------------------------------------------------------------------------------------

int main()
try {

	rational r1{ 5,6 };
	rational r2{ 5,10 };

	printResult(r1, r2, '+');
	printResult(r1, r2, '-');
	printResult(r1, r2, '*');
	printResult(r1, r2, '/');

	if (r1.isEqual(r2))
		cout << "The two rational numbers are equal." << endl;
	else
		cout << "The two rational numbers are not equal." << endl;

	return 0;
}
catch (rational::Invalid)
{
	cerr << "Invalid rational Number" << endl;
}

//---------------------------------------------------------------------------------------------------------

rational::rational() :numerator{ 0 }, denominator{ 1 }
{

}
rational::rational(int n, int d) :numerator{ n }, denominator{ d }
{
	if (d == 0)
		throw Invalid{};
}

void rational::assign(int n, int d)
{
	if (d == 0)
		throw Invalid{};
	numerator = n;
	denominator = d;

}

int rational::getNumerator() const
{
	return numerator;
}

int rational::getDenominator() const
{
	return denominator;
}

rational rational::add(const rational& r) const
{

	int com = denominator * r.denominator;
	int num = numerator * r.denominator + denominator * r.numerator;

	rational result{ num,com };
	result.reduce();
	return result;


}

rational rational::subtract(const rational& r) const
{
	int com = denominator * r.denominator;
	int num = numerator * r.denominator - denominator * r.numerator;

	rational result{ num,com };
	result.reduce();
	return result;
}

rational rational::multiply(const rational& r) const
{
	int com = denominator * r.denominator;
	int num = numerator * r.numerator;

	rational result{ num,com };
	result.reduce();
	return result;

}
rational rational::divide(const rational& r) const
{
	int com = denominator * r.numerator;
	int num = numerator * r.denominator;

	rational result{ num,com };
	result.reduce();
	return result;
}

bool rational::isEqual(const rational& r) const
{
	if (toDouble() == r.toDouble())
		return true;
	return false;

}

double rational::toDouble() const
{
	return static_cast<double> (numerator) / static_cast<double> (denominator);
}

void rational::print() const
{
	cout << numerator << "/" << denominator;
}


void rational::reduce()
{
	int min;
	if (numerator >= denominator)
		min = denominator;
	else
		min = numerator;
	for (int i = min; i > 1; i--)
	{
		if (numerator % i == 0 && denominator % i == 0)
		{
			numerator = numerator / i;
			denominator = denominator / i;
		}
	}
}
