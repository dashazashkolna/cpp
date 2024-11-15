#include <iostream>
#include <fstream>
using namespace std;

class Vector {

private:
    int size;
    double* elements;

public:
    Vector(int n) {
        size = n;
        elements = new double[size];
    }

    Vector(const Vector& other) {
        size = other.size;
        elements = new double[size];
        for (int i = 0; i < size; i++) {
            elements[i] = other.elements[i];
        }
    }

    void input() {
        cout << "Введіть елементи вектора розмірністю " << size << ": ";
        for (int i = 0; i < size; i++) {
            cin >> elements[i];
        }
    }

    void setElement(int index, double value) {
        if (index >= size) throw logic_error("Індекс виходить за межі вектора");
        else elements[index] = value;
    }

    void print(const char* filename) {
        ofstream file(filename);
        if (!file.good()) exit(1);
        for (int i = 0; i < size; i++) {
            file << elements[i] << " ";
        }
        file.close();
    }

    double scalar_product(const Vector& other) {

        if (size != other.size)
            throw logic_error("Неможливо порахувати скалярний добуток (різні розмірності)");
        double scalar = 0;
        for (int i = 0; i < size; i++) {
            scalar += (elements[i] * other.elements[i]);
        }

        return scalar;
    }

    Vector cross_product(const Vector& other) {
        if (size != 3 || other.size != 3)
            throw logic_error("Векторний добуток викуонється лише в тривимірному просторі");

        Vector res(3);
        res.elements[0] = elements[1] * other.elements[2] - elements[2] * other.elements[1];
        res.elements[1] = elements[0] * other.elements[2] - elements[2] * other.elements[0];
        res.elements[2] = elements[0] * other.elements[1] - elements[1] * other.elements[0];

        return res;

    }

    ~Vector() {
        delete[] elements;
    }
};

int main() {
    cout << "Введіть розмірність: ";
    int n;
    cin >> n;
    Vector v1(n);
    v1.input();
    v1.print("output.txt");
    v1.setElement(0, 14.99);

    Vector v2(n);
    v2.input();
    cout << v1.scalar_product(v2);
    Vector v3(3);
    v3 = v1.cross_product(v2);
    v3.print("output.txt");

    return 0;

}