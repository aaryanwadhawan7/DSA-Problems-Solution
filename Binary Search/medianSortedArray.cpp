// MEDIAN OF 2 SORTED ARRAYS -> In Left and Right, there should be equal no. of elements...
// Given : the two sorted arrays are of different sizes.

#include <iostream>
#include <vector>
using namespace std;

double medianTwoSortedArray (vector<int> &a, vector<int> &b)
{
    int i = 0, j = 0;
    int sizeA = a.size(), sizeB = b.size();
    vector<int> mergeArr = {};
    while (i < sizeA && j < sizeB)
    {
        if (a[i] < b[j])
        {
            mergeArr.push_back(a[i++]);
        }
        else
        {
            // a[i] >= b[j]
            mergeArr.push_back(b[j++]);
        }
    }

    if (i < sizeA)
        mergeArr.push_back(i++);
    else if (j < sizeB)
        mergeArr.push_back(j++);

    int mergeSize = sizeA + sizeB;
    if (mergeSize % 2 != 0)
    {
        // odd
        return (double)mergeArr[mergeSize / 2];
    }

    double median = (mergeArr[mergeSize / 2] + mergeArr[mergeSize / 2 - 1]) / 2.0;
    return median;
}

double medianSortedArray2 (vector<int> &a, vector<int> &b) 
{
    int size1 = a.size(), size2 = b.size();
    int cnt = 0;
    int i = 0, j = 0; // i -> a and j -> b
    int n = size1 + size2; // 1. even or 2. odd 
    int ind1 = n / 2 - 1; 
    int ind2 = n / 2;
    int ind1El = -1, ind2El = -1;

    while (i < size1 && j < size2) {
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1El = a[i];
            else if (cnt == ind2) ind2El = a[i];
            cnt++;
            i++;
        } else {
            if (cnt == ind1) ind1El = b[j];
            else if (cnt == ind2) ind2El = b[j];
            cnt++;
            j++;
        }
    }
    
    while (i < size1) {
         if (cnt == ind1) ind1El = a[i];
            else if (cnt == ind2) ind2El = a[i];
            cnt++;
            i++;
    }

    while (j < size2) {
        if (cnt == ind1) ind1El = b[j];
            else if (cnt == ind2) ind2El = b[j];
            cnt++;
            j++;
    }

    if (cnt % 2 != 0) {
        // odd 
        return (ind2El)/2.0;
    }

    // even
    return (ind1El + ind2El)/2.0;
}

int main()
{
    vector<int> a = {2, 4, 6};
    vector<int> b = {1, 3, 5};
    // 1 2 3 4 5 6
    double ans = medianSortedArray2(a, b);
    cout << "The answer of 2 sorted array is " << ans << " ." << endl;
    return 0;
}