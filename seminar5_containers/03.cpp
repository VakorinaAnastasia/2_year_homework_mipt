#include <iostream>
#include <set>

void sortWithMultiset() {
    int n;
    std::cin >> n;
    std::multiset<int> sortedSet;
    
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        sortedSet.insert(num);
    }
    
    for (int num : sortedSet) std::cout << num << " ";
    std::cout << "\n";
}

int main() {
    sortWithMultiset();
}