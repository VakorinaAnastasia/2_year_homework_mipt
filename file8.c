#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int numbers[1000];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
}