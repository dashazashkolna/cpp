#include <stdio.h>
#include <math.h>

int main() {
    int k = 0;
    double eps, pi = 0, cur_pi;
    printf("eps = ");
    scanf("%lf", &eps);

    do {
        cur_pi = (pow(-1, k) / pow(16, k) *
                 (8.0 / (8 * k + 2) + 4.0 / (8 * k + 3) +
                  4.0 / (8 * k + 4) - 1.0 / (8 * k + 7)));
        pi += cur_pi;
        k++;
    }
    while (fabs(cur_pi) >= eps);

    printf("%lf", pi / 2);

    return 0;
}
