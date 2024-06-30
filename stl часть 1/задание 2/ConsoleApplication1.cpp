#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;  // Считываем количество элементов

    set<int> uniqueNumbers;  // Множество для хранения уникальных чисел
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;  // Считываем очередное число
        uniqueNumbers.insert(num);  // Добавляем в множество
    }

    vector<int> sortedNumbers(uniqueNumbers.begin(), uniqueNumbers.end());  // Преобразуем множество в вектор
    sort(sortedNumbers.begin(), sortedNumbers.end(), greater<int>());  // Сортируем вектор в порядке убывания

    // Выводим отсортированные уникальные числа
    for (int num : sortedNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
