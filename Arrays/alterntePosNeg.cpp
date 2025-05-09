#include <bits/stdc++.h>
using namespace std;

vector <int> posNegAlternate(vector<int> &v, int n) {
    vector<int> pos;
    vector<int> neg;

    // o(n)
    for (int i = 0; i < n; i++) {
        if (v[i] < 0) {
            neg.push_back(v[i]);
        } else {
            pos.push_back(v[i]);
        }
    }

    for (int i = 0; i < n - 1; i++) {
        v[2*i] = pos[i];
        v[i+1] = neg[i];
    }

    return v;
}

int main () {
    // 1. no of + and - elements are equal
    vector <int> v = {2,3,-1,4,-2,-9};
    int n = v.size();
    vector <int> ans = posNegAlternate(v,n);
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;

    // 2. no of + and - elements are bot equal
    return 0;
}