#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    double pi = 0.0;
    
    for (int i = 0; i < n; i++) {
        double term = 1.0 / (2 * i + 1);
        if (i % 2 == 0) {
            pi += term;
        } else {
            pi -= term;
        }
    }
    
    pi *= 4;
    printf("%.10f", pi);
}