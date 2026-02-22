#include <iostream>
#include <vector>
#include <dlfcn.h>
#include <unistd.h>

int main() {
    sleep(2);
    void* handle = dlopen("./miptlib.dll", RTLD_LAZY);
    
    using add_t = double(*)(double, double);
    using power_t = double(*)(double, int);
    using circleArea_t = double(*)(double);
    using mean_t = double(*)(const std::vector<double>&);
    
    add_t add = (add_t)dlsym(handle, "_ZN7miptlib3addEdd");
    power_t power = (power_t)dlsym(handle, "_ZN7miptlib5powerEdi");
    circleArea_t circleArea = (circleArea_t)dlsym(handle, "_ZN7miptlib10circleAreaEd");
    mean_t mean = (mean_t)dlsym(handle, "_ZN7miptlib4meanERKSt6vectorIdSaIdEE");
    
    std::cout << add(3, 4) << std::endl;
    std::cout << power(2, 5) << std::endl;
    std::cout << circleArea(5) << std::endl;

    std::vector<double> data = {1, 2, 3, 4, 5};

    std::cout << mean(data) << std::endl;
    
    dlclose(handle);
}