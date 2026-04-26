#include <iostream>
#include <thread>
#include <vector>
#include <string>

using std::cout, std::endl;
using namespace std::string_literals;

void func(const std::string& a, int b) {
    cout << a << " " << b << endl;
}

template <typename Func, typename... Args>
void iterate(int n, Func func, Args... args) {
    std::vector<std::thread> threads;
    threads.reserve(n);
    for (int i = 0; i < n; ++i) {
        threads.emplace_back(func, args...);
    }
    for (auto& t : threads) {
        t.join();
    }
}

int main() {
    iterate(5, func, "Hello"s, 12345);
}