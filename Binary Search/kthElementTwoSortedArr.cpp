#include <iostream>
#include <vector>
using namespace std;

int kthEle (vector<int> &a, vector<int> &b, int k) {

    int size1 = a.size(), size2 = b.size();
    int i = 0; // i -> a 
    int j = 0; // j -> b
    vector<int> mergeSortedArr = {};

    while (i < size1 && j < size2) {
        if (a[i] < b[j]) {
            mergeSortedArr.push_back(a[i]);
            i++;
        } else {
            mergeSortedArr.push_back(b[j]);
            j++;
        }
    }

    while (i < size1) {
        mergeSortedArr.push_back(a[i]);
        i++;
    }

    while (j < size2) {
        mergeSortedArr.push_back(b[j]);
        j++;
    }

    for (auto el : mergeSortedArr) {
        cout << el << " ";
    }
    cout << endl;

    int targetInd = k - 1;
    return mergeSortedArr[targetInd];
}

int main () {
    vector<int> a = {2,4,4};
    vector<int> b = {1,3,5};
    // {  1   2   3   4   4   5  }
    int k;
    cout << "Enter kth element : " << endl;
    cin >> k;
    int ans = kthEle (a,b,k);
    cout << "The kth element of sorted arr a and b is " << ans << " ." << endl;
    return 0;
}