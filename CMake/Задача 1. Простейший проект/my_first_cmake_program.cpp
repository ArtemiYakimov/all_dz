#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string a;

    cout << "������� ���: ";
    cin >> a;
    cout << "������������, " << a << endl;

    return 0;
}