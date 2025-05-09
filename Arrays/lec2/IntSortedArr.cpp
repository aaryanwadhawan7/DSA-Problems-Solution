#include <bits/stdc++.h>
using namespace std;

vector<int> intArr(vector<int> &a, vector<int> &b, int n1, int n2)
{
    vector<int> intersection;
    int i = 0, j = 0;
    for (int x = 0; x < n1; x++)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < a[i])
        {
            j++;
        }
        else
        {
            // a[i] == b[j]
            intersection.push_back(a[i]);
            i++, j++;
        }
    }
    return intersection;
}

vector<int> bruteIntSortedArr(vector<int> &a, vector<int> &b, int n1, int n2)
{
    // 1. Create a visited vector
    vector<int> visited[n2 + 1] = {0};
    vector<int> intersection;

    // 2. Algorithm :Update the visited vector corresponding to the occurence of elements in 2nd vector
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (a[i] == b[j] && visited[b[j]] == 0)
            {
                intersection.push_back(a[i]);
                visited[b[j]] == 1;
                break;
            }

            if (a[i] < b[j])
                break;
        }
    }

    return intersection;
}


int main()
{
    vector<int> a = {1, 2, 2, 3, 3, 4, 5, 6};
    vector<int> b = {2, 3, 4, 4, 5, 6};
    int n1 = a.size();
    int n2 = b.size();
    vector<int> ans = bruteIntSortedArr(a, b, n1, n2);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}