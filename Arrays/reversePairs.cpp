// A reverse pair is a pair (i, j) where:
// 1) 0 <= i < j < nums.length
// 2) nums[i] > 2 * nums[j]

# include <iostream>
# include <vector>
using namespace std;

int countPairs (vector<int> &nums, int start, int mid, int end) {
    // Keep iterating over one sorted vector
    // Compare the element with other sorted vector and count reverse pair 
    int count = 0;
    int right = mid + 1;
    for (int left = start; left <= mid; left++) {
        while (right <= end && nums[left] > 2*nums[right]) {
            right ++;
        }
        count += (right - (mid + 1));
    }
    return count;
}

void merge (vector<int> &nums, int start, int mid, int end) {
    int i = start;
    int j = mid + 1;

    vector <int> temp;
    while (i <= mid && j <= end) {
        if (nums[i] <= nums[j]) {
            // nums[i] will come first then nums[j]
            temp.push_back(nums[i]);
            i++;
        } else {
            temp.push_back(nums[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }

    while (j <= end) {
        temp.push_back(nums[j]);
        j++;
    }

    // Push all elements of temp to nums
    int idx = 0;
    for (auto it : temp) {
        nums[idx] = it;
        idx ++;
    }
}

int mergeSort (vector<int> &nums, int start, int end) {
    int count = 0;
    // D&C technique
    if (start < end) {
        int mid = start + (end - start)/2;
        count += mergeSort (nums, start, mid);
        count += mergeSort (nums, mid + 1, end);
        count += countPairs(nums, start, mid, end);
        merge(nums, start, mid, end); // this will return the distort vector back to original form
    }

    return count;
}

int main () {
    vector <int> nums = {1,3,2,3,1};
    int s = nums.size();
    int st = 0, end = s - 1;

    int ans = mergeSort(nums, st, end);

    // for (auto it : nums) {
    //     cout << it << " ";
    // }

    // cout << endl; 

    cout << ans << end;
    return 0;
}