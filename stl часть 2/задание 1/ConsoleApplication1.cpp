#include <iostream>
#include <set>
#include <vector>

std::vector<int> deletecopy(std::vector<int> vec) {
    std::set<int> set(vec.begin(), vec.end()); // создать множество из вектора
    vec.assign(set.begin(), set.end()); // присвоить множество обратно вектор
    return vec;
}

int main() {
    std::vector<int> vec = { 1, 1, 2, 5, 6, 1, 2, 4 };
    vec = deletecopy(vec);
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
