#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    ifstream finp;
    ofstream fout;

    finp.open("input.txt");
    fout.open("output.txt");
    double mult = 1;
    int k = 0;

    while (!finp.eof()) {
        double num;
        finp >> num;
        mult *= num;
        k += 1;
    }

    fout << pow(mult, 1.0/k);

    finp.close();
    fout.close();

    return 0;
}