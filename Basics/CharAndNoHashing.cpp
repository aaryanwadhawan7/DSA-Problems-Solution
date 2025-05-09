// Hashing -> pre-storing / fetching 

#include <iostream>
#include <string>
using namespace std;

int countElement(int number, int arr[]){
    int cnt = 0;
    for(int i = 0; i<6 ; i++) {
        if(number == arr[i]) {
            cnt = cnt + 1;
        }
    }
    return cnt;
}

int main(){
    
    // int arr[] = {1,2,3,2,5,4};
    // int number = 7;
    // int numberCounter = countElement(number,arr);
    // cout << numberCounter << endl;
    
    // I/P => n , array , no. of queries , queries 
    
    // number hashing 
    
    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }

    // //precompute:
    // int hash[13] = {0};
    // for (int i = 0; i < n; i++) {
    //     hash[arr[i]] += 1;
    // }

    // int q;
    // cin >> q;
    // while (q--) {
    //     int number;
    //     cin >> number;
    //     // fetching:
    //     cout << hash[number] << endl;
    // }
    
    // character hashing 
    
    string s;
    cin >> s;
    
    //pre compute
    int hash[26];
    for(int i = 0; i<s.size(); i++) {
        hash[s[i]-'a']++;
    }
    
    int q; // no. of queries 
    cin >> q;
    while(q--) {
        char c;
        cin >> c;
        //fetch
        cout << hash[c-'a'] << endl;
    }
    
    return 0;
}

//T.C. => O(N)
//I we have to find the occurence of q no.s then the T.C. will be Q*O(N) => O(Q*N)

/*

Inside int main() function =>
Integer -> arr[10^6] , Boolean -> arr[10^7]

Globally declare variable
Integer -> arr[10^7] , Boolean -> arr[10^8]

*/

// Character Hashing -> Problem 2 
