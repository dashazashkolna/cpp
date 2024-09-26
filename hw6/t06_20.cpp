#include <iostream>
using namespace std;

int main() {
    int num, pos;
    cin >> num >> pos;
    int first = num >> (pos + 1);
    int second = num & ((1 << pos) - 1);

    int res = (first << pos) | second;

    cout << res << endl;

    return 0;
}
