#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num:nums) {
            if(seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    Solution solution;
    cout << boolalpha << solution.hasDuplicate(nums) << '\n';
    return 0;
}
