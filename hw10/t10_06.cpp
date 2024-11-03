#include <iostream>
using namespace std;

struct Circle {
    double r;
    double coords[2];
};

void input_circle(Circle &circle) {
    cout << "радіус кола: ";
    cin >> circle.r;
    cout << "координати центру: ";
    cin >> circle.coords[0] >> circle.coords[1];
}

void print_circle(Circle &circle) {
    cout << "радіус кола: " << circle.r << endl;
    cout << "координати центру: (" << circle.coords[0] << ", " << circle.coords[1] << ")" << endl;
}

int main() {

    Circle circle;
    input_circle(circle);
    print_circle(circle);
    return 0;
}