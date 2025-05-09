// Union of 2 Sorted Arrays

#include <bits/stdc++.h>
using namespace std;

vector<int> bruteUnion(vector<int> &a, vector<int> &b)
{
    set<int> st; // O(n1 + n2)
    // n1 -> a.size() , n2 -> b.size() , n -> st.size()
    for (auto it : a)
    { // O(n1*log(n))
        st.insert(it);
    }

    for (auto itr : b)
    { // O(n2*log(n))
        st.insert(itr);
    }

    // Transfer unique elements from set to a vector : O(n1 + n2)
    vector<int> ans(st.begin(), st.end()); // O(n1 + n2)
    return ans;

    // tc : O(n1 log n) + O(n2 log n) + O(n1 + n2)
    // sc : O(n1 + n2) [Space used to store unique elements] + O(n1 + n2) [Space use to return ans]
}

vector<int> OptimalUnion(vector<int> &a, vector<int> &b)
{

    // tc : O(n1 + n2) ,  sc : O(n1 + n2)
    int i = 0;
    int j = 0;
    int n1 = a.size(), n2 = b.size();
    vector<int> unionArr;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            // Ensure we check if unionArr is not empty
            if (unionArr.empty() || unionArr.back() != a[i])
            {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else
        {
            // b[j] < a[i]
            if (unionArr.empty() || unionArr.back() != b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    while (i < n1)
    {
        // Check if unionArr is not empty before accessing back()
        if (unionArr.empty() || unionArr.back() != a[i])
        {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    while (j < n2)
    {
        // Check if unionArr is not empty before accessing back()
        if (unionArr.empty() || unionArr.back() != b[j])
        {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    return unionArr;
}


int main()
{
    vector<int> a = {1, 1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 4, 4, 5, 6};

    // vector<int> result = bruteUnion (a,b);
    vector<int> result = OptimalUnion(a, b);

    for (auto it : result)
    {
        cout << it << " ";
    }

    return 0;
}