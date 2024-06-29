#include <iostream>
#include <vector>

class FreeClass {
private:
    int sum;
    int count;
    int* pointer_;
    int size_;
public:
    FreeClass(int* pointer, int size) : sum(0), count(0), pointer_(pointer), size_(size) {

        for (int i = 0; i < size; ++i) {
            if (pointer[i] % 3 == 0) {
                sum += pointer[i];
                count++;
            }
        }

    };

    int get_sum() const {
        return sum;
    }

    int get_count() const {
        return count;
    }
};

int main() {

    int const size = 6;
    int arr[size] = { 4, 1, 3, 6, 25, 54 };

    FreeClass func(arr, size);

    // row 1
    std::cout << "[IN]: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // row 2
    std::cout << "[OUT]: get_sum() = " << func.get_sum() << std::endl;

    // row 3
    std::cout << "[OUT]: get_count() = " << func.get_count() << std::endl;

    return 0;
}