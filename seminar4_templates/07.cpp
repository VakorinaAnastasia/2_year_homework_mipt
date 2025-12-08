#include <iostream>
#include <string>
#include <cstdlib>

template<typename T>
class Manager
{
private:
    T* ptr;
public:
    Manager() : ptr(nullptr) {}

    void allocate()
    {
        ptr = static_cast<T*>(std::malloc(sizeof(T)));
    }

    void construct(const T& t)
    {
        new (ptr) T(t);
    }

    void destruct()
    {
        ptr->~T();
    }

    void deallocate()
    {
        std::free(ptr);
        ptr = nullptr;
    }

    T& get()
    {
        return *ptr;
    }
};

int main()
{
    using namespace std::string_literals;

    Manager<std::string> a;
    a.allocate();
    a.construct("Cats and dogs"s);
    a.get() += " and elephant";
    std::cout << a.get() << std::endl;
    a.destruct();
    a.construct("Sapere Aude"s);
    std::cout << a.get() << std::endl;
    a.destruct();
    a.deallocate();
}