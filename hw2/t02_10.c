#include <stdio.h>
#include <math.h>

double angle(float a, float b, float c) {
    double res = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b));
    return res;
}

int main() {
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    double ang1 = angle(a, b, c);
    double ang2 = angle(a, c, b);
    double ang3 = angle(b, c, a);

    printf("Radians: ang1 = %f, ang2 = %f, ang3 = %f\n", ang1, ang2, ang3);
    printf("Degrees: ang1 = %f, ang2 = %f, ang3 = %f\n\n", ang1 * (180.0 / 3.14), ang2 * (180.0 / 3.14), ang3 * (180.0 / 3.14));

    return 0;

}
