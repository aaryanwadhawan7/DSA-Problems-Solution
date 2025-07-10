/*
Leetcode 203 : Remove Linked List Elements

Given the head of a Linked List and an integer val,
remove all nodes of the Linked list that has Node.val == val, and return the new head.

*/

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node *next;

    Node(int val1, Node *next1)
    {
        val = val1;
        next = next1;
    }

    Node(int val2)
    {
        val = val2;
        next = nullptr;
    }
};

Node *convertToLL(vector<int> &nums, int vecSize)
{
    Node *head = new Node(nums[0]);
    // Don't alter head of the LL
    // Declare a ptr to head which pts to adjacent node to form LL
    Node *mover = head;
    for (int i = 1; i < vecSize; i++)
    {
        Node *temp = new Node(nums[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

// head = [1,2,6,3,4,5,6], val = 6
Node *removeElements(Node *head, int value)
{
    // Edge case : check if head has val as a property
    if (head != nullptr && head->val == value)
    {
        // remove head
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    Node *temp = head;
    while (temp != nullptr && temp -> next != nullptr)
    {
        if (temp-> next -> val == value)
        {
            // delete curr node 
            Node* curr = temp -> next;
            temp -> next = temp -> next -> next;
            delete curr;
        } else {
            temp = temp -> next;
        }
    }


    return head;
}

int main()
{
    vector<int> nums = {10, 12, 15, 14, 7, 12};
    int vecSize = nums.size();

    Node *head = convertToLL(nums, vecSize);

    head = removeElements (head,12);

    printLL (head);

    return 0;
}