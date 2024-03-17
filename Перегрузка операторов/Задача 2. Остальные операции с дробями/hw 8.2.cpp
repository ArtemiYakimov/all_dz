#include <iostream>
#include <Windows.h>

using namespace std;

class Fraction {
private:
	int numerator_;
	int denominator_;
	int arr[2] = { 0, 0 };
	void number(Fraction drob) {
		arr[0] = numerator_ * drob.denominator_;
		arr[1] = denominator_ * drob.numerator_;
	}
	int mini(int a, int b) {
		if (a == b) {
			return a;
		}
		a > b ? mini(a - b, b) : mini(a, b - a);
	}

	Fraction non() {
		int a = numerator_ > 0 ? numerator_ : (numerator_ * (-1));
		int b = denominator_ > 0 ? denominator_ : (denominator_ * (-1));
		int c = mini(a, b);
		return Fraction(numerator_ / c, denominator_ / c);
	}
public:
	Fraction(int numerator, int denominator) {
		numerator_ = numerator;
		denominator_ = denominator;
	}

	Fraction operator + (Fraction drob) {
		int q = numerator_ * drob.denominator_ + drob.numerator_ * denominator_;
		int z = denominator_ * drob.denominator_;
		return Fraction(q, z).non();
	};

	Fraction operator - (Fraction drob) {
		int q = numerator_ * drob.denominator_ - drob.numerator_ * denominator_;
		int z = denominator_ * drob.denominator_;
		return Fraction(q, z).non();
	};

	Fraction operator * (Fraction drob) {
		int q = numerator_ * drob.numerator_;
		int z = denominator_ * drob.denominator_;
		return Fraction(q, z).non();
	};

	Fraction operator / (Fraction drob) {
		int q = numerator_ * drob.denominator_;
		int z = denominator_ * drob.numerator_;
		return Fraction(q, z).non();
	};

	Fraction& operator ++ () {
		numerator_ = numerator_ + denominator_;
		return *this;
	};

	Fraction& operator ++ (int) {
		Fraction drob = *this;
		(*this).numerator_ = numerator_ + denominator_;
		return drob;
	};

	Fraction& operator -- () {
		numerator_ = numerator_ - denominator_;
		return *this;
	};

	Fraction& operator -- (int) {
		Fraction drob = *this;
		(*this).numerator_ = numerator_ - denominator_;
		return drob;
	};

	int get_num() {
		return this->numerator_;
	};
	int get_den() {
		return this->denominator_;
	};
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a, b, c, d;

	cout << "Введите числитель дроби 1: ";
	cin >> a;
	cout << "Введите знаменатель дроби 1: ";
	cin >> b;
	cout << "Введите числитель дроби 2: ";
	cin >> c;
	cout << "Введите знаменатель дроби 2: ";
	cin >> d;

	Fraction number(a, b);
	Fraction numberok(c, d);
	Fraction x = number + numberok;
	cout << a << "/" << b << " + " << c << "/" << d << " = " << x.get_num() << "/" << x.get_den() << endl;
    x = number - numberok;
	cout << a << "/" << b << " - " << c << "/" << d << " = " << x.get_num() << "/" << x.get_den() << endl;
	x = number * numberok;
	cout << a << "/" << b << " * " << c << "/" << d << " = " << x.get_num() << "/" << x.get_den() << endl;
	x = number / numberok;
	cout << a << "/" << b << " / " << c << "/" << d << " = " << x.get_num() << "/" << x.get_den() << endl;

	++number;
	x = number * numberok;
	cout << "++" << a << "/" << b << " * " << c << "/" << d << " = " << x.get_num() << "/" << x.get_den() << endl;
	cout << "Значение дроби 1 = " << number.get_num() << "/" << number.get_den() << endl;
	
	cout << number.get_num() << "/" << number.get_den() << "--" << " * " << c << "/" << d << " = ";
	x = number-- * numberok;
	cout << x.get_num() << "/" << x.get_den() << endl;
	cout << "Значение дроби 2 = " << number.get_num() << "/" << number.get_den() << endl;
	return 0;
}