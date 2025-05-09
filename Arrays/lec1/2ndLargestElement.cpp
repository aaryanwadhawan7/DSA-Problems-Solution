#include <bits/stdc++.h>
using namespace std;


int brute2ndLargest(int arr[] , int size) {

    sort(arr , arr + size); // n log(n)
    int largest = arr[size-1]; 
    int secLargest = -1; // incase if 2nd largest element is not present in array

    // O(n)
    for (int i = size-2; i>=0; i--) {
        if (arr[i] != largest) {
            secLargest = arr[i];
            break;
        }
    }
    return secLargest;
}

int better2ndLargest(int arr[] , int size) {

    if (size < 2) {
        return -1;
    }
    
    // first pass : find largest element  : O(n)
    int largest = arr[0];
    for (int i = 0; i < size; i++) {
        if (largest < arr[i]) {
            largest = arr[i];
        }
    }
    cout << largest << endl;

    // second pass : find second largest element : O(n)
    int secondLargest = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] < largest && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

int optimal2ndLargest(int arr[] , int size) {
    // O(n)
    int largest = arr[0] , secondLargest = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] < largest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int optimal2ndSmallest(int arr[] , int size) {
    // O(n)
    int secondSmallest = INT_MAX, smallest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    return secondSmallest;
}

int main () {
    int arr[] = {1,2,7,7,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    //cout << brute2ndLargest(arr,size) << endl;
    //cout << better2ndLargest(arr,size) << endl;
    cout << optimal2ndLargest(arr,size) << " " << optimal2ndSmallest(arr,size) << endl;
    return 0;
}