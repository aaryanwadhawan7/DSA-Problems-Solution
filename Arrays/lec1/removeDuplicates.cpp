#include <bits/stdc++.h>
using namespace std;

void bruteRemoveDuplicates(int arr[] , int& size) {
    set <int> container; // SC : O(n)
    for (int i = 0; i < size; i++) {
        //unique elements
        container.insert(arr[i]);  //n*log(n)
    }

    size = container.size();

    int index = 0;
    // O(n)
    for(auto it : container) {
        arr[index] = it;
        index++;
    }
}

void optimalRemoveDuplicates(int arr[] , int& size) {
    // 2 - pointer approach
    int i = 0;
    for (int j = 1; j < size; j++) {
        if (arr[i] != arr[j]) {
            i++;
            arr[i] = arr[j];
        }
    }

    size = i + 1;
}

int main () {
    int arr[] = {1,1,2,2,2,3,3};
    int size = sizeof(arr) / sizeof(arr[0]);
    //bruteRemoveDuplicates(arr,size);
    optimalRemoveDuplicates(arr,size);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}