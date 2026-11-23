#include <iostream>
using namespace std;

// Find out maximum element of the k size window

vector<int> slidingWindowMaximum(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> res;

    // 1st window
    for(int i=0; i<k; i++) {
        while(!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    cout << "Initial deque state: ";
    for (int index : dq) {
        cout << index << " ";
    }
    cout << endl;

    for(int i=k; i<nums.size(); i++) {
        res.push_back(nums[dq.front()]);

        // remove elements which are not part of curr window
        while(!dq.empty() && dq.front() <= i-k) {
            dq.pop_front();
        }

        //remove smaller elements in k range as they are useless
        while(!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    res.push_back(nums[dq.front()]);
    return res;
}

int main() {
    vector<int> nums = {4, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = slidingWindowMaximum(nums, k);
    cout << "Sliding Window Maximums: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}