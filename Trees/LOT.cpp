// Level Order Traversal

#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }

    Node(int val, Node *leftPtr, Node *rightPtr)
    {
        data = val;
        left = leftPtr;
        right = rightPtr;
    }
};

// TC : O (N) and SC : O (N), where N is the number of nodes in tree
vector<vector<int>> lot(Node *root)
{
    // Auxilary space to return the ans : O (N) 
    vector<vector<int>> ans;

    if (root == NULL)
    {
        return ans;
    }

    queue<Node*> q; 
    q.push(root); 

    while (!q.empty())
    {
        int qSize = q.size();
        // Iterate over the queue
        vector <int> level;
        for (int i = 0; i < qSize; i++) {
            Node* top = q.front();
            q.pop();
            level.push_back(top -> data);

            if (top -> left != nullptr) {
                q.push (top -> left);
            }
            if (top -> right != nullptr) {
                q.push (top -> right);
            }
        }
        ans.push_back(level);
    }

    return ans;
}

// Depth First Search 
// Tc -> O(N), Sc -> O (N) [Incase of degenerate ot skew binary tree]
int maxDepth  (Node* root) {
    if (root == NULL) {
        return 0;
    }

    // Recursive fn to calculate the height of left subtree
    int leftHeight = maxDepth (root -> left);
    int rightHeight = maxDepth (root -> right);

    return 1 + max (leftHeight, rightHeight);
}

// Breadth First Search (Level Order Traversing)
// Sc : O (N) [Queue DS] and Tc : O(N)
int maxDepthBFS (Node* root) {
    if (root == NULL) {
        return 0;
    }

    int depth = 0;
    queue <Node* > q;
    q.push (root);

    while (!q.empty()) {
        int qSize = q.size ();
        for (int i = 0; i < qSize; i++) {
            Node* node = q.front();
            q.pop();

            if (node -> left != nullptr) {
                q.push(node -> left);
            }

            if (node -> right != nullptr) {
                q.push (node -> right);
            }
        }
        depth ++;
    }

    return depth;
}

// Tc : O(n), Sc : O(2n)
vector <int> topViewBT (Node* root) {
    vector <int> ans;
    if (root == NULL) {
        return ans;
    }

    queue <pair <Node*, int>> q;
    // pair => (Node*, line)
    map <int, int> mpp;

    // Initially push the root node to q
    q.push ({root, 0});

    while (!q.empty()) {
        // If node corresponding to a line didn't exist then push it into q
        // Check for left and right ptr nodes and push it to queue
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;

        if (mpp.find (line) == mpp.end()) mpp[line] = node -> data;

        if (node -> left != nullptr) {
            q.push ({node -> left, line-1});
        }

        if (node -> right != nullptr) {
            q.push ({node -> right, line+1});
        }
    }

    for (auto it : mpp) {
        ans.push_back(it.second);
    }

    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> res = lot(root);

    cout << "Level Order Traversal : " << endl;
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
    }
    cout << endl;

    int heightOfBT = maxDepth (root);
    //cout << "Height of the binary tree : " << heightOfBT;
    cout << "height : "<< maxDepthBFS (root) << endl;

    // Top View of the Binary Tree
    vector <int> topView = topViewBT (root);
    for (int i = 0; i < topView.size(); i++) {
        cout << topView [i] << " ";
    }
    cout << endl;

    return 0;
}