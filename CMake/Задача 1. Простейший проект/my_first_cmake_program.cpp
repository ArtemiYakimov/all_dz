#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string a;

    cout << "Введите имя: ";
    cin >> a;
    cout << "Здравствуйте, " << a << endl;

    return 0;
}