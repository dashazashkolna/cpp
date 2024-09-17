 #include <stdio.h>

int main() {

    float first = 1.0 / (1.0 + 1.0 / 3.0);
    float second = 4.0 + 1.0 / (7.0 + first);
    float result = 1.0 / second;

    printf("%f\n", result + 365);

    return 0;
}