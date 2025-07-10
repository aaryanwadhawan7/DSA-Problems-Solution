#include <iostream>
#include <vector>
using namespace std;

// Return index of the pivot element...

// if ( ( nums[index] > nums[index + 1]) && (nums[index] > nums[index - 1] ) ) then nums[index] is a pivot element

// TC : O(n)
int findPivot (vector<int> &nums, int vecSize) {
    for (int i = 0; i < vecSize; i++) {
        if (nums[i] > nums[i+1] && nums[i] > nums[i-1]) {
            return i;
        }
    }
    return -1;
}

int findPivot2 (vector<int> &nums, int vecSize) {
    int low = 1;
    int high = vecSize - 2;

    // edge cases -> condition for last and first element
    if (vecSize == 1) {
        return 0;
    }

    if (nums[0] > nums[1]) {
        // increasing slope
        return 0;
    }

    if (nums[vecSize-1] > nums[vecSize-2]) {
        // decreasing slope
        return (vecSize - 1);
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) {
            return mid;
        } else if (nums[mid] > nums[mid-1]) {
            // increasing slope
            // search in right 
            low = mid + 1;
        } else if (nums[mid] > nums[mid+1]) {
            // decreasing slope
            // search in left
            high = mid - 1;
        }
    }

    return -1;
}

int main () {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int vecSize = nums.size();
    int pivotElementIndex = findPivot2(nums,vecSize);
    cout << pivotElementIndex << endl;
    return 0;
}