// Bubble Sort -> swapping adjacent element 
// Not suitable for large datasets as its average and worst case time complexity is quite high
// TC : O(n*n)
// SC : O(1)

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[] , int n) {
    for(int i = 0; i<n-1; i++) {
        //outer loop for passes 
        for(int j = 0; j < n - i -1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void printArray(int arr[] , int n) {
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {5,1,4,2,8};
    int n = sizeof(arr)/sizeof arr[0];
    
    bubbleSort(arr,n);
    cout << "Bubble Sort :" << endl;
    printArray(arr,n);
    
    return 0;
}