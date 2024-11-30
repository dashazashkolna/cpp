#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

template <typename InputIt, typename OutputIt, typename UnaryOperation, typename Predicate>
OutputIt transform_if(InputIt first, InputIt last, OutputIt d_first, UnaryOperation op, Predicate pred) {
    while (first != last) {
        if (pred(*first)) {
            *d_first++ = op(*first);
        }
        ++first;
    }
    return d_first;
}

int main() {
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> output;

    auto square = [](int x) { return x * x; };
    auto is_even = [](int x) { return x % 2 == 0; };

    transform_if(input.begin(), input.end(), back_inserter(output), square, is_even);

    for (const auto& val : output) {
        cout << val << " ";
    }

    return 0;
}

