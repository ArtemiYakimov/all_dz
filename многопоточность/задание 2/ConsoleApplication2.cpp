#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

// Функция для вычисления суммы двух векторов
void sumVectors(const vector<int>& v1, const vector<int>& v2, vector<int>& result, int start, int end) {
    for (int i = start; i < end; i++) {
        result[i] = v1[i] + v2[i];
    }
}

int main() {
    // Размеры тестовых массивов
    vector<int> sizes = { 1000, 10000, 100000, 1000000 };

    // Вывод доступного количества аппаратных ядер
    cout << "Available hardware threads: " << thread::hardware_concurrency() << endl;

    // Таблица для хранения результатов
    cout << "Size\t2 threads\t4 threads\t8 threads\t16 threads" << endl;

    for (int size : sizes) {
        // Создание тестовых векторов
        vector<int> v1(size), v2(size), result(size);

        // Замер времени для 2 потоков
        auto start = chrono::high_resolution_clock::now();
        vector<thread> threads2(2);
        for (int i = 0; i < 2; i++) {
            threads2[i] = thread(sumVectors, ref(v1), ref(v2), ref(result), i * size / 2, (i + 1) * size / 2);
        }
        for (auto& t : threads2) {
            t.join();
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration2 = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        // Замер времени для 4 потоков
        start = chrono::high_resolution_clock::now();
        vector<thread> threads4(4);
        for (int i = 0; i < 4; i++) {
            threads4[i] = thread(sumVectors, ref(v1), ref(v2), ref(result), i * size / 4, (i + 1) * size / 4);
        }
        for (auto& t : threads4) {
            t.join();
        }
        end = chrono::high_resolution_clock::now();
        auto duration4 = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        // Замер времени для 8 потоков
        start = chrono::high_resolution_clock::now();
        vector<thread> threads8(8);
        for (int i = 0; i < 8; i++) {
            threads8[i] = thread(sumVectors, ref(v1), ref(v2), ref(result), i * size / 8, (i + 1) * size / 8);
        }
        for (auto& t : threads8) {
            t.join();
        }
        end = chrono::high_resolution_clock::now();
        auto duration8 = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        // Замер времени для 16 потоков
        start = chrono::high_resolution_clock::now();
        vector<thread> threads16(16);
        for (int i = 0; i < 16; i++) {
            threads16[i] = thread(sumVectors, ref(v1), ref(v2), ref(result), i * size / 16, (i + 1) * size / 16);
        }
        for (auto& t : threads16) {
            t.join();
        }
        end = chrono::high_resolution_clock::now();
        auto duration16 = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        // Вывод результатов в таблицу
        cout << size << "\t" << duration2 << "ms\t" << duration4 << "ms\t" << duration8 << "ms\t" << duration16 << "ms" << endl;
    }

    return 0;
}