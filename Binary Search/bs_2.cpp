// Lower Bound -> smallest index such that arr[index] >= x 
// Binary Search -> Search and Sorted

#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> &nums, int size, int x) {
    int low = 0, high = size - 1;
    int ans = size;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == x) {
            return mid;
        } else {
            if (nums[mid] >= x) {
                // search in left
                // may be an answer or may not be an answer
                ans = mid;
                high = mid - 1;
            } else {
                // nums[mid] < x
                // search in right
                low = mid + 1;
            }
        }
    }

    return ans;
}

// Upper Bound -> smallest index such that nums[index] > x

int upperBound(vector<int> &nums, int size, int x) {
    int low = 0, high = size - 1;
    int ans = size;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == x) {
            return mid;
        } else {
            if (nums[mid] > x) {
                // search in left
                // may be an answer or may not be an answer
                ans = mid;
                high = mid - 1;
            } else {
                // nums[mid] < x
                // search in right
                low = mid + 1;
            }
        }
    }

    return ans;
}


int main () {
    vector<int>nums = {1,2,2,3,5,8,9,11,13};
    int size = nums.size();
    int x;
    cin >> x;

    int op = lowerBound(nums,size,x);
    int op2 = upperBound(nums,size,x);
    cout << "Lower bound index of x is " << op << " ." << endl;
    cout << "Upper bound index of x is " << op2 << " ." << endl;

    return 0;
}