#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Параметр для максимального количества клиентов
    const int MAX_CLIENTS = 10;

    // Счетчик клиентов
    std::atomic<int> client_count = 0;

    // Мьютекс для синхронизации доступа к счетчику
    std::mutex mtx;

    // Поток для имитации клиентов
    std::thread client_thread([&]() {
        while (true) {
            // Ожидание 1 секунды
            std::this_thread::sleep_for(std::chrono::seconds(1));

            // Увеличение счетчика клиентов
            mtx.lock();
            if (client_count < MAX_CLIENTS) {
                client_count++;
                std::cout << "Новый клиент. Количество клиентов: " << client_count << std::endl;
            }
            mtx.unlock();
        }
        });

    // Поток для имитации операциониста
    std::thread operator_thread([&]() {
        while (client_count > 0) {
            // Ожидание 2 секунд
            std::this_thread::sleep_for(std::chrono::seconds(2));

            // Уменьшение счетчика клиентов
            mtx.lock();
            if (client_count > 0) {
                client_count--;
                std::cout << "Обслужен клиент. Количество клиентов: " << client_count << std::endl;
            }
            mtx.unlock();
        }
        });

    // Ожидание завершения потоков
    client_thread.join();
    operator_thread.join();

    return 0;
}