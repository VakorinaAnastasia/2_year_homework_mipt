#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, r1, x2, y2, r2;
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    scanf("%lf %lf %lf", &x2, &y2, &r2);
    
    double dx = x2 - x1;
    double dy = y2 - y1;
    double distance = sqrt(dx*dx + dy*dy);
    double sum = r1 + r2;
    double diff = (r1 > r2) ? (r1 - r2) : (r2 - r1);
    
    if (distance + 1e-5 > sum || distance + 1e-5 < diff) {
        if (distance - 1e-5 < sum && distance + 1e-5 > sum) {
            printf("Touch");
        } else if (distance - 1e-5 < diff && distance + 1e-5 > diff) {
            printf("Touch");
        } else {
            printf("Do not intersect");
        }
    } else {
        printf("Intersect");
    }
}