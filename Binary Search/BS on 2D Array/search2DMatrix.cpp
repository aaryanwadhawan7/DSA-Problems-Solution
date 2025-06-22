#include <iostream>
#include <vector>
using namespace std;

// Brute approach -> Linear Search -> O (m * n)

bool searchMatrix (vector<vector<int>> &matrix, int m, int n, int target) {

    for (int i = 0; i < m; i++) {
        int low = 0;
        int high = n - 1;

        if (matrix[i][low] <= target && matrix[i][high] >= target) {
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (matrix[i][mid] == target) {
                    return true;
                } else if (matrix[i][mid] > target) {
                    // search in left : look for smaller value
                    high = mid - 1;
                } else {
                    // search in right
                    low = mid + 1;
                }
            }
        } else {
            continue;
        }
    }

    return false;
}

int main () {
    int m, n;
    cout << "Enter no. of rows : " << endl;
    cin >> m;
    cout << "Enter no. of columns : " << endl;
    cin >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter matrix elements : " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int target; 
    cout << "Enter target element : " << endl;
    cin >> target;

    bool isPresent = searchMatrix (matrix,m,n,target);
    cout << "Is " << target << " element is present in matrix : " << isPresent << " ." << endl;
    return 0;
}