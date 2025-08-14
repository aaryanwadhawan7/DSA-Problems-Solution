#include <iostream>
#include <vector>
using namespace std;

void print(const vector<vector<int>> &adj)
{
    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    // First Line :  No. of Nodes or Vertex (N) and No. of Edges (M)
    // Further Lines : Edges (M lines)

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < M; i++)
    {
        int firstNode, secondNode; // Reintialize firstNode and secondNode with every new edge
        cin >> firstNode >> secondNode;
        adj[firstNode][secondNode] = 1;
        adj[secondNode][firstNode] = 1;
    }

    cout << endl;
    print(adj);

    return 0;
}