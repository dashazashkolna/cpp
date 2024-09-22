#include <stdio.h>
#include <math.h>

int main() {
    int i = 1, n;
    float x, s = 1.0;
    printf("n = ");
    scanf("%d", &n);
    printf("x = ");
    scanf("%f", &x);

    while (i <= n) {
        s += pow(sin(x), i);
        i++;
    }
    printf("%f", s);

    return 0;
}