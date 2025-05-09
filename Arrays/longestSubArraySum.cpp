#include <bits/stdc++.h>
using namespace std;


// Better/ Optiaml [Hashing] -> [positives + negatives + 0's]
// tc : O(N*log(N)) [for ordered map]
// tc : O(N x 1) ~ O(N x N) [for unordered map]
// sc : O(N)


int longestSubArraySum(vector<int> &a, int k) {
    int maxLen = 0;
    int prefixSum = 0;

    map<long long, int> preSumMap; // prefixSum , index 
    for (int i = 0; i < a.size(); i++) {
        prefixSum += a[i];
        if (prefixSum == k) {
            maxLen = max(maxLen,i+1);
        }

        long long  rem = prefixSum - k;
        int length = i - preSumMap.find(rem);
        if(preSumMap.find(rem) == preSumMap.end()) {
            maxLen = max(maxLen,i);
        }
        if (preSumMap.find(prefixSum) == preSumMap.end())
        preSumMap[prefixSum] = i;
    }
    return maxLen;
}


// Brute -> [Find all SubArrays and check if the element sum is equals to k...] -> [positives + Negatives + 0's] 
// tc : O(N x N)


// --------------------------------------------------------------------------------------------------------------


// [positives + 0's]
// Optimal Approach : Go left , Update Sum and if [sum > k] then trim subarray from left 
// 2 Pointer Approach
// tc : O(N) + O(N)

int optimalPositiveAndZero (vector<int> &a , int k) {
    int left = 0;
    int right = 0;
    int maxLen = 0;
    long long sum = a[0];

    while (right < a.size()) {

        while(sum > k && left <= right) {
            // trim the subarray
            sum-=a[left];
            left++;
        }

        if(sum == k) {
            maxLen = max(maxLen,right - left + 1);
        }

        right++;
        if (right < (a.size()))
        sum += a[right];
    }

    return maxLen;
}

int main () {
    vector<int> a = {1,2,3,1,1,1,1,4,2,3,0};
    int k;
    cout << "Give Sum :" << endl;
    cin >> k;

    // cout << "Longest Subarray length with sum k : " << longestSubArraySum(a,k) << endl;
    cout << optimalPositiveAndZero(a,k);
    return 0;
}