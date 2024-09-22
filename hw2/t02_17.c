#include <stdio.h>
#include <math.h>

float softPlus(float);
float softPlus_derivative(float);

int main() {
    float x;
    scanf("%f", &x);
    float res = softPlus(x);
    float der = softPlus_derivative(x);
    printf("function: %f, derivative: %f\n", res, der);
}

float softPlus(float x) {
    return log(1 + pow(exp(1), x));
}

float softPlus_derivative(float x) {
    return pow(exp(1), x) / (1 + pow(exp(1), x));
}