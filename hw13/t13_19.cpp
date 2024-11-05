#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string input;
    string word;
    vector<string> ings;

    cout << "Введіть речення: ";
    getline(cin, input);
    istringstream inp(input);

    while (inp >> word) {
        if (word.size() >= 4 && word.substr(word.size() - 4) == "ings") {
            ings.push_back(word);
        }
    }

    cout << "Причастя з суфіксом 'ings': ";
    for (const string& ings_word : ings) {
        cout << ings_word << " ";
    }
    cout << endl;

    return 0;
}
