#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *child;

    Node(int data, Node *next1, Node *child1)
    {
        val = data;
        next = next1;
        child = child1;
    }

    Node(int data2)
    {
        val = data2;
        next = nullptr;
        child = nullptr;
    }

    Node()
    {
        val = 0;
        next = nullptr;
        child = nullptr;
    }
};

void merge(int st, int end, int mid, vector<int> &vec)
{

    int i = st;
    int j = mid;

    vector<int> temp;
    while (i <= mid && j <= end)
    {
        if (vec[i] <= vec[j])
        {
            temp.push_back(vec[i]);
            i++;
        }
        else
        {
            temp.push_back(vec[j]);
            j++;
        }
    }

    while (st <= mid)
    {
        temp.push_back(vec[i]);
        i++;
    }

    while (j <= end)
    {
        temp.push_back(vec[j]);
        j++;
    }

    for (int k = st; k <= end; k++)
    {
        vec[k] = temp[k - st];
    }
}

void mergeSort(int st, int end, vector<int> &vec)
{

    // D&C ->
    // 1) Divide the vec into sorted half
    // 2) Merge the two sorted half into one sorted vec using 2 ptrs

    // 1    2    3    10
    // st             end

    // 1    2    3
    // st        end

    if (st >= end)
    {
        return;
    }

    while (st < end)
    {
        int mid = st + (end - st) / 2;
        // Divide
        mergeSort(0, mid, vec);
        mergeSort(mid + 1, end, vec);
        // Merge
        merge(st, end, mid, vec);
    }
}

void printOriginalLL(Node *head, int depth)
{
    while (head != nullptr)
    {
        // Indentation based on current depth
        for (int i = 0; i < depth; i++)
        {
            cout << "| ";
        }

        // Print current node's value
        cout << head->val << endl;

        // Recursively print the child list
        if (head->child)
        {
            printOriginalLL(head->child, depth + 1);
        }

        head = head->next;
    }
}

Node *convertVecToLL(vector<int> &vec)
{
    Node *head = new Node(vec[0]);
    Node *temp = head;

    for (int i = 1; i < vec.size(); i++)
    {
        Node *newNode = new Node(vec[i]);
        temp->next = newNode;
        temp = temp->next;
    }

    return head;
}

Node *flattenedLinkedList(Node *head)
{
    vector<int> vec;

    if (head == NULL)
    {
        return head;
    }

    // ptr : to traverse over the head
    Node *temp = head;
    while (temp != NULL)
    {
        // add temp data to vec
        vec.push_back(temp->val);

        if (temp->child)
        {
            Node *childNodes = temp->child;
            while (childNodes != nullptr)
            {
                vec.push_back(childNodes->val);
                childNodes = childNodes->child;
            }
        }

        // after this we have added all child nodes corresponding to the particular head
        temp = temp->next;
    }

    int st = 0;
    int end = vec.size() - 1;
    mergeSort(st, end, vec);

    head = convertVecToLL(vec);

    return head;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->child;
    }
}

Node *merge2LL(Node *list1, Node *list2)
{
    // Two pointers
    // Remember : next ptr points to nullptr

    Node *dummyNode = new Node(-1);
    Node *mover = dummyNode;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            mover->child = list1;
            list1 = list1->child;
        }
        else
        {
            mover->child = list2;
            list2 = list2->child;
        }

        mover = mover -> child;
        mover->next = nullptr;
    }

    if (list1 != NULL)
    {
        mover->child = list1;
    }

    if (list2 != NULL)
    {
        mover->child = list2;
    }

    if (dummyNode->child)
    {
        dummyNode->child->next = NULL;
    }

    return dummyNode->child;
}

// TC : O (n * 2m) and SC : O(1)
Node *OptimalApproach(Node *head)
{

    // if there is single head then if the subsequent child exists
    // then they are linked in sorted manner
    if (head == NULL || head->next == nullptr)
    {
        return head;
    }

    // Big Problem -> convert the given linked list format into a single flattened linked list
    // Small Problem -> consider the linked list is flattened via recursion
    Node *newHead = OptimalApproach(head->next);
    return merge2LL(head, newHead);
}

int main()
{

    /*

    (head)
    5   ->   10   ->  12   ->  7  -> nullptr
    |        |        |        |
    14       4        20      17
                      |
                      13

    */

    Node *head = new Node(5);
    head->child = new Node(14);

    head->next = new Node(10);
    head->next->child = new Node(4);

    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);

    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    // print the original linked list structure
    printOriginalLL(head, 0);

    head = OptimalApproach(head);

    printLL(head);

    return 0;
}