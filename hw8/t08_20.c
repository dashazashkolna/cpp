#include <stdio.h>

#define N 3
#define M 4


void print_array(int matrix[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matrix[i][j]);
        } printf("\n");
    }
}

void shift(int k, int matrix[N][M]) {
    int new_matrix[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            new_matrix[i][(j + k) % M] = matrix[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = new_matrix[i][j];
        }
    }
}

int main() {
    int matrix[N][M] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    print_array(matrix);
    int k;
    printf("\n Введіть зсув k = ");
    scanf("%d", &k);
    shift(k, matrix);
    printf("\n");
    print_array(matrix);
    return 0;
}