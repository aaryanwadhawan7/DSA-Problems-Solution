#include <iostream>
#include <vector>
using namespace std;

// sc : O(2 * E)
int main() {
    int N, M;
    cin >> N >> M;

    vector<int> adj[N + 1]; // array of vectors

    for (int i = 0; i < M; i++) { // loop over edges
        int firstNode, secondNode;
        cin >> firstNode >> secondNode;
        adj[firstNode].push_back(secondNode);
        // Directed Graph just remove below line of code 
        adj[secondNode].push_back(firstNode); // undirected graph
    }

    cout << endl;
    for (int i = 1; i <= N; i++) { // loop over vertices
        cout << i << ": ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}

// Rep1 : vector<vector<int>> adjacencyMatrix (N+1, vector<int>> (N+1,0)) -> N+1 x N+1
// Rep2 : vector<int> adjacencyList[N+1] -> N+1 continuous boxes each box is an dynamic vector