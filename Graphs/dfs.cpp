#include <iostream>
#include <vector>
using namespace std;

void printAdjLst (int n, int m, vector <int> adj[]) {
    // n -> # of nodes/vertices
    // m -> # of edges

    for (int i = 0; i <= n; i++) {
        cout << i << " -> ";
        for (auto itr : adj[i]) {
            cout << itr << " ";
        }
        cout << endl;
    }
}

void dfs (int node, vector<int> adj[], vector <int> &lst, int visited[]) {
    lst.push_back(node);
    // mark occurence of node in visited arr
    visited[node] = 1;

    for (auto itr : adj[node]) {
        if (!visited[itr])
        dfs (itr, adj, lst, visited);
    }
}

int main () {
    int n, m;
    cin >> n >> m;
    vector <int> adj[n+1]; // adjacency list

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << endl;

    printAdjLst (n, m, adj);

    cout << "Depth First Traversal : " << endl;
    int startNode = 1;
    vector <int> lst;
    int visited[n+1] = {0};
    dfs (startNode, adj, lst, visited);

    for (auto itr : lst) {
        cout << itr << " ";
    }

    return 0;
}