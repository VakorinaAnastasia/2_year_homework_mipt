#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *text = argv[1];
    int times = atoi(argv[2]);
    
    if (times <= 0) {
        return 0;
    }
    
    for (int i = 0; i < times; i++) {
        printf("%s", text);
        if (i < times - 1) {
            printf(" ");
        }
    }
}