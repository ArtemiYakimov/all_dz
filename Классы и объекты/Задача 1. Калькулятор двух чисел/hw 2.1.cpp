#include <iostream>
#include <Windows.h>

using namespace std;

class Calculator {
private: 
    double num1; 
    double num2;
protected:
public:
    double add() {
        return num1 + num2;
    };
    double multiply() {
        return num1 * num2;
    };
    double subtract_1_2() {
        return num1 - num2;
    };
    double subtract_2_1() {
        return num2 - num1;
    };
    double divide_1_2() {
        return num1 / num2;
    };
    double divide_2_1() {
        return num2 / num1;
    };
    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        }
        else {
            cout << "Неверный ввод!" << endl;
            return false;
        }
    };
    bool set_num2(double num2) {
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        }
        else {
            cout << "Неверный ввод!" << endl;
            return false;
        }
    };
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double x;
    double y;
    bool flag;
    Calculator calc;

    do {
        do {
            cout << "Введите num1: ";
            cin >> x;
            flag = calc.set_num1(x);
        } while (!flag);
        
        do {
            cout << "Введите num2: ";
            cin >> y;
            flag = calc.set_num2(y);
        } while (!flag);

        cout << "num1 + num2 = " << calc.add() << endl;
        cout << "num1 - num2 = " << calc.subtract_1_2() << endl;
        cout << "num2 - num1 = " << calc.subtract_2_1() << endl;
        cout << "num1 * num2 = " << calc.multiply() << endl;
        cout << "num1 / num2 = " << calc.divide_1_2() << endl;
        cout << "num2 / num1 = " << calc.divide_2_1() << endl;

     } while (true);

    return 0;
}