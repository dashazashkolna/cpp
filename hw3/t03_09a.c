#include <stdio.h>

float max(float, float);

int main() {

    float x, y, z;
    scanf("%f %f %f", &x, &y, &z);
    
    if (max(x+y+z, x*y - x*z + y*z) >= x*y*z) {
        printf("%f", max(x+y+z, x*y - x*z + y*z));
    } else {
        printf("%f", x*y*z);
    }

    return 0;
}

float max(float x, float y) {
    return (x >= y) ? x : y;
}