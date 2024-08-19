#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <vector>

const int NUM_THREADS = 5; // количество потоков
const int CALCULATION_TIME = 5; // время расчета в секундах

void calculateInThread(int threadId) {
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "Thread " << std::setw(2) << threadId << " | ID: " << std::this_thread::get_id() << " | ";
    for (int i = 0; i < 50; i++) {
        std::cout << "#";
        std::this_thread::sleep_for(std::chrono::milliseconds(CALCULATION_TIME * 10 / 50));
    }
    std::cout << " | Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count() << " ms" << std::endl;
}

int main() {
    std::vector<std::thread> threads;

    std::cout << "+--------------+---------------------+--------------------+-------------+" << std::endl;
    std::cout << "| Thread ID    | Thread Identifier  | Calculation Status | Time Taken  |" << std::endl;
    std::cout << "+--------------+---------------------+--------------------+-------------+" << std::endl;

    for (int i = 0; i < NUM_THREADS; i++) {
        threads.emplace_back(calculateInThread, i + 1);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "+--------------+---------------------+--------------------+-------------+" << std::endl;

    return 0;
}