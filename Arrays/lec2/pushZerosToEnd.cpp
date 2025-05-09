// C++ Program to move all zeros to end using temporary array

#include <bits/stdc++.h>
using namespace std;


void pushZerosToEnd(vector<int> &arr) {
    int n = arr.size();
    vector<int> temp(n);

    // to keep track of the index in temp[]
    int j = 0;

    // Copy non-zero elements to temp[]
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0)
            temp[j++] = arr[i];
    }

    // Fill remaining positions in temp[] with zeros
    while (j < n) {
        temp[j++] = 0;
    }

    // Copy all the elements from temp[] to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

void pushZerosToEnd2(vector<int> &vec) {
    // keep the track of the non-zero element 
    int count = 0;
    
    for(int i = 0; i<vec.size(); i++) {
        if(vec[i] != 0) {
            vec[count] = vec[i];
            count+=1;
        }
    }
    
    // after this all non-zero elements are shifted at the front 
    // place all 0's at the end
    
    while(count < vec.size()) {
        vec[count++] = 0;
    }
}

void pushZerosToEnd3(vector<int> &vec) {
    // this will keep the track of all non-zero element 
    int cnt = 0;
    
    for(int i = 0; i<vec.size(); i++) {
        if(vec[i] != 0) {
            swap(vec[i],vec[cnt]);
            cnt+=1;
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    // pushZerosToEnd(arr);
    // pushZerosToEnd2(arr);
    pushZerosToEnd3(arr);
    // Print the modified array
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}