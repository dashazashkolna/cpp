#include <stdio.h>
#include <math.h>

int main() {

    float data;
    scanf("%f", &data);
    float degree = pow(data, 8);
    printf("%025.4f", degree);

    return 0;

}