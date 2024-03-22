#include <iostream>
#include <Windows.h>
#include "greeter.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string a;
    cout << "Введите имя: ";
    cin >> a;
    Greeter name;
    cout << name.greet(a);
    return 0;
}