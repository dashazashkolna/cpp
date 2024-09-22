#include <stdio.h>

float max(float, float);

int main() {

    float x, y, z;
    scanf("%f %f %f", &x, &y, &z);

    if (max(x*y, x*z) >= y*z) {
        printf("%f", max(x*y, x*z));
    } else {
        printf("%f", y*z);
    }

    return 0;
}

float max(float x, float y) {
    return (x >= y) ? x : y;
}