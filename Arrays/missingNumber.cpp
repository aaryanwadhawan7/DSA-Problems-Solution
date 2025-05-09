// Problem Statement :
// Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. 
// Find the number(between 1 to N), that is not present in the given array.

#include <bits/stdc++.h>
using namespace std;

int brute (vector<int> &vec,int N) {
    // vec.size() -> N
    // linear search : tc -> O(N x N) and sc -> O(1)
    for (int i = 1; i <= N; i++) {
        bool flag = false;
        for (int j = 0; j < N; j++) {
            if (vec[j] = i) {
                flag = true;
                break;
            }
        }
        if (flag == false) return i;
    }
    return -1;
}

int better (vector<int> &vec, int N) {
    // Hashing
    int hash[N+1] = {0};
    
    // 1. Storing the frequencies : iterating over the vec and updating frequencies
    // vec.size()  ->  [N]  : i = 0 to [N-2] cause there is one missing element 
    for (int i = 0; i < N - 1; i++) { // O(N)
        hash[vec[i]]++;
    }

    // 2. Iterate over the hash and check the frequency 
    // hash.size()  ->  [N + 1]  -> 0 to N 
    // [0,N]
    for(int j = 1; j <= N; j++) { // O(N)
        if (hash[j] == 0) {
            return j;
        }
    }

    // there is no missing number
    return -1;
}

int optimalOne (vector<int> &vec, int N) {
    int sum = 0;

    // Sum of vec elements : O(N)
    for (int i = 0; i < vec.size(); i++) {
        // i -> 0 to [N-1]
        sum += vec[i];
    }

    int actualSum = ( N * ( N + 1 ) ) / 2;

    return (actualSum - sum);
}

int optimalTwo (vector<int> &vec, int N) {
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < vec.size(); i++) { // O(N)
        xor1 = xor1 ^ vec[i];
        xor2 = xor2 ^ (i+1);
    }
    xor1 = xor1 ^ N;
    // for (int i = 0; i <= vec.size(); i++) {
    //     vec = val ^ i;
    // }

    return (xor1 ^ xor2);
}

int main () {
    int N = 5;
    vector<int> vec = {1,2,4,5};
    int result = optimalTwo (vec , N);
    cout << result << endl;
    return 0;
}