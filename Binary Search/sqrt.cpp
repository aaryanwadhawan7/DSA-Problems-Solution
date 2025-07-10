// sqrt(n) : Binary Search on Answers
// Range is defined... , Find min or max something....

#include <iostream>
using namespace std;

int sqrt (int n) {
    // Range : [min -> 1] and [max -> n]
    int low = 1;
    int high = n;
    int ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        int val = mid * mid;
        if (val <= n) {
            // may or may not be answer
            ans = mid;
            // search in right
            low = mid + 1;
        } else {
            // val > n
            // search in left
            high = mid - 1;
        }
    }

    return ans;
}

int main () {
    int n;
    cin >> n;
    int ans = sqrt(n);
    cout << "Sqrt of " << n << " is " << ans << " ." << endl;
    return 0;
}