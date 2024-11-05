#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    string input;
    double num;
    getline(cin, input);
    istringstream inp(input);

    while (inp >> num) {
        if (num > 0) {
            cout << dec << setw(3) << log(num) << " ";
            cout << scientific << log(num) << endl;
            cout.copyfmt(ios(nullptr));
            
        } else {
            cout << "None ";
        }

        inp.ignore(1, ',');
    }
    return 0;
}