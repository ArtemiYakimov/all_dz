#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

const int NUM_THREADS = 5; // количество потоков
const int CALCULATION_TIME = 5; // время расчета в секундах

std::mutex mtx; // мьютекс для синхронизации доступа к консоли

void calculateInThread(int threadId) {
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 50; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(CALCULATION_TIME * 10 / 50));
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count();

        mtx.lock(); // блокируем мьютекс для доступа к консоли
        // Установка курсора в нужную позицию
        std::cout << "\033[" << threadId << ";0H"; // Перемещение курсора на строку threadId, колонку 0
        std::cout << "| " << std::setw(2) << threadId << " | " << std::this_thread::get_id() << " | ";
        for (int j = 0; j < i; j++) {
            std::cout << "#";
        }
        for (int j = i; j < 50; j++) {
            std::cout << " ";
        }
        std::cout << " | " << std::setw(6) << elapsed << " ms |";
        std::cout.flush();
        mtx.unlock(); // разблокируем мьютекс
    }
}

int main() {
    std::vector<std::thread> threads;

    // Очистка консоли и установка курсора в начало
    std::cout << "\033[2J\033[1;1H";
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