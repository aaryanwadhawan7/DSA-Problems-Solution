// Q1 : Yes or No
// Q2 : Return the Indexes 

#include <bits/stdc++.h>
using namespace std;

// brute q1 and q2 : O(N x N) : Same

// q1better
string q1Better(vector<int> &arr, int target) {
    map<int,int> mpp; 
    // key , value : [target - a] , i 
    for (int i = 0; i < arr.size(); i++) {
        int a = arr[i];
        int b = target - a;
        if (mpp.find(b) != mpp.end()) {
            return "Yes";
        }
        mpp[a] = b;
    }
    return "No";
}

// q2Better and q2Optimized : Same
vector<int> q2Better(vector<int> &arr, int target) {
    map<int , int> mpp; // O(n*log(n))
    for (int i = 0; i < arr.size(); i++) {
        int a = arr[i];
        int b = target - a;
        if (mpp.find(b) != mpp.end()) {
            return {mpp[b],i};
        }
        mpp[a] = i;
    }

    // not found 
    return {-1,-1};
}

// q1Optimized 
string q2Optimized (vector<int> &arr, int target) {

    int right = arr.size() - 1,left = 0;
    sort(arr.begin(), arr.end()); // O(n*log(n))

    while (right >= left) {
        if (arr[right] + arr[left] > target) {
            // sum val should be low 
            right--;
        } else if (arr[right] + arr[left] < target) {
            // sum val should be more 
            left++;
        } else {
            // arr[right] + arr[left] == target
            return "Yes";
        }
    }

    return "No";
}

int main () {
    vector<int> arr = {1,2,3,5,7,1};
    int target = 12;
    cout << q2Optimized(arr,target) << endl;
    return 0;
}