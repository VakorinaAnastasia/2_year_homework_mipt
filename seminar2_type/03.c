#include <stdio.h>

float yearfrac(int year, int day) {
    if (year % 4 == 0) {
        return day / 366.0;
    } else {
        return day / 365.0;
    }
}

int main() {
    int year, day;
    scanf("%d %d", &year, &day);
    printf("%.5f", yearfrac(year, day));
}