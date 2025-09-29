#include <stdio.h>

int main() {
    char c;
    scanf("%c", &c);
    
    if (c >= 'A' && c <= 'Z') 
        puts("Letter");
    else if (c >= 'a' && c <= 'z') 
        puts("Letter");
    else if (c >= '0' && c <= '9') 
        puts("Digit");
    else 
        puts("Other");
}