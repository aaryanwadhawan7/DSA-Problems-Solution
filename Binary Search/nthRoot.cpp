// Ques) Find the nth root of the integer.
// [ Test case 1 ) N = 4, M = 81 => Output : 3 ]
// [ Test Case 2)  N = 3, M = 16 => Output : -1 ]

#include <iostream>
#include <math.h>
using namespace std;

int nthRoot (int N, int M) {
    for (int i = 1; i < M; i++) {
        if (pow(i,N) == M) {
            return i;
        }
    }
    return -1;
}

int main () {
    int N,M;
    cin >> N;
    cin >> M;

    int ans = nthRoot(N,M);
    cout << ans << endl;
    return 0;
}

