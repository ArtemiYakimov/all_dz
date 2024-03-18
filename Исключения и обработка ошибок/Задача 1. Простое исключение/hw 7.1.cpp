#include <iostream>
#include <Windows.h>

using namespace std;

int function(string str, int forbidden_length) {
    int q = str.length();
    if (q != forbidden_length) {
        return q;
    }
    throw "Вы ввели слово запретной длины! До свидания";
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a;
    string b;

    bool flag = true;

    cout << "Введите запретную длину: ";
    cin >> a;

    try {

        do {
            cout << "Введите слово: ";
            cin >> b;
            cout << "Длина слова \"" + b + "\" равна " << function(b, a) << endl;
        } while (flag);
    }
    catch (const char* error) {
        cout << error << endl;
    }
    catch (...) {
        cout << "Неизвестная ошибка" << endl;
    }

    return 0;
}
