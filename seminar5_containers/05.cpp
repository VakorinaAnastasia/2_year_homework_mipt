#include <iostream>
#include <set>
#include <vector>

void ropeProblem() {
    int n, k;
    std::cin >> n >> k;
    
    std::set<int> cuts = {0, n};
    std::multiset<int> lengths = {n};
    std::vector<int> maxLengths;
    
    for (int i = 0; i < k; ++i) {
        int cutPoint;
        std::cin >> cutPoint;
        
        auto it = cuts.lower_bound(cutPoint);
        int right = *it;
        --it;
        int left = *it;
        
        lengths.erase(lengths.find(right - left));
        lengths.insert(cutPoint - left);
        lengths.insert(right - cutPoint);
        cuts.insert(cutPoint);
        maxLengths.push_back(*lengths.rbegin());
    }
    
    for (size_t i = 0; i < maxLengths.size(); ++i) std::cout << maxLengths[i] << " ";
    std::cout << "\n";
}

int main() {
    ropeProblem();
}