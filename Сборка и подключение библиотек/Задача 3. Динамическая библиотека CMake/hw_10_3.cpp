#include <iostream>
#include <Windows.h>
#include "leaver.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string a;

    cout << "¬ведите им€: ";
    cin >> a;
    Leaver name;
    cout << name.leave(a);

    return 0;
}