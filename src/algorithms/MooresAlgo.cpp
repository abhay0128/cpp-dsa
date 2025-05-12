#include <iostream>
#include <vector>
using namespace std;

// Moore's Voting Algorithm to find majority element

class Solution {
    public:
    int majorityElement(vector<int>& nums) {
        
        int freq = 1, result = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(freq == 0){
                result = nums[i];
            }
            if(result == nums[i]){
                freq++;
            } else {
                freq--;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2, 1, 1};
    int result = sol.majorityElement(nums);
    cout << "result:" << result << endl;
    return 0;
}