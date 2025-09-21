#include <stdio.h>
#define MAX 100

void assign(int A[MAX][MAX], int B[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = B[i][j];
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX];
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &B[i][j]);
        }
    }
    
    assign(A, B, n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.0f ", A[i][j]);
        }
        printf("\n");
    }
}