#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if ((a & b) == 0) {
        cout << "числа не мають одиничних бітів на однакових позиціях." << endl;
    } else {
        cout << "числа мають одиничні біти на однакових позиціях." << endl;
    }

    return 0;
}
