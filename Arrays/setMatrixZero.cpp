
#include <bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}


void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // Set -1 for rows and cols
    // that contains 0. Don't mark any 0 as -1:

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    // Finally, mark all -1 as 0:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

vector<vector<int>> zeroMatrix2(vector<vector<int>> &matrix, int n, int m) {

    int row[n] = {0}; // row array
    int col[m] = {0}; // col array

    // Traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark ith index of row wih 1:
                row[i] = 1;

                // mark jth index of col wih 1:
                col[j] = 1;
            }
        }
    }

    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

vector<vector<int>> zeroMatrix3 (vector<vector<int>> &matrix, int n, int m) {
    // row -> col[0] -> matrix[...][0]
    // col -> row[0] -> matrix[0][...]

    // mark 1st row and col zero based on the matrix element 
    bool rowEleZero = false;
    bool colEleZero = false;

    // iterate through the row and col to find Zero Element 
    // for case having only one row 
    for (int i = 0; i < m; i++) {
        if (matrix[0][i] == 0) {
            rowEleZero = true;
        }
    }

    for (int j = 0; j < n; j++) {
        if (matrix[j][0] == 0) {
            colEleZero = true;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark row zero 
                matrix[i][0] = 0;
                // mark col zero
                if (j != 0) {
                    matrix[0][j] = 0;
                }else {
                    colEleZero = 0;
                }
            }
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] != 0) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                  matrix[i][j] = 0;
                }
            }
        }
    }

    if (colEleZero) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0; 
        }
    }

    if (rowEleZero) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
     vector<vector<int>> ans = zeroMatrix3(matrix, n, m);

    cout << "The Final matrix is " << endl;
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}

