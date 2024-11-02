#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

double** create_matrix(int n, int m) {
    double **a = (double**) calloc(n, sizeof *a);
    if (a == NULL)
        exit(1);
    for (int i = 0; i < n; i++) {
        a[i] = (double*) calloc(m, sizeof *a[i]);
        if (a[i] == NULL)
            exit(1);
    }
    return a;
}

void fill_matrix(double** a, int n, int m) {
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = rand() % 100 / 10.0;
        }
    }
}

double** add_col(double** a, int n, int m, int k) {
    double** new_matrix = create_matrix(n, m + k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            new_matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            new_matrix[i][j + k] = a[i][j];
        }
    }
    return new_matrix;
}

void print_matrix(double** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void delete_matrix(double** a, int n) {
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
}

int main() {
    int n = 3, m = 4, k = 3;
    double** matrix = create_matrix(n, m);
    fill_matrix(matrix, n, m);

    cout << "Початкова матриця:" << endl;
    print_matrix(matrix, n, m);

    double** new_matrix = add_col(matrix, n, m, k);
    cout << "Модифікована матриця з додатковими стовпчиками:" << endl;
    print_matrix(new_matrix, n, m + k);

    delete_matrix(matrix, n);
    delete_matrix(new_matrix, n);
    return 0;
}
