#include <stdio.h>
#include <math.h>

double gamma(double x) {
    double step = 0.01;
    double eps = 1e-10;
    double result = 0.0;
    double t = step;
    
    while (1) {
        double f_prev = pow(t - step, x - 1) * exp(-(t - step));
        double f_curr = pow(t, x - 1) * exp(-t);
        double area = (f_prev + f_curr) * step / 2;
        
        if (area < eps && t > 10) {
            break;
        }
        
        result += area;
        t += step;
    }
    
    return result;
}

int main() {
    double x;
    scanf("%lf", &x);
    printf("%.6f", gamma(x));
}