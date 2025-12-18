#include <iostream>
#include <map>
#include <vector>

void countOccurrences() {
    int n;
    std::cin >> n;
    std::map<int, int> countMap;
    
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        countMap[num]++;
    }
    
    std::vector<int> uniqueNumbers;
    for (const auto& pair : countMap) uniqueNumbers.push_back(pair.first);
    
    for (size_t i = 0; i < uniqueNumbers.size(); ++i) std::cout << uniqueNumbers[i] << " ";
    std::cout << "\n";
    
    for (const auto& pair : countMap) std::cout << pair.second << " ";
    std::cout << "\n";
}

int main() {
    countOccurrences();
}