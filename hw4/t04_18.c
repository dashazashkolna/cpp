#include <stdio.h>

int main() {
    int k, fact = 1;
    float x, pow = 1;
    printf("k = ");
    scanf("%d", &k);
    printf("x = ");
    scanf("%f", &x);

    int i = 1;
    while (i <= 2*k) {
        fact *= i;
        i++;
    }

    int i2 = 1;
    while (i2 <= 2*k) {
        pow *= x;
        i2++;
    }

    printf("%f", pow / fact);

    return 0;
}