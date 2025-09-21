#include <stdio.h>

int sum_of_digits(int x)
{
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int sum_of_digits_rec(int x)
{
    if (x == 0) return 0;
    return x % 10 + sum_of_digits_rec(x / 10);
}

int main()
{
    int x;
    scanf("%d", &x);
    printf("%i\n",sum_of_digits_rec(x));
}