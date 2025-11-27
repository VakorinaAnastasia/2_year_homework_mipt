#include <iostream>
#include <string>
#include <new>

int main()
{
    std::string stackString = "Cat";
    std::cout << stackString << std::endl;
    
    std::string* heapString = new std::string("Dog");
    std::cout << *heapString << std::endl;
    delete heapString;
    
    char x[sizeof(std::string)];
    std::string* placementString = new (x) std::string("Elephant");
    std::cout << *placementString << std::endl;
    placementString->~basic_string();
}