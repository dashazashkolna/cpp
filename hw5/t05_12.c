#include <stdio.h>

int recursive_pow(int base, int exp) {
    if (exp == 0) {
        return 1;
    } else {
        return base * recursive_pow(base, exp - 1);
    }
}

int main() {
    float a1 = 2, a2 = 1, a3;
    float sum = 252;
    float b1 = 1, b2 = 0, b3;
    int n, k = 3;

    scanf("%d", &n);

    while (k <= n) {
        b3 = 2 * b2 + a2;
        a3 = a2 / (k + 1) + a1 + b3;
        sum += (recursive_pow(3, 2 * k + 1) / (a3 * b3 + 1));
        a1 = a2;
        a2 = a3;
        b1 = b2;
        b2 = b3;
        k++;
    }

    printf("sn = %lf", sum);

    return 0;
}