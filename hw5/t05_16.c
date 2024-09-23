#include <stdio.h>
#include <math.h>

int main() {
    double x, epsilon, term = 1.0, sum = 1.0;
    int cur_sign = 1, n = 1;
    double power = 1;
    printf("x = ");
    scanf("%lf", &x);
    printf("eps = ");
    scanf("%lf", &epsilon);

    while (fabs(term) >= epsilon) {
        n++;
        power *= x;
        cur_sign *= (-1);
        term = cur_sign * power * n;
        sum += term;
    }
    printf("1/((1+x)^2) = %lf\n", sum);

    return 0;
}