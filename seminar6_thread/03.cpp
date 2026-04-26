#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using std::cout, std::endl, std::size_t;
using namespace std::chrono_literals;

uint64_t getMax(int n, const std::vector<uint64_t>& v) {
    if (v.empty()) return 0;
    if (n <= 0) n = 1;
    if (n > v.size()) n = v.size();

    size_t chunk = v.size() / n;
    size_t rem = v.size() % n;
    std::vector<uint64_t> local_max(n);
    std::vector<std::thread> threads;
    size_t current = 0;

    for (int i = 0; i < n; ++i) {
        size_t part = chunk + (i < rem ? 1 : 0);
        size_t end = current + part;
        threads.emplace_back([&v, &local_max, i, current, end]() {
            uint64_t mx = v[current];
            for (size_t j = current + 1; j < end; ++j) {
                if (v[j] > mx) mx = v[j];
            }
            local_max[i] = mx;
        });
        current = end;
    }

    for (auto& t : threads) t.join();

    uint64_t global_max = local_max[0];
    for (int i = 1; i < n; ++i) {
        if (local_max[i] > global_max) global_max = local_max[i];
    }
    return global_max;
}

int main() {
    cout << "Generating numbers! " << endl;
    std::vector<uint64_t> numbers(5e8);
    numbers[0] = 123456789;
    for (size_t i = 1; i < numbers.size(); ++i) {
        numbers[i] = numbers[i - 1] * i + 1;
    }
    cout << "Numbers generated! " << endl;

    auto start = std::chrono::high_resolution_clock::now();
    uint64_t m = getMax(4, numbers);
    cout << "Maximum = " << m << endl;

    auto end = std::chrono::high_resolution_clock::now();
    cout << "Time to calclulate max = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds. " << endl;
}