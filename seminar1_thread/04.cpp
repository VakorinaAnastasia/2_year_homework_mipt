#include <iostream>
#include <deque>
#include <thread>
#include <vector>
#include <chrono>

using std::cout, std::endl, std::size_t;
using namespace std::chrono_literals;

template <typename RandIt>
RandIt getMax(int n, RandIt start, RandIt finish) {
    if (start == finish) return start;
    if (n <= 0) n = 1;
    size_t len = finish - start;
    if (n > len) n = len;

    size_t chunk = len / n;
    size_t rem = len % n;
    std::vector<RandIt> local_max(n, start);
    std::vector<std::thread> threads;
    RandIt current = start;

    for (int i = 0; i < n; ++i) {
        size_t part = chunk + (i < rem ? 1 : 0);
        RandIt endIt = current + part;
        threads.emplace_back([&local_max, i, current, endIt]() {
            RandIt mx = current;
            for (auto it = current + 1; it != endIt; ++it) {
                if (*it > *mx) mx = it;
            }
            local_max[i] = mx;
        });
        current = endIt;
    }

    for (auto& t : threads) t.join();

    RandIt global_max = local_max[0];
    for (int i = 1; i < n; ++i) {
        if (*local_max[i] > *global_max) global_max = local_max[i];
    }
    return global_max;
}

int main() {
    cout << "Generating numbers! " << endl;
    std::deque<uint64_t> numbers;
    numbers.push_back(123456789);
    for (size_t i = 1; i < 1e7; ++i) {
        numbers.push_back(numbers.back() * i + 1);
    }
    cout << "Numbers generated! " << endl;

    auto start = std::chrono::high_resolution_clock::now();
    auto it = getMax(4, numbers.begin(), numbers.end());
    cout << "Maximum = " << *it << endl;

    auto end = std::chrono::high_resolution_clock::now();
    cout << "Time to calclulate max = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds. " << endl;
}