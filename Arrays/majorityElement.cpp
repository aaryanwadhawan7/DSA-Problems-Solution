#include <bits/stdc++.h>
using namespace std;

int better(vector<int> &nums) {
    int n = nums.size();
    map<int,int> hashMap; // sc -> O(n) 
    // [key , value] -> [element , cnt]

    // 1. store the vector element frequency
    for (int i = 0; i < n; i++) { // tc -> O(n*log(n))
        hashMap[nums[i]]++;
    }

    for (auto it : hashMap) {
        if (it.second > n/2) {
            return it.first;
        }
    }
    return -1;
}

int optimal (vector<int> &nums) {
    // Moore's Voting Algorithm
    int cnt = 0;
    int el;

    for (int i = 0; i < nums.size(); i++) {
        if (cnt == 0) {
            cnt = 1;
            el = nums[i];
        } else if (el == nums[i]) {
            cnt ++;
        } else {
            cnt --;
        }
    }

    int cnt1 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == el) {
            cnt1 ++;
        }

        if (cnt1 > nums.size()/2) {
            return el;
        }
    }
    return -1;
}

int main () {
    vector <int> nums = {2,2,1,1,1,2,2,2,3};
    // brute -> tc : O(n^2) , sc : O(1)
    // better -> Hashing 
    // int ans = better(nums);
    int res = optimal(nums);
    cout << "Majority element which appears more than N/2 : " << res << endl;
    return 0;
}