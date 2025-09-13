#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int sum[m];
    for (int j = 0; j < m; j++) {
        sum[j] = 0;
    }

    int total = n * m;
    for (int k = 0; k < total; k++) {
        int x;
        scanf("%d", &x);
        sum[k % m] += x;
    }
    for (int j = 0; j < m; j++) {
        printf("%d ", sum[j]);
    }
}
