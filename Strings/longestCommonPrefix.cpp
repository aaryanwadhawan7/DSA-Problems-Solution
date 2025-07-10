# include <iostream>
# include <vector>
using namespace std;

// TC : O (n * s) where n is the number of strings and s is the avg size of the strings
// SC : O(1)
string longestCommonPrefix (vector<string> &strs, int vecSize) {
    // We will take one string from the vector of strings
    // Compare with other strings of the 
    
    string currStr = strs[0];
    int strLength = currStr.length();

    for (int i = 1; i < strs.size(); i++) {
        string str = strs[i];
        int ptr = 0;
        while (ptr < str.length() && ptr < currStr.length() && str[ptr] == currStr[ptr]) {
            // char of both strings are not equal
            ptr++;
        }
        currStr = currStr.substr(0,ptr);
        if (currStr.length() == 0) {
            return "";
        }
    }

    return currStr;
}

int main () {
    vector <string> strs = {"flower", "flow", "flight"};
    //                      currStr    str
    // {"flow,", "light"}
    // currStr    str -> ptr > strs[0].length()
    int vecSize = strs.size();
    string commonPrefix = longestCommonPrefix (strs, vecSize);
    cout << "The Longest Common Prefix is " << commonPrefix << endl;
    return 0;
}