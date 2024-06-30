#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <algorithm>

template <typename Container>
void print_container(const Container& container) {
    for (const auto& element : container) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set); // four one three two (потому что множества сортируются)

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list); // one two three four

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector); // one two three four

    return 0;
}
