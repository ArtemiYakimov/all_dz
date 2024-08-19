#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Параметр для максимального количества клиентов
    const int MAX_CLIENTS = 10;

    // Счетчик клиентов
    std::atomic<int> client_count = 0;

    // Поток для имитации клиентов
    std::thread client_thread([&]() {
        while (true) {
            // Ожидание 1 секунды
            std::this_thread::sleep_for(std::chrono::seconds(1));

            // Увеличение счетчика клиентов
            if (client_count.load(std::memory_order_relaxed) < MAX_CLIENTS) {
                client_count.fetch_add(1, std::memory_order_relaxed);
                std::cout << "Новый клиент. Количество клиентов: " << client_count.load(std::memory_order_relaxed) << std::endl;
            }
        }
        });

    // Поток для имитации операциониста
    std::thread operator_thread([&]() {
        while (client_count.load(std::memory_order_relaxed) > 0) {
            // Ожидание 2 секунд
            std::this_thread::sleep_for(std::chrono::seconds(2));

            // Уменьшение счетчика клиентов
            if (client_count.load(std::memory_order_relaxed) > 0) {
                client_count.fetch_sub(1, std::memory_order_relaxed);
                std::cout << "Обслужен клиент. Количество клиентов: " << client_count.load(std::memory_order_relaxed) << std::endl;
            }
        }
        });

    // Ожидание завершения потоков
    client_thread.join();
    operator_thread.join();

    return 0;
}