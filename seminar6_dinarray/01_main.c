#include <stdio.h>
#include "dynarray.h"

int main() 
{
    Dynarray a;
    init(&a, 0);
    
    for (int i = 0; i < 100; ++i)
        push_back(&a, i);
        
    print(&a);
    destroy(&a);
}