#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    scanf("%i", &n);
    int max = INT_MIN;
    int N = 0;
    
    for (int i = 0; i < n; ++i)
    {
        int a;
        scanf("%i", &a);
        
        if (a > max)
        {
            max = a;
            N = 1;
        }
        else if (a == max)
        {
            N++;
        }
    }
    printf("%i %i\n", max, N);
}
