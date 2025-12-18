#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <utility>

template <typename Container>
auto pairElements(const Container& container) -> std::vector<std::pair<typename Container::value_type, typename Container::value_type>> {
    using T = typename Container::value_type;
    std::vector<std::pair<T, T>> result;
    auto it = container.begin();
    
    while (it != container.end()) {
        T first = *it;
        ++it;
        T second = (it != container.end()) ? *it : T();
        result.emplace_back(first, second);
        if (it != container.end()) ++it;
    }
    
    return result;
}

void testPairing() {
    std::vector<int> v1 = {10, 20, 30, 40, 50};
    auto pairs1 = pairElements(v1);
    for (const auto& p : pairs1) std::cout << "{" << p.first << ", " << p.second << "} ";
    std::cout << "\n";
    
    std::list<std::string> l1 = {"cat", "dog", "mouse", "lion"};
    auto pairs2 = pairElements(l1);
    for (const auto& p : pairs2) std::cout << "{\"" << p.first << "\", \"" << p.second << "\"} ";
    std::cout << "\n";
    
    std::string s1 = "Hello";
    auto pairs3 = pairElements(s1);
    for (const auto& p : pairs3) std::cout << "{'" << p.first << "', '" << p.second << "'} ";
    std::cout << "\n";
}

int main() {
    testPairing();
}