#include <iostream>
using namespace std;

class Fraction
{
private:
	int numerator_;
	int denominator_;
	int arr[2] = { 0, 0 };
	void number(Fraction drob) {
		arr[0] = numerator_ * drob.denominator_;
		arr[1] = denominator_ * drob.numerator_;
	}
public:
	Fraction(int numerator, int denominator) {
		numerator_ = numerator;
		denominator_ = denominator;
	}

	bool operator == (Fraction drob) {
		number(drob);
		return arr[0] == arr[1];
	};

	bool operator != (Fraction drob) {
		return !(*this == drob);
	};

	bool operator < (Fraction drob) {
		number(drob);
		return arr[0] < arr[1];
	};

	bool operator > (Fraction drob) {
		number(drob);
		return arr[0] > arr[1];
	};

	bool operator <= (Fraction drob) {
		number(drob);
		return !(arr[0] > arr[1]);
	};

	bool operator >= (Fraction drob) {
		number(drob);
		return !(arr[0] < arr[1]);
	};
};


int main(){
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}