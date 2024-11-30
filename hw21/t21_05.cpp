#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << "Uppercase string: " << str << endl;

    return 0;
}
