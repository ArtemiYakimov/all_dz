#include <iostream>
#include <vector>
#include <algorithm>
#include <future>

// Функция для поиска минимального элемента в векторе
std::future<int> findMinElement(const std::vector<int>& vec, int start, int end) {
    return std::async(std::launch::async, [&vec, start, end]() {
        int minIdx = start;
        for (int i = start + 1; i <= end; ++i) {
            if (vec[i] < vec[minIdx]) {
                minIdx = i;
            }
        }
        return minIdx;
        });
}

// Функция для сортировки вектора выбором
std::vector<int> selectionSort(std::vector<int> vec) {
    for (int i = 0; i < vec.size() - 1; ++i) {
        std::future<int> minIdxFuture = findMinElement(vec, i, vec.size() - 1);
        int minIdx = minIdxFuture.get();

        // Меняем местами минимальный элемент и элемент на i-м месте
        std::swap(vec[i], vec[minIdx]);
    }
    return vec;
}

int main() {
    std::vector<int> unsortedVector = { 5, 2, 8, 1, 9, 3 };
    std::vector<int> sortedVector = selectionSort(unsortedVector);

    std::cout << "Unsorted vector: ";
    for (int num : unsortedVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted vector: ";
    for (int num : sortedVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}