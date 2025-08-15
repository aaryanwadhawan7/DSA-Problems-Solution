// Connected Components [Undirected Graph] 
// It is a graph only but broken down into 4 different components !
// Code will be covered later !

#include <iostream>
#include <vector> 
#include <queue>
using namespace std;

void printAdjLst (int n, int m, vector <int> adj[]) {
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (auto itr : adj[i]) {
            cout << itr << " ";
        }
        cout << endl;
    }
}

void bfs (vector <int> &comp, int visited[], vector <int> adj[], int start) {
    queue <int> q;
    q.push (start);

    // traverse the neighbour of the node 
    while (!q.empty()) {
        // node -> starting node
        int node = q.front();
        q.pop();
        visited [node] = 1;
        comp.push_back (node);

        for (auto itr : adj[node]) {
            if (!visited[itr]) {
                q.push (itr);
                visited[itr] = 1;
            }
        }
    }
}

int main () {
    // Undirected Graph
    // Breadth First Search (BFS)
    // 0-based indexing

    int n, m;
    cin >> n >> m;

    vector <int> adj[n+1];
    for (int i = 0; i < m; i++) {
        // i -> 0 to m
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << endl;

    cout << "Adjacency List : " << endl;
    printAdjLst (n, m, adj);
    cout << endl;

    vector <vector<int>> lst; // List of Connected Components
    int visited[n+1] = {0};
    for (int i = 0; i < n; i++) {
        vector <int> comp;
        if (!visited[i]) {
            bfs (comp, visited, adj, i);
            lst.push_back(comp);
        }
    }

    // cout << "Breadth First Search : " << endl;
    // for (auto itr : lst) {
    //     cout << itr << " ";
    // }
    // cout << endl;

    for (auto comp : lst) {
        for (auto &node : comp) {
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "No. of Connected Components : " << lst.size();

    return 0;
}