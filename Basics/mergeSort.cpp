// Merge Sort -> D&C

// 1. Divide the array -> [mid]
// -------------------------------------------
// 2. Merge parts to create an sorted array -> 
// 1. compare left and right part element
// 2. push the elements in the temp vector
// 3. push temp elements to original array
// ------------------------------------------

// tc [Recursive functions] -> total calls * work done in each call -> log(n) * n

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &vec, int st, int mid, int end)
{
    vector<int> temp; // sc : O(n)
    int i = st, j = mid;

    // O(n)
    while (st <= mid && j <= end)
    {
        if (vec[i] <= vec[j])
        {
            temp.push_back(vec[i]);
            i++;
        }
        else
        {
            temp.push_back(vec[j]);
            j++;
        }
    }

    while (st <= mid)
    {
        temp.push_back(vec[i]);
        i++;
    }

    while (j <= end)
    {
        temp.push_back(vec[j]);
        j++;
    }

    // O(n)
    for (int idx = 0; idx < temp.size(); idx++) {
        vec[idx+st] = temp[idx];
    }
}

void mergeSort(vector<int> &vec, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2; 
        // not [(st+end)/2] cause of overflow
        // divide 
        mergeSort(vec, 0, mid); // Re fn 1
        mergeSort(vec, mid + 1, end); // Re fn 2
        // conquer ~ merge 
        merge(vec, st, mid, end); // O(2n) ~ O(n)
    }
}

int main()
{
    vector<int> vec = {12, 31, 35, 8, 32, 17};
    int size = vec.size();
    int st = 0;
    int end = size - 1; 
    // pointing towards the last element 
    mergeSort(vec, st, end);

    for (auto val : vec)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}