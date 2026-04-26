#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <chrono>

using std::cout, std::endl, std::size_t;

template<typename RandIt, typename Comparator>
void parallelSort(int n, RandIt start, RandIt finish, Comparator comp) {
    size_t len = finish - start;
    if (n <= 1 || len < 2) {
        std::sort(start, finish, comp);
        return;
    }
    if (n > len) n = len;

    size_t chunk = len / n;
    size_t rem = len % n;
    std::vector<std::thread> threads;
    std::vector<RandIt> bounds;
    RandIt current = start;
    bounds.push_back(start);

    for (int i = 0; i < n; ++i) {
        size_t part = chunk + (i < rem ? 1 : 0);
        RandIt endIt = current + part;
        bounds.push_back(endIt);
        threads.emplace_back([current, endIt, comp]() {
            std::sort(current, endIt, comp);
        });
        current = endIt;
    }

    for (auto& t : threads) t.join();

    for (size_t step = 1; step < n; step *= 2) {
        for (size_t i = 0; i < n; i += 2 * step) {
            if (i + step < n) {
                RandIt mid = bounds[i + step];
                RandIt end = (i + 2 * step < n) ? bounds[i + 2 * step] : finish;
                if (mid < end) std::inplace_merge(bounds[i], mid, end, comp);
            }
        }
    }
}

int main() {
    std::vector<int> v(1e7);
    for (size_t i = 0; i < v.size(); ++i) v[i] = v.size() - i;

    auto start = std::chrono::high_resolution_clock::now();
    parallelSort(4, v.begin(), v.end(), std::less<int>());
    auto end = std::chrono::high_resolution_clock::now();

    cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << endl;
}