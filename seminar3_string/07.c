#include <stdio.h>

void encrypt(char* str, int k) {
    while (*str) {
        if (*str >= 'A' && *str <= 'Z') {
            *str = (*str - 'A' + k) % 26 + 'A';
        } else if (*str >= 'a' && *str <= 'z') {
            *str = (*str - 'a' + k) % 26 + 'a';
        }
        str++;
    }
}

int main() {
    char line[1000];
    int key;
    
    scanf("%d", &key);
    getchar();
    fgets(line, 1000, stdin);
    
    encrypt(line, key);
    printf("%s", line);
}