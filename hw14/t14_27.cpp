#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void f(const char* input, const char* output) {
    ifstream finp(input);
    ofstream fout(output);
    string line;

    if (!finp.good()) exit(1);

    while (getline(finp, line)) {
        fout << " " << line << endl;
    }

    finp.close();
    fout.close();
}
int main() {
    f("input27.txt", "output27.txt");
    return 0;
}