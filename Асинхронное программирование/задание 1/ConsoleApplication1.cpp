#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <future>
#include <numeric>

template <typename InputIterator, typename Function>
void parallel_for_each(InputIterator first, InputIterator last, Function&& f, size_t min_chunk_size = 1) {
    const size_t length = std::distance(first, last);
    if (length <= min_chunk_size) {
        std::for_each(first, last, std::forward<Function>(f));
        return;
    }

    const size_t num_threads = std::thread::hardware_concurrency();
    const size_t chunk_size = (length + num_threads - 1) / num_threads;

    std::vector<std::future<void>> futures;

    for (size_t i = 0; i < num_threads; ++i) {
        InputIterator start = first + i * chunk_size;
        InputIterator end = (i == num_threads - 1) ? last : first + (i + 1) * chunk_size;
        futures.emplace_back(std::async(std::launch::async, [start, end, f = std::forward<Function>(f)]() {
            std::for_each(start, end, f);
            }));
    }

    for (auto& future : futures) {
        future.get();
    }
}

int main() {
    std::vector<int> v(100);
    std::iota(v.begin(), v.end(), 0);

    parallel_for_each(v.begin(), v.end(), [](int x) {
        std::cout << x << " ";
        });
    std::cout << std::endl;

    return 0;
}