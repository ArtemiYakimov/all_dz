#include <iostream>
template <typename T>
class Vector {
private:
    T* data_;  // Указатель на массив элементов
    int size_;  // Количество элементов в контейнере
    int capacity_;  // Количество элементов, которое может вместить контейнер до нового выделения памяти

public:
    Vector() : size_(0), capacity_(2) {
        data_ = new T[capacity_];  // Инициализируем массив с начальной емкостью 2
    }

    ~Vector() {
        delete[] data_;  // Освобождаем память при уничтожении контейнера
    }

    T& at(int index) {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    void push_back(T value) {
        if (size_ == capacity_) {
            // Если контейнер заполнен, увеличиваем емкость в 2 раза
            capacity_ *= 2;
            T* newData = new T[capacity_];
            for (int i = 0; i < size_; ++i) {
                newData[i] = std::move(data_[i]);  // Копируем элементы с помощью std::move
            }
            delete[] data_;
            data_ = newData;
        }
        data_[size_++] = std::move(value);  // Используем std::move для перемещения значения
    }

    int size() {
        return size_;
    }

    int capacity() {
        return capacity_;
    }
};

int main() {
    Vector<int> vec;  // Создаем объект класса Vector
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;

    return 0;
}
