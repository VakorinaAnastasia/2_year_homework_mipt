#include <iostream>
#include <string>

template<typename T>
T triple(const T& x)
{
    return 3 * x;
}

std::string triple(const std::string& x)
{
    return x + x + x;
}

int main()
{
    std::string b = "Cat";
    std::cout << triple(b) << std::endl;
}