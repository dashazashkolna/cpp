#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>

int main() {
    std::string name;
    std::vector<int> V;
    int n, temp;

    std::cin >> name >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> temp;
        V.push_back(temp);
    }

    std::set<int> first_half(V.begin(), V.begin() + n / 2);
    std::set<int> second_half(V.begin() + n / 2, V.end());
    std::vector<int> result;

    std::set_difference(second_half.begin(), second_half.end(),
                        first_half.begin(), first_half.end(),
                        std::back_inserter(result));

    std::sort(result.begin(), result.end());

    std::ofstream outfile(name);
    for (int num : result) {
        outfile << num << "\n";
    }

    return 0;
}