#include <stdio.h>

void bob(int n);

void alice(int n) {
    n = n * 3 + 1;
    printf("Alice: %d\n", n);
    bob(n);
}

void bob(int n) {
    if (n % 2 == 0) {
        n = n / 2;
        printf("Bob: %d\n", n);
        bob(n);
    } else if (n != 1) {
        alice(n);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    alice(n);/*  */
}