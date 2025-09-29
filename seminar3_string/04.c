#include <stdio.h>

int main() {
    char s1[100], s2[100];
    scanf("%s %s", s1, s2);
    
    int i = 0;
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != '\0') {
            putchar(s1[i]);
        }
        if (s2[i] != '\0') {
            putchar(s2[i]);
        }
        i++;
    }
    putchar('\n');
}