#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    float num1, num2, num3;

    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;
    cout << "Введите третье число: ";
    cin >> num3;

    if (num1 == num2 || num1 == num3 || num2 == num3) {
        num1 += 5;
        num2 += 5;
        num3 += 5;
        cout << "Результат: " << num1 << ", " << num2 << ", " << num3 << endl;
    }
    else {
        cout << "Равных чисел нет" << endl;
    }

    return 0;
}