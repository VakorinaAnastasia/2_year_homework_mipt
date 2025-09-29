#include <stdio.h>

int main() {
    char digit;
    int sum = 0;
    
    while (scanf("%c", &digit) == 1 && digit != '\n') {
        if (digit >= '0' && digit <= '9') {
            sum += digit - '0';
        }
    }
    
    printf("%d\n", sum);
}