#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
using namespace std::chrono_literals;

void worker(int id) {
    std::cout << "Thread#" << id << " started." << std::endl;
    std::this_thread::sleep_for(id * 1s);
    std::cout << "Thread#" << id << " finished." << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::thread> threads;
    threads.reserve(n);
    for (int i = 1; i <= n; ++i) {
        threads.emplace_back(worker, i);
    }
    for (auto& t : threads) t.join();
}
