#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000000

int main() {
    getchar();
    printf("1. Allocating memory\n");
    char* data = malloc(SIZE);
    
    getchar();
    printf("2. Setting first char to 'A'\n");
    data[0] = 'A';
    
    getchar();
    printf("3. Setting last char to 'B'\n");
    data[SIZE - 1] = 'B';
    
    getchar();
    printf("4. Printing first char = %c\n", data[0]);
    
    getchar();
    printf("5. Printing last char = %c\n", data[SIZE - 1]);
    
    getchar();
    printf("6. Setting many chars to X\n");
    for (size_t i = 0; i < SIZE; i += 1000)
        data[i] = 'X';
    
    getchar();
    printf("7. Printing all set chars\n");
    for (size_t i = 0; i < SIZE; i += 1000)
        printf("%c ", data[i]);
    
    getchar();
    free(data);
}