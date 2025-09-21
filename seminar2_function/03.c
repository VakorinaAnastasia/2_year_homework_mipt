#include <stdio.h>

void print_even(int a, int b)
{
    int start = a;
    if (a % 2 != 0) {
        start = a + 1; 
    }
    
    for (int i = start; i <= b; i += 2) {
        printf("%d ", i);
    }
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    print_even(a, b);
    return 0;
}