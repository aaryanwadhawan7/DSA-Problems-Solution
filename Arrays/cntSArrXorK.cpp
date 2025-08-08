// Count number of subarrays with XOR as k

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int countSubArrays (vector<int> &nums, int n, int k) {
    // Similar to prefixSum Approach
    int count = 0;
    int XOR = 0;
    unordered_map <int, int> mpp;
    mpp [0] = 1;
    // Prefix XOR -> Count
    for (int i = 0; i < n; i++) {
        XOR = XOR ^ nums[i];
        int findPrefixXOR = XOR ^ k;
        if (mpp.find(findPrefixXOR) != mpp.end()) {
            count += mpp[findPrefixXOR];
        }

        mpp[XOR]++;
    }

    return count;
}

int main () {
    vector <int> nums = {  4  ,  2  ,  2  ,  6  ,  4  };
    //                     | -> x      | -> k      | -> xr  
    // x ^ k = xr : For subarray to be xor as k then there should exist prefix subarray with xor val as x
    int n = nums.size();
    int k = 6;
    int res = countSubArrays (nums, n, k);
    cout << res << endl;
    return 0;
}