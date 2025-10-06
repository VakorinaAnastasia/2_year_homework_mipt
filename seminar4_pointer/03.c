#include <stdio.h>

void cube(float* px)
{
    *px = *px * *px * *px;
}

int main()
{
    float a = 5.0f;
    cube(&a);
    printf("%.2f\n", a);
}