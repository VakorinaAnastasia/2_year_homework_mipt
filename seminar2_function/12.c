#include <stdio.h>
#define MAX 100

void assign(int A[MAX][MAX], int B[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = B[i][j];
        }
    }
}

void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    int x[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x[i][j] = 0;
            for (int k = 0; k < n; k++) {
                x[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    assign(C, x, n);
}

void power(int A[MAX][MAX], int C[MAX][MAX], int n, int k) {
    int B[MAX][MAX];
    
    assign(B, A, n);
    assign(C, A, n);
    
    for (int i = 1; i < k; i++) {
        multiply(A, B, C, n);
        assign(B, C, n);
    }
}

int main() {
    int A[MAX][MAX], C[MAX][MAX];
    int n, k;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    scanf("%d", &k);
    
    power(A, C, n, k);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}