#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int numbers[10000];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            int num1 = numbers[j];
            int num2 = numbers[j + 1];
            int sum1 = 0, sum2 = 0;
            
            int temp1 = num1;
            while (temp1 > 0) {
                sum1 += temp1 % 10;
                temp1 /= 10;
            }
            
            int temp2 = num2;
            while (temp2 > 0) {
                sum2 += temp2 % 10;
                temp2 /= 10;
            }

            if (sum1 > sum2) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
}