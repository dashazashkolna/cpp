#include <stdio.h>
#include <math.h>

int main() {

    int n;
    printf("Розмір масиву: ");
    scanf("%d", &n);
    float array[n], min_a, max_a;

    for (int i = 1; i <= n; i++) {
        scanf("%f", &array[i]);

        if (i % 2 == 0) {
            if (i == 2) {
                min_a = array[i];
            } else if (min_a > array[i]) {
                min_a = array[i];
            }
        } else {
            if (i == 1) {
                max_a = array[i];
            } else if (max_a < array[i]) {
                max_a = array[i];
            }
        }
    }

    printf("%f\n", min_a + max_a);

    return 0;
}

