#include <Windows.h>
#include <iostream>
#include <stdexcept>

class SmartArray {
private:
    int* arr;
    int position;
    int size;

public:
    SmartArray(int initialSize) : position(0), size(initialSize) {
        arr = new int[size]();
    }

    ~SmartArray() {
        delete[] arr;
    }

    void addElement(int number) {
        if (position == size) {
            int newSize = size + (size / 2);
            int* newArr = new int[newSize];
            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            size = newSize;
        }
        arr[position] = number;
        position++;
    }

    int getElement(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        SmartArray arr(5);
        arr.addElement(1);
        arr.addElement(4);
        arr.addElement(155);
        arr.addElement(14);
        arr.addElement(15);

        arr.addElement(21);
        arr.addElement(10);
        arr.addElement(132);

        std::cout << arr.getElement(7) << std::endl;
        std::cout << arr.getElement(17) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}