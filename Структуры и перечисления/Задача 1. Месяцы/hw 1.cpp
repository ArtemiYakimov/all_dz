#include <iostream>
#include <Windows.h>

using namespace std;

enum mounts {
    january = 1,
    february = 2,
    march = 3,
    april = 4,
    may = 5,
    june = 6,
    july = 7,
    august = 8,
    september = 9,
    october = 10,
    november = 11,
    december = 12
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool flag = true;
    int a = 0;
    do {
        cout << "Введите номер месяца: ";
        cin >> a;
        if (a > 0) {
            if (a == mounts::january) cout << "Январь" << endl;
            else if (a == mounts::february) cout << "Февраль" << endl;
            else if (a == mounts::march) cout << "Март" << endl;
            else if (a == mounts::april) cout << "Апрель" << endl;
            else if (a == mounts::may) cout << "Май" << endl;
            else if (a == mounts::june) cout << "Июнь" << endl;
            else if (a == mounts::july) cout << "Июль" << endl;
            else if (a == mounts::august) cout << "Август" << endl;
            else if (a == mounts::september) cout << "Сентябрь" << endl;
            else if (a == mounts::october) cout << "Октябрь" << endl;
            else if (a == mounts::november) cout << "Ноябрь" << endl;
            else if (a == mounts::december) cout << "Декабрь" << endl;
            else cout << "Неправильный номер!" << endl;
        }
        else {
            flag = false;
        }
    } while (flag);
    cout << "До свидания" << endl;
    
        return 0;
}