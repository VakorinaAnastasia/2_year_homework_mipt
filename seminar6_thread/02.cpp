#include <iostream>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;

void chain(int current, int total) {
    std::cout << "Thread#" << current << " started." << std::endl;
    std::this_thread::sleep_for(200ms);
    if (current < total) {
        std::thread next(chain, current + 1, total);
        next.join();
    }
    std::this_thread::sleep_for(200ms);
    std::cout << "Thread#" << current << " finished." << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    if (n > 0) {
        std::thread t(chain, 1, n);
        t.join();
    }
}