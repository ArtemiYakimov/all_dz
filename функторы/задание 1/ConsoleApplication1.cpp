#include <iostream>
#include <Windows.h>
#include <vector>

template <class T>
T my_sqrt(T a) {
    return a * a;
};

template <class T>
std::vector<T> my_sqrt(std::vector<T> vec) {
    for (int i = 0; i < vec.size(); i++) {
        vec[i] *= vec[i];
    }

    return vec;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int t = 4;
    std::cout << "[IN] : " << t << std::endl;
    std::cout << "[OUT] : " << my_sqrt(t) << std::endl;

    std::vector<int> vec{ -1, 4, 8 };
    std::cout << "[IN] : ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << (i != vec.size() ? ", " : "");
    }
    std::cout << std::endl;

    vec = my_sqrt(vec);

    std::cout << "[OUT] : ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << (i != vec.size() ? ", " : "");
    }

    return 0;
}