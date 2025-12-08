#include <iostream>
#include <string>

std::string operator*(int n, const std::string& s)
{
    std::string result;
    for (int i = 0; i < n; ++i)
        result += s;
    return result;
}

template<typename T>
T triple(const T& x)
{
    return 3 * x;
}

int main()
{
    std::string b = "Cat";
    std::cout << triple(b) << std::endl;
}