// BS on Answers -> (min) max  or  (max) min

// Aggressive Cows Problem
// Ques) Assign C cows to N stalls such that
//       min distnace between them is largest possible.

// [POINTS TO REMEMBER] :
// THE MOST OPTIMAL WAY IS TO PUT OUR FIRST OBJECT (COW IN THIS PROBLEM) IS AT THE FIRST POSITION.
// IN ORDER TO FIND MIN DISTANCE IT IS ADVISED TO LOOK FOR ADJACENT ELEMENTS.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canWePlaceCows(vector<int> &positions, int minDist, int cows)
{
    int cntCows = 1, currPostn = positions[0];
    for (int i = 0; i < positions.size(); i++)
    {
        if (positions[i] - currPostn >= minDist)
        {
            cntCows++;
            currPostn = positions[i];
        }
    }

    return cntCows >= cows;
}

int largestMinDistance2(vector<int> &positions, int cows)
{

    sort(positions.begin(), positions.end());
    int size = positions.size();
    int low = 1;
    int high = positions[size - 1] - positions[0];
    int ans = size;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canWePlaceCows(positions, mid, cows))
        {
            // true
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int largestMinDistance(vector<int> &positions, int cows)
{

    // range -> [1,max-min]
    // SORTED ARRAY IS NECESSARY SINCE WE ARE LOOKING FOR ADJACENT INCREASING ELEMENTS

    sort(positions.begin(), positions.end());
    int sizePositions = positions.size();
    int ans = sizePositions;

    for (int i = 1; i < (positions[sizePositions - 1] - positions[0]); i++)
    {
        if (canWePlaceCows(positions, i, cows))
        {
            // true
            ans = i;
        }
        else
        {
            continue;
        }
    }

    return ans;
}

int main()
{
    vector<int> positions = {0, 3, 4, 7, 10, 9};
    int cows = 4;
    int ans = largestMinDistance2 (positions, cows);
    cout << "The largest distance possible to place " << cows << " cows in such a way difference b/w them is minimum is " << ans << " ." << endl;
    return 0;
}