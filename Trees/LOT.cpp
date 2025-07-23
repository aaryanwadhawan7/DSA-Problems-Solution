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


// Tc : O (n)
// Sc : O (n) [Incomplete binary tree, due to increased in the # of leaf nodes complexity increases]
vector <int> zigZagTraversal (Node* root) {
    vector <int> ans;
    if (root == NULL) {
        return ans;
    }

    queue <Node*> q;
    q.push (root);

    bool leftToRight = true;

    while (!q.empty ()) {
        int qSize = q.size();
        vector <int> level(qSize);

        for (int i = 0; i < qSize; i++) {
            Node* curr = q.front ();
            q.pop ();

            // push curr data
            int index = (leftToRight) ? i : qSize - 1 - i;
            level[index] = curr -> data;

            if (curr -> left != nullptr) {
                q.push (curr -> left);
            }

            if (curr -> right != nullptr) {
                q.push (curr -> right);
            }
        }
        // after each level we have to change the order of pushing the nodes val into vector
        leftToRight = !leftToRight;
        for (auto it : level) {
            ans.push_back(it);
        }
    }

    return ans;
}


void leftBoundaryTraversal (Node* root, vector<int> &ans) {
    // curr node is nullptr
    if (root == NULL) {
        return;
    }

    // curr node is leaf node
    if (root -> left == NULL && root -> right == NULL) {
        return;
    }


    // curr node is not nullptr and it is not leaf node
    ans.push_back(root -> data);

   if (root -> left != nullptr) {
    leftBoundaryTraversal (root -> left, ans);
   } else {
    leftBoundaryTraversal (root -> right, ans);
   }
}


void traversingAllLeafNodes (Node* root, vector<int> &ans) {
    if (root == NULL) {
        // backtracking
        return;
    }

    if (root -> left == NULL && root -> right == NULL) {
        ans.push_back (root -> data);
    }

    // curr node is not leaf node
    traversingAllLeafNodes (root -> left, ans);
    traversingAllLeafNodes (root -> right, ans);
}


void rightBoundaryTraversal (Node* root, vector<int> &ans) {
    Node* originalRoot = root;

    if (root == NULL || (root -> left == NULL && root -> right == NULL)) {
        return;
    }

    if (root -> right != nullptr) {
        rightBoundaryTraversal (root -> right, ans);
    } else {
        rightBoundaryTraversal (root -> left, ans);
    }

    // backtracking
    ans.push_back (root -> data);
}


vector <int> boundaryTraversal (Node* root) {
    vector <int> ans;
    if (root == NULL) {
        return ans;
    }

    // left part except leaf nodes
    leftBoundaryTraversal (root, ans);
    // printing all leaf nodes
    traversingAllLeafNodes (root, ans);
    // right part except leaf nodes
    rightBoundaryTraversal (root, ans);

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

    // LOT 
    cout << "Level Order Traversal : " << endl;
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
    }
    cout << endl;


    // Height of BT
    int heightOfBT = maxDepth (root);
    //cout << "Height of the binary tree : " << heightOfBT;
    cout << "height : "<< maxDepthBFS (root) << endl;



    // Top View of the Binary Tree
    cout << "Top View of BT : " << endl;
    vector <int> topView = topViewBT (root);
    for (int i = 0; i < topView.size(); i++) {
        cout << topView [i] << " ";
    }
    cout << endl;


    // Zig Zag Traversal
    cout << "Zig Zag Traversal : " << endl;
    vector <int> zigZag = zigZagTraversal (root);
    for (auto it : zigZag) {
        cout << it << " ";
    }
    cout << endl;


    // Boundary Traversal 
    cout << "Boundary Traversal : " << endl;
    vector <int> bt = boundaryTraversal (root);
    for (auto it : bt) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}