// Single Element in Sorted Array

#include <iostream>
#include <vector>
using namespace std;

// O(n)
int singleElement(vector<int> &nums)
{
    int size = nums.size();

    if (size == 1)
    {
        return nums[0];
    }

    // check first element
    if (nums[0] != nums[1])
    {
        return nums[0];
    }

    // check last element
    if (nums[size - 1] != nums[size - 2])
    {
        return nums[size - 1];
    }

    // search space -> 1st index to (n-2) index
    for (int i = 1; i < size - 1; i++)
    {
        // ( curr != (curr - 1) ) && ( curr != (curr + 1) )
        if ((nums[i] != nums[i + 1]) && (nums[i] != nums[i - 1]))
        {
            return nums[i];
        }
    }

    return -1;
}

// O(logn)
int singleElement2(vector<int> &nums)
{

    int low = 1;
    int size = nums.size();
    int high = size - 2;

    if (size == 1)
    {
        return nums[0];
    }

    // check first element
    if (nums[0] != nums[1])
    {
        return nums[0];
    }

    // check last element
    if (nums[size - 1] != nums[size - 2])
    {
        return nums[size - 1];
    }

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if ((nums[mid] != nums[mid + 1]) && (nums[mid] != nums[mid - 1]))
        {
            return nums[mid];
        }

        // (even , odd) : curr elemnent is in left part and single element is on the right part
        // (odd , even) : curr element is in the right part and single element is on the left part

        if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
            (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
        {
            // eliminate the left half:
            low = mid + 1;
        }
        // we are in the right:
        else
        {
            // eliminate the right half:
            high = mid - 1;
        }
    }
    
    return -1;
}


    int main()
    {
        vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
        // vector<int> nums2 = { 1 , 1 , 3 , 5 };

        // int ans = singleElement(nums);

        int ans = singleElement2(nums);
        cout << "Single Element in the nums is " << ans << "  ." << endl;

        return 0;
    }