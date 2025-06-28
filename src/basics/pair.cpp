#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<int, int>> v = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    // sort by first element
    sort(v.begin(), v.end());
    cout << "Sorted by first element:" << endl;
    for (const auto& p : v) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
    // sort by second element
    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    cout << "Sorted by second element:" << endl;
    for (const auto& p : v) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}

