// Given the nth row, you have to print the pascal triangle

#include <iostream>
#include <vector>
using namespace std;

int NcR (int n, int r) {
    long long res = 1;
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }

    return (int)res;
}

vector <vector<int>> generate (int nthRow) {
    vector<vector<int>> ans;

    // nth row -> n # of elements
    for (int row = 0; row < nthRow; row++) {
         vector<int> rowAns;
        for (int col = 0; col <= row; col++) {
            rowAns.push_back(NcR (row, col));
        }
        ans.push_back(rowAns);
    }

    return ans;
}


int main () {
    int nthRow;
    cin >> nthRow;
    vector<vector<int>> pascalTriangle = generate (nthRow);
    for (auto &row : pascalTriangle) {
        for (auto ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }
}