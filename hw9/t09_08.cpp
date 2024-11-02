#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

double* input(int n) {
    double* a = (double*) malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

void print(double* arr, int n) {
    cout << "Елементи масиву: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

double mean(double* arr, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

void variance(double* arr, int n, double mean) {
    cout << "Дисперсія: ";
    for (int i = 0; i < n; i++) {
        cout << abs(arr[i] - mean) << " ";
    }
    cout << endl;
}

int main() {
    for (int i = 1; i < 4; i++) {
        int n;
        cout << "Розмірність " << i << ": ";
        cin >> n;

        double* arr = input(n);

        print(arr, n);

        double avg = mean(arr, n);
        cout << "Середнє арифметичне: " << avg << endl;

        variance(arr, n, avg);

        free(arr);
    }

    return 0;
}
