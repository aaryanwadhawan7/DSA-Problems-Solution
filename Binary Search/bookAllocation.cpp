// Book Allocation Problem or Allocate Book 
// Ques)  You have to allocate to book to m students such that 
//        maximum no. of pages assigned to student is minimum.

// PROBLEM STATEMENT (REQUIRED METRICS) :
// 1). Atleast one book should be allocated to each student.
// 2). Each book should be allocated to only one student.
// 3). Book Allocation should be in continuous manner.

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int maxElement (vector<int> &pages) {
    int maxi = INT_MIN;
    for (auto it : pages) {
        if (maxi < it) {
            maxi = it;
        }
    }

    return maxi;
}

int sumElement (vector<int> &pages) {
    int sum = 0;
    for (auto it : pages) {
        sum = sum + it;
    }

    return sum;
}

int allocatedStudent (vector<int> &pages, int maxPages) {
    int studentCnt = 1;
    int currPages = 0;
    for (int i = 0; i < pages.size(); i++) {
        if (currPages + pages[i] > maxPages) {
            studentCnt++;
            currPages = pages[i];
        } else {
            currPages += pages[i];
        }
    }

    return studentCnt;
}

// TC :
// O (sumElement - maxElement) * O(n) , n -> pages.size()

int bookAllocation (vector<int> &pages, int m) {
    int low = maxElement(pages);
    int high = sumElement(pages);

    for(int i = low; i < high; i++) {
        // i -> [low] to [high]
        if (allocatedStudent (pages,i) == m) {
            // pages can be allocated to exactly m students
            return i;
        }
    }

    return -1;
}

// Optimal Approach -> Binary Search -> Similar to painters partition problem

int main () {
    vector<int> pages = {25, 46, 28, 49, 24};
    int m = 4;
    int n = pages.size();

    int ans = bookAllocation (pages, m);
    cout << ans << endl;
    return 0;
}