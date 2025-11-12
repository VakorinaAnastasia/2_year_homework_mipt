#include <iostream>
#include <string>

struct Book
{
    std::string title;
    int pages;
    float price;
};

bool isExpensive(const Book& book)
{
    return book.price > 1000;
}

int main()
{
    Book book1 = {"C++ Programming", 500, 800.0f};
    Book book2 = {"Advanced C++", 800, 1500.0f};
    
    std::cout << std::boolalpha;
    std::cout << isExpensive(book1) << std::endl;
    std::cout << isExpensive(book2) << std::endl;
}