#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int length = 1;
    int max = N;
    printf("%d", N);

    while (N > 1) {
        if (N % 2 == 1) {
            N = 3 * N + 1;
        } else {
            N = N / 2;
        }
        
        printf(" %d", N);
        length++;
        
        if (N > max) {
            max = N;
        }
    }
    printf("\nLength = %d, Max = %d\n", length, max);
}