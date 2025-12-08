#include <iostream>
#include <string>

template<typename T>
T triple(const T& x)
{
    if constexpr (std::is_same_v<T, std::string>)
        return x + x + x;
    else
        return 3 * x;
}

int main()
{
    int a = 10;
    std::cout << triple(a) << std::endl;

    std::string b = "Cat";
    std::cout << triple(b) << std::endl;
}