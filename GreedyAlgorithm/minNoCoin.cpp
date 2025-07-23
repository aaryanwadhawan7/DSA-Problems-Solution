#include <iostream>
#include <vector>
using namespace std;


int minDeno (vector <int> &deno, int V) {
    int coinsNeeded = 0;
    for (int i = deno.size () - 1; i >= 0; i--) {
        while (V >= deno[i]) {
            V = V - deno[i];
            coinsNeeded ++;
        }
    }

    return coinsNeeded;
}

int main () {
    vector <int> deno = {1,2,5,10,20,50,100,200,500,2000};
    int V = 2859; // min no of coins used to make amount equals to V

    int minNoCoins = minDeno (deno, V);
    cout << minNoCoins << endl;

    return 0;
}