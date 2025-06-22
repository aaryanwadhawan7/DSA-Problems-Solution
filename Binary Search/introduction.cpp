// Linear Search : unsorted and unique elements

#include <iostream>
using namespace std;

int linearSearch (int arr[], int size, int target) {
    for(int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    // target element not found yet
    return -1;
}

// Binary Search : sorted and unique element

// 1. Real Life Example : Dictionary (linear search, binary search)
// 2. Coding Problem Example
// 3. Iterative Approach
// 4. Recursive Approach
// 5. Time Complexity : O(logn(base-2))
// 6. Overflow case : either use (long long) datatype for mid or define mid as 
// mid = low + (high - low) / 2

int binarySearch (int brr[] ,int size_brr ,int target) {
    // 2-pointer approach : 
    // low and high ptr [Defines the search space]
    // mid [Decides the position of the target element]

    int low = 0, high = size_brr - 1;

    // LOGIC
    // we will iterate until search space bw low and high is defined...
    while (low <= high) {
        int mid = (low + high) / 2;

        if (brr[mid] == target) {
            return mid;
        } else {
            if (brr[mid] > target) {
                // search in left part of the arr
                high = mid - 1;
            } else {
                // search in right part of arr
                low = mid + 1;
            }
        }
    }

    return -1;
}

int binarySearchRecursion (int brr[], int size_brr, int low, int high, int target) {
    int mid = (low + high) / 2;

    // base case
    if (low > high) {
        // target element not found
        return -1;
    }

    // Handling Single case 
    if (brr[mid] == target) {
        return mid;
    } else {
        if (brr[mid] > target) {
            // search in the right part of brr
            return binarySearchRecursion(brr,size_brr,low,mid - 1,target);
        } 
    }
    return binarySearchRecursion(brr,size_brr,mid+1,high,target);
}

int main () {

    int arr[] = {1,3,4,5,7};
    int brr[] = {3,4,6,7,9,12,16,17};
    

    int size = sizeof (arr) / sizeof (arr[0]);
    int size_brr = sizeof (brr) / sizeof (brr[0]);
    int target;
    cin >> target;

    // this will give use the position of the target element
    // int index = linearSearch (arr, size, target);
    // int index = binarySearch(brr,size_brr,target);

    int index = binarySearchRecursion(brr,size_brr,0,size_brr-1,target);
    cout << index << endl;

    // if (index != -1) {
    //     cout << "Target Element is present at " << index << " !" << endl;
    // } else {
    //     cout << "Target Element is not present in the array." << endl;
    // }

    return 0;
}