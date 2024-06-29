#include <iostream>
#include <vector>

class FreeClass {
private:
    int* pointer_;
    int size_;
    std::vector<int> numbers_;
public:
    FreeClass(int* pointer, int size) : pointer_(pointer), size_(size) {};

    void operator() () {

        for (int i = 0; i < this->size_; ++i) {
            if (pointer_[i] % 3 == 0) {
                numbers_.push_back(pointer_[i]);
            }
        }
    }

    int get_sum() const {
        int sum = 0;
        for (int n : numbers_)
            sum += n;

        return sum;
    }

    int get_count() const {
        return numbers_.size();
    }
};

int main() {

    int const size = 6;
    int arr[size] = { 4, 1, 3, 6, 25, 54 };

    FreeClass func(arr, size);
    func();

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
