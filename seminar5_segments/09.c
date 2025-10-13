#include <stdio.h>

int adder(int n) {
    static int total = 0;
    total += n;
    return total;
}

int main() {
    printf("%i\n", adder(10));
    printf("%i\n", adder(15));
    printf("%i\n", adder(70));
}