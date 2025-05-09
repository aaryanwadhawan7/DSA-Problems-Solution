#include <bits/stdc++.h>
using namespace std;

int findLargest(int arr[],int size) {
    // TC : O(N) and SC : O(1)
    int greatest = arr[0];
    for (int i = 1; i<size; i++) {
        if (arr[i] > greatest) {
            greatest = arr[i];
        }
    }
    return greatest;
}

bool isSorted(int arr[] , int size) {
    // O(n)
    for (int i = 1; i < size; i++) {
        if (arr[i] >= arr[i-1]) {
            return true;
        }else {
            return false;
        }
    }

    return true;
}

int linearSearch(int arr[] , int size , int val) {
    int ans = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
           ans = i;
        }
    }
    return ans;
}

int main() {
    int arr[5] = {3,2,1,5,2};
    int size = sizeof(arr) / sizeof(arr[0]);
    // cout << findLargest(arr,size) << endl;
    // cout << isSorted(arr,size) << endl;

    int val;
    cout << "Enter the val :" << endl;
    cin >> val;
    cout << linearSearch(arr,size,val);

    return 0;
}

