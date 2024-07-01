#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

// Шаблонная функция для перемещения содержимого одного вектор в другой
template <typename T>
void переместитьВекторы(std::vector<T>& src, std::vector<T>& dst) {
    dst = std::move(src);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Создаем два вектора строк
    std::vector<std::string> один = { "строка_тест1", "строка_тест2" };
    std::vector<std::string> два;

    // Выводим содержимое векторов до перемещения
    std::cout << "Содержимое вектора один до перемещения:" << std::endl;
    for (const auto& str : один) {
        std::cout << str << std::endl;
    }
    std::cout << "Содержимое вектора два до перемещения:" << std::endl;
    for (const auto& str : два) {
        std::cout << str << std::endl;
    }

    // Перемещаем содержимое вектора один в вектор два
    переместитьВекторы(один, два);

    // Выводим содержимое векторов после перемещения
    std::cout << "Содержимое вектора один после перемещения:" << std::endl;
    for (const auto& str : один) {
        std::cout << str << std::endl;
    }
    std::cout << "Содержимое вектора два после перемещения:" << std::endl;
    for (const auto& str : два) {
        std::cout << str << std::endl;
    }

    return 0;
}
