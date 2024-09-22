#include <stdio.h>
#include <math.h>

double isReLu(double, double);
double isReLu_derivative(double, double);

int main() {
    double a, x;
    scanf("%lf %lf", &a, &x);
    printf("function: %lf derivative: %lf", isReLu(a, x), isReLu_derivative(a, x));

    return 0;
}

double isReLu(double a, double x) {
    if (x < 0) {
        return x / (pow(1+a*x*x, 0.5));
    } else {
        return x;
    }
}

double isReLu_derivative(double a, double x) {
    if (x < 0) {
        return 1 / ((pow(1+a*x*x, 0.5)) * (1 + a*x*x));
    } else {
        return 1;
    }
}