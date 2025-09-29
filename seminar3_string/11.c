#include <stdio.h>

void safe_strcpy(char dest[], size_t size, const char src[]) {
    if (size == 0) {
        return;
    }
    
    int i;
    for (i = 0; i < size - 1; i++) {
        if (src[i] == '\0') {
            break;
        }
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

int main() {
    char a[10] = "Mouse";
    char b[50] = "LargeElephant";
    
    safe_strcpy(a, 10, b);
    printf("Result: %s\n", a);
    
}