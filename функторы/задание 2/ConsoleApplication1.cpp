#include <iostream>
#include <Windows.h>

template <class T>
class Table {
public:
    T** arr;
    int rows, cols;

    Table(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;

        arr = new T * [rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new T[cols];
        }
    };

    T* operator[] (int index)
    {
        if (index >= 0 && index < this->rows) {
            return this->arr[index];
        }
    }

    T* operator[] (int index) const
    {
        if (index >= 0 && index < this->rows) {
            return this->arr[index];
        }

        throw std::runtime_error("Выход за пределы массива ...");
    }

    ~Table() {
        for (int i = 0; i < this->rows; i++) {
            delete[] this->arr[i];
        }
        delete[] this->arr;
    };
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    auto table = Table<int>(2, 3);
    table[0][0] = 4;
    std::cout << table[0][0];

    return 0;
}