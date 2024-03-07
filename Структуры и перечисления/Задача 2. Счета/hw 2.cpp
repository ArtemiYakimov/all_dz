#include <iostream>
#include <Windows.h>
using namespace std;

struct bank {
    int a;
    string b;
    double c;
};

void chet(bank* q, double s) {
    q->c = s;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a;
    string b;
    double c;

    cout << "Введите номер счёта: ";
    cin >> a;
    cout << "Введите имя владельца: ";
    cin >> b;
    cout << "Введите баланс: ";
    cin >> c;
    bank q = {
        a, b, c
    };
    cout << "Введите новый баланс: ";
    cin >> c;
    chet(&q, c);
    cout << "Ваш счёт: " << q.b << ", " << q.a << ", " << q.c << endl;
   
    return 0;
}