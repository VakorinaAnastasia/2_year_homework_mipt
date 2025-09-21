#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    
    if ((num >= 0 && num <= 20) || (num > 100 && num < 200)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}
