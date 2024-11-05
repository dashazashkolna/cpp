#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string input;
    string word;
    vector<string> longest;
    int max_size = 0;
    cout << "Введіть речення: ";
    getline(cin, input);
    istringstream inp(input);

    while (inp >> word) {
        if (word.size() > max_size) {
            longest.clear();
            max_size = word.size();
            longest.push_back(word);
        } else if (word.size() == max_size) {
            longest.push_back(word);
        }
    }

    cout << "Найдовше слово(а): ";
    for (const string& w : longest) {
        cout << w << " ";
    }

    return 0;
}