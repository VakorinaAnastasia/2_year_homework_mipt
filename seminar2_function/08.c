#include <stdio.h>

void reverse(int array[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int res = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = res;
    }
}

int main() 
{
    int arr1[] = {10, 20, 30, 40, 50};
    reverse(arr1, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    
    int arr2[] = {60, 20, 80, 10};
    reverse(arr2, 4);
    for (int i = 0; i < 4; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
}