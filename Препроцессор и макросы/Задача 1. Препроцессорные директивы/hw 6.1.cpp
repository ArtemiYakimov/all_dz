#include <iostream>
#include <Windows.h>
#define MODE 1

using namespace std;

void add() {
    int a, b;
    cout << "Работаю в боевом режиме" << endl;
    cout << "Введите число 1: ";
    cin >> a;
    cout << "Введите число 2: ";
    cin >> b;
    cout << "Результат сложения: " << (a + b);
    
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

#if MODE == 0
    cout << "Работаю в режиме тренировки" << endl;
#elif MODE == 1
    add();
#else
    cout << "Неизвестный режим. Завершение работы" << endl;
#endif

    return 0;
}
