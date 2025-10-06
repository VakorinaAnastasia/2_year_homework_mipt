#include <stdio.h>

void mult2_a(int* p, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        *(p + i) = *(p + i) * 2;
    }
}

void mult2_b(int* p, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        p[i] = p[i] * 2;
    }
}