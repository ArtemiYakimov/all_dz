#include <iostream>
#include <Windows.h>

using namespace std;

struct dan {
    string a;
    string b;
    int c;
    int d;
    int e;
};

void console(dan* q) {
    cout << "Город: " << q-> a << endl;
    cout << "Улица: " << q->b << endl;
    cout << "Номер дома: " << q->c << endl;
    cout << "Номер квартиры: " << q->d << endl;
    cout << "Индекс: " << q->e << endl;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    dan s = {
        "Москва", "Арбат", 12, 8, 123456
    };

    console(&s);
    cout << endl;

    s = {
        "Холмск", "Советская", 1, 12, 159845
    };

    console(&s);

    return 0;
}

/*Город: Москва
Улица: Арбат
Номер дома: 12
Номер квартиры: 8
Индекс: 123456 */