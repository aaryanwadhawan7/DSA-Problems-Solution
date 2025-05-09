#include <bits/stdc++.h>
using namespace std;

void optimalPushZeroEnd (int a[] , int size) {
    // 2 - pointer approach intuition

    int j = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] != 0) {
            swap(a[i] , a[j]);
            j++;
        }
    }

}

void pushZerosToEnd (int a[] , int size) {

    vector <int> temp; // SC : O(n)
    // 1. push non-zero elements to temp vector
    for (int i = 0; i < size; i++) { // O(n) , worst case when the last element is non-zero
        if (a[i] != 0) {
            // element is non-zero
            temp.push_back(a[i]);
        }
    }

    // 2. Add zeros to end of temp // O(n - y) , y = no. of zeros
    for (int j = temp.size(); j < size; j++) {
        temp.push_back(0);
    }

    // 3. Move all elements from temp to original array
    for (int x = 0; x < size; x++) { // O(y)
        a[x] = temp[x];
    }

    // TC : O(2n)
}

int main () {

    int a[] = { 1 , 0 , 2 , 3 , 2 , 0 , 0 , 4 , 5 , 1 };
    //              j
    int size = sizeof(a)/sizeof(a[0]);
    // pushZerosToEnd(a,size);
    optimalPushZeroEnd(a , size);

    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }

    return 0;
}