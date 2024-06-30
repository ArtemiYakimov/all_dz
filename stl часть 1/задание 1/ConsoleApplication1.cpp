#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void countCharFrequencies(const string& text) {
    // Создаем карту для хранения частот символов
    map<char, int> freqMap;
    for (char c : text) {
        ++freqMap[c];
    }

    // Преобразуем карту в вектор пар и сортируем по значению в порядке убывания
    vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end());
    sort(freqVec.begin(), freqVec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
        });

    // Выводим отсортированные частоты
    for (const auto& pair : freqVec) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    string text = "Hello, World!";
    countCharFrequencies(text);
    return 0;
}

