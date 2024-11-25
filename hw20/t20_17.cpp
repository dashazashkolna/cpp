#include <iostream>
#include <vector>
#include <map>
#include <string>

int main() {
    std::vector<std::string> V;
    std::multimap<char, std::string> M;
    int n;
    std::string word;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> word;
        V.push_back(word);
    }

    for (const auto& str : V) {
        char key = (str.length() > 1) ? str[1] : str[0];
        M.insert({key, str});
    }

    for (const auto& pair : M) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}