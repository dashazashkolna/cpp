#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float price;
    int min_age;
    int max_age;
} Toy;

void res_toy(FILE *file, float y, int x) {
    Toy toy;
    int found = 0;
    FILE *output = fopen("output.bin", "wb");

    if (!output) exit(1);

    while (fscanf(file, "%s %f %d %d", toy.name, &toy.price, &toy.min_age, &toy.max_age) == 4) {
        if (strcmp(toy.name, "Конструктор") == 0 &&
            toy.price == y && toy.min_age <= x
            && toy.max_age >= 12) {
                printf("Знайдено: %s, %.2f грн\n", toy.name, toy.price);
                fwrite(&toy, sizeof(Toy), 1, output);
                found = 1;
        }
    }

    if (!found) {
        printf("Не знайдено таку іграшку\n");
    }

    fclose(output);
}

int main() {
    FILE *file = fopen("input12.txt", "r");

    if (!file) exit(1);

    float y;
    int x;
    printf("Введіть ціну Y: ");
    scanf("%f", &y);
    printf("Введіть мінімальний вік x: ");
    scanf("%d", &x);

    res_toy(file, y, x);
    fclose(file);

    return 0;
}
