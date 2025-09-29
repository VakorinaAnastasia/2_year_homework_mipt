#include <stdio.h>

int is_palindrom(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char word[100];
    scanf("%s", word);
    
    if (is_palindrom(word)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}