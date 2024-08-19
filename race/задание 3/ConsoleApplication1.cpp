#include <iostream>
#include <mutex>

class Data {
public:
    Data(int value) : value(value), mutex() {}

    void swap(Data& other) {
        std::lock_guard<std::mutex> lock1(mutex);
        std::lock_guard<std::mutex> lock2(other.mutex);
        std::swap(value, other.value);
    }

    void swapWithLock(Data& other) {
        std::unique_lock<std::mutex> lock1(mutex, std::defer_lock);
        std::unique_lock<std::mutex> lock2(other.mutex, std::defer_lock);
        std::lock(lock1, lock2);
        std::swap(value, other.value);
    }

    int getValue() const {
        return value;
    }

private:
    int value;
    std::mutex mutex;
};

int main() {
    Data data1(10);
    Data data2(20);

    std::cout << "Before swap: " << std::endl;
    std::cout << "data1 value: " << data1.getValue() << std::endl;
    std::cout << "data2 value: " << data2.getValue() << std::endl;

    data1.swap(data2);

    std::cout << "After swap: " << std::endl;
    std::cout << "data1 value: " << data1.getValue() << std::endl;
    std::cout << "data2 value: " << data2.getValue() << std::endl;

    return 0;
}