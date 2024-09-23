#include <stdio.h>

int main() {
    int a1 = 0, a2 = 1, a3, s = 4;
    int n, k = 3, pow = 4;
    scanf("%d", &n);
    while (k <= n) {
        a3 = a2 + k * a1;
        pow *= 2;
        s += (pow * a3);
        a2 = a3;
        a1 = a2;
        k++;
    }
    printf("sn = %d", s);

    return 0;
}