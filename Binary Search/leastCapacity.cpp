// Least capacity to ship packages within D days

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int sumEle (vector<int> &weights) {
    int sum = 0;
    for (auto it : weights) {
        sum += it;
    }

    return sum;
}

int maxEle (vector<int> &weights) {
    int maxi = INT_MIN;
    for (auto element : weights) {
        if (element > maxi) {
            maxi = element;
        }
    }

    return maxi;
}


int daysNeeded (vector <int> &weights, int capacity) {

    int days = 1; 
    int totalCap = 0;

    for (int i = 0; i < weights.size(); i++) {
        if (totalCap + weights[i] > capacity) {
            days++;
            totalCap = weights[i];
        } else {
            totalCap += weights[i];
        }
    }

    return days;
}

int leastCapacity (vector<int> &weights, int days) {

    // task -> we have to ship weights within given days and idividual 
    // weights[i] need to be shifted in sorted order.
    // you can send multiple weights at a time but it should be within the capacity range
    // which we need to determine

    // min capacity -> max element : if val capacity less than max element than 
    // we will not to able to ship max element
    // max capacity -> sum of all elements
    // Range -> [maximum element, sum of elements]

     int sizeWeights = weights.size();
     int low = maxEle (weights);
     int high = sumEle(weights);
     int ans = low;
    // [  10   11   12   ................   55  ] : capacity define
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int daysReqd = daysNeeded(weights,mid);

        if (daysReqd <= days) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}


int main () {
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days;
    cout << "Enter the days needed to ship packages :"  << endl;
    cin >> days;

    int capacity = leastCapacity (weights,days);
    cout << capacity << endl;
    return 0;
}