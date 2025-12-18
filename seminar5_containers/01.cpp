#include <iostream>
#include <list>
#include <vector>

void josephusProblem(int n, int m) {
    std::list<int> warriors;
    for (int i = 1; i <= n; ++i) warriors.push_back(i);
    
    std::vector<int> eliminationOrder;
    auto it = warriors.begin();
    
    while (!warriors.empty()) {
        for (int i = 1; i < m; ++i) {
            ++it;
            if (it == warriors.end()) it = warriors.begin();
        }
        
        eliminationOrder.push_back(*it);
        it = warriors.erase(it);
        if (it == warriors.end() && !warriors.empty()) it = warriors.begin();
    }
    
    for (size_t i = 0; i < eliminationOrder.size() - 1; ++i)
        std::cout << eliminationOrder[i] << " ";
    std::cout << eliminationOrder.back() << "\n" << eliminationOrder.back() << "\n";
}

int main() {
    int n, m;
    while (std::cin >> n >> m) josephusProblem(n, m);
}