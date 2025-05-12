#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> nums, int target) {
    vector<int> result;
    int n = nums.size();
    int i=0, j = n-1;
    while(i<j){
        int pairSum = nums[i] + nums[j];
        if(pairSum>target){
            j--;
        } else if(pairSum<target){
            i++;
        } else{
            result.push_back(i);
            result.push_back(j);
            return result;
        }
    }
    return result;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 13;
    vector<int> result = pairSum(nums, target);
    cout << result[0] << ", " << result[1] << endl;
    return 0;
}