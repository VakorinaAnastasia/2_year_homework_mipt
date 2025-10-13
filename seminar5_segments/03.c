#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char* a, const char* b) {
    char* result = malloc(strlen(a) + strlen(b) + 1);
    
    strcpy(result, a);
    strcat(result, b);
    
    return result;
}

int main() {
    char a[100];
    char b[100];
    
    scanf("%s", a);
    scanf("%s", b);
    
    char* result = concat(a, b);
    
    printf("%s\n", result);
    
    free(result);
}