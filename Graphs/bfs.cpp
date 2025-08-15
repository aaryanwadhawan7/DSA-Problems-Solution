#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(int N, int M, vector<int> adj[])
{
    queue<int> q;
    q.push(1);
    int visited[N+1] = {0}; 
    visited[1] = 1;
    vector<int> ans;
    ans.push_back(1);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // check for neighbour nodes of the curr node
        for (auto element : adj[node])
        {
            if (!visited[element])
            {
                ans.push_back(element);
                visited[element] = 1;
                q.push(element);
            }
            // curr node is already present in the queue
        }
    }

    return ans;
}

void print(int N, vector<int> adj[])
// N -> 5 (1 to 5)
{
    cout << "Printing Adjacency List : " << endl;
    for (int i = 1; i <= N; i++)
    {
        cout << i << " -> ";
        for (auto itr : adj[i])
        {
            cout << itr << " ";
        }
        cout << endl;
    }
}

int main()
{

    int N, M;
    // N -> # of Nodes
    // M -> # of Edges
    cin >> N >> M;
    vector<int> adj[N+1]; // adjacency list
    // 1, 2, 3, 4, 5 -> Nodes/Vertices
    for (int i = 0; i < M; i++)
    // i -> 1, 2, 3, 4, 5, 6, 7
    {
        int firstNode, secondNode;
        cin >> firstNode >> secondNode;
        // Add edge
        adj[firstNode].push_back(secondNode);
        adj[secondNode].push_back(firstNode);
    }

    cout << endl;
    print(N, adj);
    cout << endl;

    vector<int> traversal = bfs(N, M, adj);
    cout << "Breadth First Traversal : " << endl;
    for (auto itr : traversal)
    {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}