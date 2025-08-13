#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val, Node *nextPtr)
    {
        data = val;
        next = nextPtr;
    }

    Node(int val2)
    {
        data = val2;
        next = nullptr;
    }
};

Node *reverseKGrps(Node *head, int k)
{
    Node *temp = head;
    int cnt = 0;

    // Check if there are at least k nodes
    while (cnt < k && temp != nullptr)
    {
        temp = temp->next;
        cnt++;
    }
    if (cnt < k)
        return head; // not enough nodes

    // Reverse exactly k nodes
    Node *prevNode = reverseKGrps(temp, k); // recursion for the rest
    cnt = 0;
    while (cnt < k && head != nullptr)
    {
        Node *next = head->next;
        head->next = prevNode;
        prevNode = head;
        head = next;
        cnt++;
    }

    return prevNode;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int k = 3;
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    print(head);

    Node *newHead = reverseKGrps(head, k);

    cout << "Reversed in groups of " << k << ": ";
    print(newHead);

    return 0;
}
