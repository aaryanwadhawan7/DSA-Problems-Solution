// Fractional Knapsack problem

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Container {
    public :
    int value;
    int weight;
};

// Problem -> We have tp get the max val keeping the value of weight similar to W
bool comparator (Container a, Container b) {
    // [value / weight] comparison
    double val1 = (double)a.value/a.weight;
    double val2 = (double)b.value/b.weight;

    return val1 > val2;
}

double fracKnapsack (Container val[], int N, int W) {
    int maxVal = 0;
    int currWeight = 0;
    //sort based on values per weight in descending order
    sort (val, val + N, comparator); // O (NlogN)
    //val [] => { {60, 10}, {100, 20}, {120, 30} }
    for (int i = 0; i < N; i++) { // O (N)
        if (currWeight + val[i].weight <= W) {
            currWeight += val[i].weight;
            maxVal += val[i].value;
        } else {
            //we have to take a part of weight (fractional)
            maxVal = maxVal + (double)((val[i].value/val[i].weight)*(W - currWeight));
        }
    }

    return maxVal;
}

int main()
{
    // given
    vector<int> weight = {20, 10, 30};
    vector<int> values = {100, 60, 120};
    int N = 3;
    int W = 50;

    Container val[N] = {{100, 20}, {60, 10}, {120,30}};

    double maxVal = fracKnapsack (val, N, W);
    cout << maxVal << endl;
    return 0;
}