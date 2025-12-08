#include <iostream>

template<typename T>
T cube(T x)
{
    return x * x * x;
}

int main()
{
    auto a = cube(5);
    std::cout << a << " " << sizeof(a) << std::endl;

    auto b = cube(5.0);
    std::cout << b << " " << sizeof(b) << std::endl;

    char x = 5;
    auto c = cube(x);
    std::cout << int(c) << " " << sizeof(c) << std::endl;
}