#include <stdio.h>
#include <math.h>

int main() {

    printf("Функція y = e^(-x)\n\n");

    int x11 = 1, x12 = 2, x13 = 3, x14 = 4, x15 = 5;
    printf("  x  |  %i  |  %i  |  %i  |  %i  |  %i  |\n", x11, x12, x13, x14, x15);
    printf("-----|-----|-----|-----|-----|-----|\n");
    float y11 = pow(2.72, -x11);
    float y12 = pow(2.72, -x12);
    float y13 = pow(2.72, -x13);
    float y14 = pow(2.72, -x14);
    float y15 = pow(2.72, -x15);
    printf("F(x) |%0.2f |%0.2f |%0.2f |%0.2f |%0.2f |\n\n", y11, y12, y13, y14, y15);



    printf("Функція y = sqrt(x)\n\n");

    int x21 = 1, x22 = 2, x23 = 3, x24 = 4, x25 = 5;
    printf("  x  |  %i  |  %i  |  %i  |  %i  |  %i  |\n", x21, x22, x23, x24, x25);
    printf("-----|-----|-----|-----|-----|-----|\n");
    float y21 = pow(x21, 0.5);
    float y22 = pow(x22, 0.5);
    float y23 = pow(x23, 0.5);
    float y24 = pow(x24, 0.5);
    float y25 = pow(x25, 0.5);
    printf("F(x) |%0.2f |%0.2f |%0.2f |%0.2f |%0.2f |\n\n", y21, y22, y23, y24, y25);
    return 0;

}