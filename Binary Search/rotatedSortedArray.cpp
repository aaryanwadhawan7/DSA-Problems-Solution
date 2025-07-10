// 1. Rotated Sorted Array with Unique Elements
// 2. Rotated Sorted Array with Duplicate Elements
// 3. Find minimum in rotated sorted array if there are duplicate elements
// 4. Find out how many number of times array is rotated

/*

index =               0     1     2     3     4     5     6    7
vector <int> nums = {  4  ,  5  ,  6  ,  7  ,  0  ,  1  ,  2  , 3  }
                      low               mid                     high


*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int search(vector<int> &nums, int n, int target)
{
    int index = -1;
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            index = mid;
        }
        // identify sorted part
        // equality condition won't hold since we are considering unique elements

        // left sorted
        if (nums[low] < nums[mid])
        {
            if (target >= nums[low] && target <= nums[mid])
            {
                // target lies b/w low and mid
                high = mid - 1;
            }
            else
            {
                // target doesn't lie between low and mid
                low = mid + 1;
            }
        }
        else if (nums[mid] < nums[high])
        {
            // right sorted
            if (target >= nums[mid] && target <= nums[high])
            {
                // target lies b/w mid and high
                low = mid + 1;
            }
            else
            {
                // target doesn't lies b/w mid and high
                high = mid - 1;
            }
        }
    }
    return index;
}

bool searchDuplicate (vector<int> &nums2, int n2, int target) {
    int low = 0;
    int high = n2 - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // eliminate duplicate elements -> trim the search space
        if (nums2[low] == nums2[mid] && nums2[mid] == nums2[high]) {
            low ++;
            high --;
            continue;
        }

        // curr == target
        if (nums2[mid] == target) {
            return true;
        }

        // eliminate half -> either right or left half
        if (nums2[low] <= nums2[mid]) {
            // left part is sorted
            if (target <= nums2[mid] && target >= nums2[low]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else if (nums2[mid] <= nums2[high]) {
            if (target <= nums2[high] && target >= nums2[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return false;
}


int searchMinDuplicate (vector<int> &nums2, int n2) {
    // Search minimum and Sorted -> Binary Search

    int low = 0;
    int high = n2 - 1;
    int mini = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        // Eliminate half (either left half / right half)
        if (nums2[low] == nums2[mid]) {
            // (curr) element == (curr + 1) element
            low ++;
            continue;
        }

        if (nums2[low] <= nums2[mid]) {
            // left half is sorted
            // leftmost element might have the ans
            mini = min(mini , nums2[low]);
            // search in right
            low = mid + 1;
        } else if (nums2[mid] <= nums2[high])  {
            // right half is sorted
            mini = min (mini, nums2[mid]);
            high = mid - 1;
        }
    }

    return mini;
}

int numberRotation (vector<int> &vec, int vecSize) {
    int low = 0;
    int high = vecSize - 1;
    int minIndex = vecSize;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        // elimination (left half / right half)

        if (vec[low] <= vec[mid]) {
            // left half sorted
            minIndex = low;
            low = mid + 1;
        } else if (vec[mid] <= vec[high]) {
            // right half sorted
            minIndex = mid;
            high = mid - 1;
        }
    }

    return minIndex;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 3};
    vector<int> nums2 = {4 , 5, 5, 5, 6, 7, 9, 10};
    vector<int> vec = {7, 8, 9, 1, 2, 3, 4, 5, 6};

    int n = nums.size();
    int n2 = nums.size();
    int vecSize = vec.size();

    //int target;
    //cin >> target;
    //int index = search(nums, n, target);
    //bool index2 = searchDuplicate(nums2,n2,target);
    // cout << "Element " << target << " is present at " << index2 << endl;
    //cout << index2 << endl;

    cout << numberRotation(vec,vecSize) << endl;

    return 0;
}