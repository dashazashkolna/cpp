#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    int num, count = 0;
    file = fopen("input06.txt", "r");

    if (!file)
        exit(1);

    while (fscanf(file, "%d", &num) == 1) {
        if (num % 2 == 0) {
            count++;
        }
    }

    fclose(file);

    printf("%d", count);
}