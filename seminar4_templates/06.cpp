#include <iostream>

template<typename IntType, IntType Mod>
class Modular
{
private:
    IntType value;
public:
    Modular(IntType v = 0) : value(v % Mod)
    {
        if (value < 0) value += Mod;
    }

    Modular(const Modular& other) : value(other.value) {}

    Modular& operator=(const Modular& other)
    {
        value = other.value;
        return *this;
    }

    Modular operator+(const Modular& other) const
    {
        return Modular(value + other.value);
    }

    Modular operator-(const Modular& other) const
    {
        return Modular(value - other.value);
    }

    Modular operator*(const Modular& other) const
    {
        return Modular(value * other.value);
    }

    Modular operator-() const
    {
        return Modular(-value);
    }

    template<typename U, U M>
    Modular(const Modular<U, M>& other) : value(other.getValue() % Mod) {}

    IntType getValue() const { return value; }

    friend std::ostream& operator<<(std::ostream& os, const Modular& m)
    {
        return os << m.value;
    }
};

int main()
{
    Modular<int, 7> a(10);
    std::cout << a << std::endl;
    a = (a + 8) * 4;
    std::cout << a << std::endl;

    Modular<int, 7> b(a);
    b = b + 2;
    a = a - b;
    std::cout << a << std::endl;

    Modular<short, 3> c(a);
    std::cout << c << std::endl;
}