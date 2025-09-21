#include <stdio.h>

void trib(int n) 
{
    if (n == 0 || n == 1) {
        printf("0");
    } else if (n == 2) {
        printf("1");
    } else {
        int a = 0, b = 0, c = 1;
        int result = 0;
        
        for (int i = 3; i <= n; i++) {
            result = a + b + c;
            a = b;
            b = c;
            c = result;
        }
        printf("%d", result);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    trib(n);
}