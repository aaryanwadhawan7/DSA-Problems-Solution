#include <iostream>
using namespace std;

// lowerBound (x) : index such that arr[index] >= x
// upperBound (x) : index such that arr[index] > x

int firstOccurence(int arr[], int N, int X)
{
    int low = 0;
    int high = N - 1;
    int first = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == X)
        {
            // may or may not be answer
            first = mid;
            // search in left
            high = mid - 1;
        }
        else if (arr[mid] > X)
        {
            // search in left
            high = mid - 1;
        }
        else
        {
            // arr[mid] < X
            // search in right
            low = mid + 1;
        }
    }

    return first;
}

int lastOccurence(int arr[], int N, int X)
{
    int low = 0;
    int high = N - 1;
    int last = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == X)
        {
            // may or may not be answer
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] > X)
        {
            high = mid - 1;
        }
        else
        {
            // arr[mid] < X
            low = mid + 1;
        }
    }

    return last;
}

int main()
{
    int arr[] = {2, 2, 3, 3, 3, 3, 4};
    int N = sizeof(arr) / sizeof(arr[0]);
    int X;
    cin >> X;

    int ans = firstOccurence(arr, N, X);
    int ans2 = lastOccurence(arr, N, X);

        cout << "The first occerence of " << X << " is " << ans << " ." << endl;
        cout << "The last occurence of" << X << " is " << ans2 << " ." << endl;
        int output = ans2 - ans + 1;
        cout << "Total no. of occurences of " << X << " is " << output << " ." << endl;

    return 0;
}