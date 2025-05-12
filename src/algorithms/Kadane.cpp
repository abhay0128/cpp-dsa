#include <iostream>
using namespace std;

// Kadane's Algorithm for Maximum subarray sum
int main() {
    int arr[7] = {3, -4, 5, 4, -1, 7, -8};
    int maxSum = INT_MIN;
    int currSum = 0;

    for(int val: arr) {
        currSum += val;
        maxSum = max(currSum, maxSum);
        if(currSum<0){
            currSum = 0;
        }
    }

    cout<< maxSum << endl;

    return 0;    
}