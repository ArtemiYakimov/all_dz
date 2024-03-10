#include <iostream>
#include <Windows.h>

using namespace std;
    
    enum class mounts {
    january = 1,
    february, 
    march,
    april,
    may,
    june,
    july,
    august,
    september,
    october,
    november,
    december
    };

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool flag = true;
    int a = 0;
    
    do {
        std::cout << "Введите номер месяца: ";
        cin >> a;
        mounts mount = static_cast<mounts>(a);
        if (a > 0) {
            if (mount == mounts::january) std::cout << "Январь" << endl;
            else if (mount == mounts::february) std::cout << "Февраль" << endl;
            else if (mount == mounts::march) std::cout << "Март" << endl;
            else if (mount == mounts::april) std::cout << "Апрель" << endl;
            else if (mount == mounts::may) std::cout << "Май" << endl;
            else if (mount == mounts::june) std::cout << "Июнь" << endl;
            else if (mount == mounts::july) std::cout << "Июль" << endl;
            else if (mount == mounts::august) std::cout << "Август" << endl;
            else if (mount == mounts::september) std::cout << "Сентябрь" << endl;
            else if (mount == mounts::october) std::cout << "Октябрь" << endl;
            else if (mount == mounts::november) std::cout << "Ноябрь" << endl;
            else if (mount == mounts::december) std::cout << "Декабрь" << endl;
            else std::cout << "Неправильный номер!" << endl;
        }
        else {
            flag = false;
        }
    } while (flag);
    std::cout << "До свидания" << endl;
   
        return 0;
}