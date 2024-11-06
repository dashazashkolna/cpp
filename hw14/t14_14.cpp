#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file1("Name1.txt");
    ifstream file2("Name2.txt");
    ofstream output("output14.txt");

    if (!file1.is_open() || !file2.is_open()) {
        exit(1);
    }

    string line_file1, line_file2;

    while (getline(file1, line_file1)) {
        if (!getline(file2, line_file2)) {
            file2.clear();
            file2.seekg(0);
            getline(file2, line_file2);
        }

        output << line_file1 << " " << line_file2 << endl;
    }

    file1.close();
    file2.close();
    output.close();

    return 0;
}
