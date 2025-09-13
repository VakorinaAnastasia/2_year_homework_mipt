#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int i = 0;
    int k = 0;

    while (i < n) {
        if (a[i] >= 0) {
            a[k] = a[i];
            k++;
        }
        i++;
    }
    i = 0;
    while (i < k) {
        printf("%d ", a[i]);
        i++;
    }
}
