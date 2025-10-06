#include <math.h>

int solve_quadratic(double a, double b, double c, double* px1, double* px2)
{
    double eps = 1e-10;
    double d = b * b - 4 * a * c;
    
    if (d < -eps) {
        return 0;
    }
    else if (fabs(d) < eps) {
        *px1 = -b / (2 * a);
        return 1;
    }
    else {
        double sqrt_d = sqrt(d);
        *px1 = (-b - sqrt_d) / (2 * a);
        *px2 = (-b + sqrt_d) / (2 * a);
        return 2;
    }
}