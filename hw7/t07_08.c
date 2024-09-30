#include <stdio.h>
#include <math.h>

int isPrime(int);

int main() {

    int n, k = 0;
    printf("Розмір масиву: ");
    scanf("%d", &n);
    int array[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);

        int sqrtValue = sqrt(array[i]);
        if (sqrtValue * sqrtValue == array[i] && isPrime(sqrtValue) && array[i] != 1) {
            k++;
        }
    }

    printf("Кількість квадратів простих чисел: %d\n", k);

    return 0;
}

int isPrime(int num) {
    for (int i = 2; i < sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}