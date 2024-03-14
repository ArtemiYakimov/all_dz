#include <iostream>
#include <Windows.h>
#include "math.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a, b, c;

    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
    cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    cin >> c;

    if (c == 1) {
        cout << a << " + " << b << " = " << summ(a, b) << endl;
    }
    else if (c == 2) {
        cout << a << " - " << b << " = " << raznost(a, b) << endl;
    }
    else if (c == 3) {
        cout << a << " * " << b << " = " << multiplic(a, b) << endl;
    }
    else if (c == 4) {
        cout << a << " / " << b << " = " << delenie(a, b) << endl;
    }
    else if (c == 5) {
        cout << a << " в степени " << b << " = " << step(a, b) << endl;
    }
    else {
        cout << "ОШИБКА, НЕ ТУПИ!!!" << endl;
    }
    return 0;
}