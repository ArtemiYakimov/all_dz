#include <iostream>
#include <Windows.h>

using namespace std;

class Counter {
private:
    int a;
protected:
public:
    Counter() {
        this->a = 1;
    };
    Counter(int b) {
        this->a = b;
    };
    void uvel() {
        ++this->a;
    };
    void umen() {
        --this->a;
    };
    void znach() {
        cout << this->a << endl;
    };
};

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
/*
Вы хотите указать начальное значение счётчика? Введите да или нет: да
Введите начальное значение счётчика: 6
Введите команду ('+', '-', '=' или 'x'): +
Введите команду ('+', '-', '=' или 'x'): +
Введите команду ('+', '-', '=' или 'x'): =
8
Введите команду ('+', '-', '=' или 'x'): -
Введите команду ('+', '-', '=' или 'x'): =
7
Введите команду ('+', '-', '=' или 'x'): x
До свидания!
*/