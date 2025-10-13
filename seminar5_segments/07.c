#include <stdio.h>
#include <math.h>

int is_negative(int x) { return x < 0; }
int is_even(int x) { return x % 2 == 0; }
int is_square(int x) { 
    int r = sqrt(x);
    return r * r == x; 
}

int count_if(int* a, size_t n, int (*pred)(int)) {
    int cnt = 0;
    for (size_t i = 0; i < n; i++) {
        if (pred(a[i])) cnt++;
    }
    return cnt;
}

int main() {
    int a[] = {89, 81, 28, 52, 44, 16, -64, 49, 52, -79};

    printf("%d\n", count_if(a, 10, is_negative));
    printf("%d\n", count_if(a, 10, is_even));
    printf("%d\n", count_if(a, 10, is_square));
}