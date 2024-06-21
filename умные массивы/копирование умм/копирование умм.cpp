#include <Windows.h>
#include <iostream>
#include <stdexcept>

using namespace std;

class smart_array {
private:
    int* arr;
    int position;
    int size;

public:
    smart_array(int size) : position(0), size(size) {
        arr = new int[size]();
    }
    smart_array(const smart_array& other_array) : position(other_array.position), size(other_array.size) {
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other_array.arr[i];
        }
    };

    ~smart_array() {
        delete[] arr;
    }

    int get_size() const {
        return size;
    }

    int get_position() const {
        return position;
    }

    smart_array& operator=(const smart_array& other_arr) {
        if (this != &other_arr) {
            delete[] arr;
            size = other_arr.get_size();
            position = other_arr.get_position();
            arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = other_arr.get_element(i);
            }
        }
        return *this;
    }

    void add_element(int number) {
        if (position == size) {
            int half = (size + 1) / 2;
            int newSize = size + half;
            int* new_arr = new int[newSize];

            for (int i = 0; i < size; i++) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
            size = newSize;
        }
        arr[position] = number;
        position += 1;
    }

    int get_element(int index) const {
        if (index >= 0 && index < position) {
            return arr[index];
        }
        throw out_of_range("Index out of bounds");
    }
};

int main() {
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);

        smart_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);

        arr = new_array;

        cout << arr.get_element(0) << endl;
        cout << arr.get_element(1) << endl;
        // cout << arr.get_element(2) << endl; // This will throw an exception
    }
    catch (const exception& ex) {
        cout << ex.what() << endl;
    }

    return 0;
}