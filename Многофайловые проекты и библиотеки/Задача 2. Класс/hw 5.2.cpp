#include <iostream>
#include <Windows.h>
#include "chetchik.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string c;
    bool flag = true;
    int d;
    Counter r;
    cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    cin >> c;
    if (c == "да") {
        cout << "Введите начальное значение счётчика: ";
        cin >> d;
        r = Counter(d);
    }
    do {
        cout << "Введите команду ('+', '-', '=' или 'x'): ";
        cin >> c;
        if (c == "+") {
            r.uvel();
        }
        else if (c == "-") {
            r.umen();
        }
        else if (c == "=") {
            r.znach();
        }
        else if (c == "x") {
            cout << "До свидания!";
            flag = false;
        }
    } while (flag);

    return 0;
}