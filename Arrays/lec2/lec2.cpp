#include <bits/stdc++.h>
using namespace std;

void reverse(int start , int end , int arr[]) {
    int temp = 0;
    // O(n)
    while (start < end) {
        // swap elements 
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++,end--;
    }
}

void leftRotateOnePlace(int arr[] , int size) {
    int j = arr[0];
    for (int i = 1; i < size; i++) {
        arr[i-1] = arr[i];
    }

    arr[size-1] = j;
}

void leftRotate(int arr[] , int size , int& d) {

    // TC : O(n+d)
    // SC : O(n)

    // Manging for values of d greater than size of array
    d = d % size;

    // 1. Put d elements in an vector : O(d)
    vector<int> temp(d);
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    // 2. Shifting elements : O(n-d)
    for (int i = d; i < size; i++) {
        arr[i - d] = arr[i];
    }

    // 3. Putting temp back : O(d)
    for (int i = size - d; i < size; i++) {
        arr[i] = temp[i - (size - d)];
    }

}

void rightRotate(int arr[], int size, int& d) {
    // Handling for case of d greater than array size 
    d = d % size;
    
    // 1. Reverse the array elements 
    reverse(0 , size-1 , arr);

    // 2. Reverse the 1st d elements of the array 
    reverse(0 , d - 1 , arr);

    // 3. Reverse the remaining elements
    reverse(d , size - 1 , arr);
}

void leftRotateOptimal(int arr[], int size, int& d) {
    // TC : O(2n) , SC : O(1)
    
    d = d % size;

    reverse(0 , d - 1 , arr); // O(d)
    reverse(d , size - 1 , arr); // O(n-d)
    reverse(0 , size - 1 , arr); // O(n)
}

int main() {
    int arr[5] = { 3 , 2 , 1 , 5 , 2 };

    //  d = 3  ->  5   2   3   2   1    [LR]
    //  d = 3 ->   1   5   2   3   2    [RR]  
    //Reverse arr: 2   5   1   2   3    

    int size = sizeof(arr) / sizeof(arr[0]);

    // left rotate the array by one place : O(n)
    //leftRotateOnePlace(arr , size);

    // left rotate by d places 
    int d;
    cout << "Enter the number of places you want to left/right rotate array :" << endl;
    cin >> d;
    //leftRotate(arr , size, d);
    //rightRotate(arr,size,d);
    leftRotateOptimal(arr,size,d);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}