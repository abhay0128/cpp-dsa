#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int n = nums.size();

    for (int i = 0; i < n - 2; ++i) {
        if (nums[i] > 0)
            break;

        if (i == 0 || nums[i] != nums[i - 1]) {
            int low = i + 1, high = n - 1;

            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];

                if (sum < 0) {
                    ++low;
                } else if (sum > 0) {
                    --high;
                } else {
                    result.push_back({nums[i], nums[low], nums[high]});
                    ++low;
                    --high;

                    while (low < high && nums[low] == nums[low - 1])
                        ++low;
                    while (low < high && nums[high] == nums[high + 1])
                        --high;
                }
            }
        }
    }

    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> triplets = threeSum(nums);

    cout << "Unique triplets that sum to zero:\n";
    for (const auto& triplet : triplets) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); ++i) {
            cout << triplet[i];
            if (i != triplet.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}