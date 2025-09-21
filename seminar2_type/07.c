#include <stdio.h>
#include <stdint.h>

int main() {
    printf("char ");
    printf("%d\n", sizeof(char));
    
    printf("long long ");
    printf("%d\n", sizeof(long long));
    
    printf("int32_t ");
    printf("%d\n", sizeof(int32_t));
    
    printf("double ");
    printf("%d\n", sizeof(double));
    
    printf("short ");
    printf("%d\n", sizeof(short));
    
    printf("size_t ");
    printf("%d\n", sizeof(size_t));
    
    printf("uint32_t ");
    printf("%d\n", sizeof(uint32_t));
    
    printf("int[100] ");
    printf("%d\n", sizeof(int[100]));
    
    printf("int ");
    printf("%d\n", sizeof(int));
    
    printf("int8_t ");
    printf("%d\n", sizeof(int8_t));
    
    printf("float ");
    printf("%d\n", sizeof(float));
    
    printf("char[100] ");
    printf("%d\n", sizeof(char[100]));
}