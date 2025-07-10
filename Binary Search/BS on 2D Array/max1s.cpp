// GIVEN : non-empty grid 'mat' with 'n' rows and 'm' columns.
// All the rows are sorted in ascending order. 
// Rows contain either 0's and 1's.


#include <iostream>
#include <vector>
using namespace std;

int lowerBound (vector<int> &row, int m, int i) {
    // lowerBound(x) : index such that row[index] >= x
    int vecSize = row.size();
    int low = 0;
    int high = vecSize - 1;
    int ans = vecSize;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (row[mid] >= i) {
            ans = mid;
            // Since we are looking for 1st occurence then look for element in left
            high = mid - 1;
        } else {
            // search in right
            low = mid + 1;
        }
    }

    return ans;
}


// Brute Approach
int maxOnes (vector<vector<int>> &matrix, int n, int m) { // rows x column -> n x m
    int index = -1;
    int maxSum = 0;

    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < m; j++) {
            rowSum = rowSum + matrix[i][j];
            if (rowSum > maxSum) {
                // update maxSum
                maxSum = rowSum;
                // rowSum should be updated to calculate sum for next row
                rowSum  = 0;
                index = i;
            }
        }
    }

    return index;
}

// Better / Optimal Approach
// We can't change the way to iterate over the matrix but we can change the logic
// to find the maximum 1's in an row.


// TC : O (n * log 2 (n))
int maxOnes2 (vector<vector<int>> &matrix, int n, int m) {
    // n x m -> rows x columns
    int index = -1; 
    int maxCnt = 0;

    for (int i = 0; i < n; i++) {
        int onesCnt = 0;
        for (int j = 0; j < m; j++) {
            // j -> 0 to m
            onesCnt = m - lowerBound(matrix[i], m, 1);
            if (onesCnt > maxCnt) {
                maxCnt = onesCnt;
                index = i;
            }
        }
    }

    return index;
}

int main () {

    int n = 3, m = 3;
    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter matrix Element : " << endl;
    // Taking input from users
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
        cout << endl;
    }


    int rowIndex = maxOnes2 (matrix,n,m);
    cout << "The row index containing maximum 1's is " << rowIndex << " ." << endl;
    return 0;
}