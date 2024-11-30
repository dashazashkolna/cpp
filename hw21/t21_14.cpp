#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

struct MonthConverter {
    map<string, int> monthMap = {
        {"January", 1}, {"February", 2}, {"March", 3}, {"April", 4},
        {"May", 5}, {"June", 6}, {"July", 7}, {"August", 8},
        {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}
    };

    int operator()(const string& month) const {
        if (isdigit(month[0])) {
            return stoi(month);
        }
        return monthMap.at(month);
    }
};

struct DateComparator {
    MonthConverter converter;

    bool operator()(const tuple<int, int, int>& d1, const tuple<int, int, int>& d2) const {
        if (get<2>(d1) != get<2>(d2)) return get<2>(d1) < get<2>(d2);
        if (get<1>(d1) != get<1>(d2)) return get<1>(d1) < get<1>(d2);
        return get<0>(d1) < get<0>(d2);
    }
};

int main() {
    ifstream inputFile("dates.txt");
    if (!inputFile) {
        cerr << "Error: Cannot open file!" << endl;
        return 1;
    }

    set<tuple<int, int, int>, DateComparator> uniqueDates{DateComparator()};
    MonthConverter monthConverter;

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        int day, year;
        string month;

        ss >> day >> month >> year;

        int monthNum = monthConverter(month);
        uniqueDates.emplace(day, monthNum, year);
    }

    inputFile.close();

    for (const auto& date : uniqueDates) {
        cout << get<2>(date) << "/" << get<1>(date) << "/" << get<0>(date) << endl;
    }

    return 0;
}
