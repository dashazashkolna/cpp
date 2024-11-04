#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

class LinearEquation {
protected:
    double a, b;

public:
    LinearEquation(double a = 0, double b = 0) : a(a), b(b) {}

    virtual bool hasInfiniteSolutions() const {
        return a == 0 && b == 0;
    }

    virtual bool hasRealSolutions() const {
        return a != 0 || b == 0;
    }

    virtual vector<double> findRealSolutions() const {
        vector<double> solutions;
        if (a != 0) {
            solutions.push_back(-b / a);
        }
        return solutions;
    }

    virtual void print() const {
        cout << "Лінійне: " << a << "x + " << b << " = 0" << endl;
    }
};

class QuadraticEquation : public LinearEquation {
protected:
    double c;

public:
    QuadraticEquation(double a = 0, double b = 0, double c = 0) : LinearEquation(a, b), c(c) {}

    bool hasInfiniteSolutions() const override {
        return false;
    }

    bool hasRealSolutions() const override {
        double discriminant = b * b - 4 * a * c;
        return discriminant >= 0;
    }

    vector<double> findRealSolutions() const override {
        vector<double> solutions;
        double discriminant = b * b - 4 * a * c;
        if (discriminant >= 0) {
            double sqrtDiscriminant = sqrt(discriminant);
            solutions.push_back((-b + sqrtDiscriminant) / (2 * a));
            solutions.push_back((-b - sqrtDiscriminant) / (2 * a));
        }
        return solutions;
    }

    void print() const override {
        cout << "Квадратне: " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
    }
};

class BiquadraticEquation : public QuadraticEquation {
public:
    BiquadraticEquation(double a = 0, double b = 0, double c = 0) : QuadraticEquation(a, b, c) {}

    bool hasInfiniteSolutions() const override {
        return false;
    }

    vector<double> findRealSolutions() const override {
        vector<double> solutions;
        double discriminant = b * b - 4 * a * c;
        if (discriminant >= 0) {
            double sqrtDiscriminant = sqrt(discriminant);
            double x1 = (-b + sqrtDiscriminant) / (2 * a);
            double x2 = (-b - sqrtDiscriminant) / (2 * a);

            if (x1 >= 0) {
                solutions.push_back(sqrt(x1));
                solutions.push_back(-sqrt(x1));
            }
            if (x2 >= 0) {
                solutions.push_back(sqrt(x2));
                solutions.push_back(-sqrt(x2));
            }
        }
        return solutions;
    }

    void print() const override {
        cout << "Біквадратне: " << a << "x^4 + " << b << "x^2 + " << c << " = 0" << endl;
    }
};

void findInfiniteSolutionsEquations(const vector<LinearEquation*>& equations) {
    cout << "Рівняння з нескінченною кількістю розв'язків:" << endl;
    for (const auto& eq : equations) {
        if (eq->hasInfiniteSolutions()) {
            eq->print();
        }
    }
}

int countNoRealSolutions(const vector<LinearEquation*>& equations) {
    int count = 0;
    for (const auto& eq : equations) {
        if (!eq->hasRealSolutions()) {
            count++;
        }
    }
    return count;
}

double findSmallestRealSolution(const vector<LinearEquation*>& equations) {
    double minSolution = numeric_limits<double>::max();
    for (const auto& eq : equations) {
        vector<double> solutions = eq->findRealSolutions();
        for (double solution : solutions) {
            if (fabs(solution) < fabs(minSolution)) {
                minSolution = solution;
            }
        }
    }
    return (minSolution == numeric_limits<double>::max()) ? NAN : minSolution;
}

double sumOfSquaresOfRealSolutions(const vector<LinearEquation*>& equations) {
    double sumSquares = 0.0;
    for (const auto& eq : equations) {
        vector<double> solutions = eq->findRealSolutions();
        for (double solution : solutions) {
            sumSquares += solution * solution;
        }
    }
    return sumSquares;
}

int main() {
    ifstream file("equations.txt");
    if (!file) {
        cerr << "Неможливо відкрити файл" << endl;
        return 1;
    }

    vector<LinearEquation*> equations;
    int type;
    double a, b, c;

    while (file >> type) {
        if (type == 1) {  // Лінійне рівняння
            file >> a >> b;
            equations.push_back(new LinearEquation(a, b));
        } else if (type == 2) {  // Квадратне
            file >> a >> b >> c;
            equations.push_back(new QuadraticEquation(a, b, c));
        } else if (type == 3) {  // Біквадратне
            file >> a >> b >> c;
            equations.push_back(new BiquadraticEquation(a, b, c));
        }
    }

    file.close();

    findInfiniteSolutionsEquations(equations);
    cout << "К-сть рівнянь, які не мають дійсних коренів: " << countNoRealSolutions(equations) << endl;

    double smallestSolution = findSmallestRealSolution(equations);
    if (!isnan(smallestSolution)) {
        cout << "Найменший за модулем корінь: " << smallestSolution << endl;
    }

    double sumSquares = sumOfSquaresOfRealSolutions(equations);
    cout << "Сума квадратів всіх дійсних розв'язків: " << sumSquares << endl;

    for (auto& eq : equations) {
        delete eq;
    }

    return 0;
}

