#include <iostream>
#include <set>

void uniqueNumbers() {
    int n;
    std::cin >> n;
    std::set<int> uniqueSet;
    
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        uniqueSet.insert(num);
    }
    
    for (int num : uniqueSet) std::cout << num << " ";
    std::cout << "\n";
}

int main() {
    uniqueNumbers();
}