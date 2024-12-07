#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    size_t rows, cols;

public:
    // Конструктор для створення матриці заданого розміру
    Matrix(size_t r, size_t c, T value = T())
        : rows(r), cols(c), data(r, std::vector<T>(c, value)) {}

    // Конструктор від вектора векторів
    Matrix(const std::vector<std::vector<T>>& d)
        : rows(d.size()), cols(d.empty() ? 0 : d[0].size()), data(d) {}

    // Метод для доступу до елементів
    T& at(size_t r, size_t c) {
        if (r >= rows || c >= cols)
            throw std::out_of_range("Індекс виходить за межі матриці!");
        return data[r][c];
    }

    const T& at(size_t r, size_t c) const {
        if (r >= rows || c >= cols)
            throw std::out_of_range("Індекс виходить за межі матриці!");
        return data[r][c];
    }

    // Дружній оператор << для виведення матриці
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (const auto& row : matrix.data) {
            for (const auto& elem : row) {
                os << elem << " ";
            }
            os << "\n";
        }
        return os;
    }

    // Оператор + для додавання матриць
    friend Matrix operator+(const Matrix& a, const Matrix& b) {
        if (a.rows != b.rows || a.cols != b.cols)
            throw std::invalid_argument("Розміри матриць не збігаються для додавання!");
        Matrix result(a.rows, a.cols);
        for (size_t i = 0; i < a.rows; ++i) {
            for (size_t j = 0; j < a.cols; ++j) {
                result.data[i][j] = a.data[i][j] + b.data[i][j];
            }
        }
        return result;
    }

    // Оператор * для множення матриці на вектор
    friend std::vector<T> operator*(const Matrix& matrix, const std::vector<T>& vec) {
        if (matrix.cols != vec.size())
            throw std::invalid_argument("Кількість стовпців матриці не збігається з розміром вектора!");
        std::vector<T> result(matrix.rows, T());
        for (size_t i = 0; i < matrix.rows; ++i) {
            for (size_t j = 0; j < matrix.cols; ++j) {
                result[i] += matrix.data[i][j] * vec[j];
            }
        }
        return result;
    }

    // Оператор * для множення матриць
    friend Matrix operator*(const Matrix& a, const Matrix& b) {
        if (a.cols != b.rows)
            throw std::invalid_argument("Кількість стовпців першої матриці не збігається з кількістю рядків другої!");
        Matrix result(a.rows, b.cols, T());
        for (size_t i = 0; i < a.rows; ++i) {
            for (size_t j = 0; j < b.cols; ++j) {
                for (size_t k = 0; k < a.cols; ++k) {
                    result.data[i][j] += a.data[i][k] * b.data[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    try {
        Matrix<int> mat1({
            {1, 2, 3},
            {4, 5, 6}
        });

        Matrix<int> mat2({
            {7, 8},
            {9, 10},
            {11, 12}
        });

        Matrix<int> mat3({
            {1, 2, 3},
            {4, 5, 6}
        });

        std::cout << "Матриця 1:\n" << mat1;
        std::cout << "Матриця 2:\n" << mat2;

        // Додавання матриць
        std::cout << "Матриця 1 + Матриця 3:\n" << (mat1 + mat3);

        // Множення матриці на вектор
        std::vector<int> vec = {1, 2, 3};
        auto resultVec = mat1 * vec;
        std::cout << "Матриця 1 * Вектор: ";
        for (int val : resultVec) {
            std::cout << val << " ";
        }
        std::cout << "\n";

        // Множення матриць
        std::cout << "Матриця 1 * Матриця 2:\n" << (mat1 * mat2);

        Matrix<float> matFloat({
            {1.5, 2.5},
            {3.5, 4.5}
        });
        std::cout << "Матриця float:\n" << matFloat;

    } catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}
