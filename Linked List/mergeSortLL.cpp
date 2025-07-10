#include <iostream>
#include <vector>
using namespace std;

class ListNode
{

public:
    int val;
    ListNode *next;

    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }

    ListNode(int data2)
    {
        val = data2;
        next = nullptr;
    }
};

ListNode *convertVecToLL(vector<int> &vec, int vecSize)
{
    ListNode *head = new ListNode(vec[0]);
    ListNode *mover = head;

    for (int i = 1; i < vecSize; i++)
    {
        ListNode *newNode = new ListNode(vec[i]);
        mover->next = newNode;
        mover = mover->next;
    }

    return head;
}

void printLL(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

ListNode *middleNode(ListNode *head)
{

    // we have to get at a node just before the middle node of LL
    ListNode *slow = head;
    ListNode *fast = head;
    fast = fast->next;

    while (fast != NULL && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

ListNode *mergeTwoSortedLL(ListNode *head1, ListNode *head2)
{

    if (head1 == NULL)
    {
        return head2;
    }

    if (head2 == NULL)
    {
        return head1;
    }

    ListNode *dummyNode = new ListNode(-1);
    ListNode *mover = dummyNode;

        while (head1 != NULL && head2 != NULL)
    {
        if (head1->val < head2->val)
        {
            mover->next = head1;
            head1 = head1->next;
            mover = mover->next;
        }
        else
        {
            mover->next = head2;
            head2 = head2->next;
            mover = mover->next;
        }
    }

    if (head1 != NULL)
    {
        mover->next = head1;
        head1 = head1->next;
    }

    if (head2 != NULL)
    {
        mover->next = head2;
        head2 = head2->next;
    }

    ListNode *newHead = dummyNode->next;
    dummyNode->next = nullptr;
    delete dummyNode;
    return newHead;
}

ListNode *mergeSortLL(ListNode *head)
{
    if (head == NULL || head->next == nullptr)
    {
        return head;
    }

    // Split the LL into 2 halves
    ListNode *head1 = head;
    ListNode *middleNodeOfLL = middleNode(head);
    ListNode *head2 = middleNodeOfLL->next;
    middleNodeOfLL->next = nullptr;

    head1 = mergeSortLL(head1);
    head2 = mergeSortLL(head2);

    return mergeTwoSortedLL(head1, head2);
}

int main()
{

    vector<int> vec = {10, 12, 15, 11};
    int size = vec.size();

    ListNode *head = convertVecToLL(vec, size);
    printLL(head);
    cout << endl;

    // Implement mergeSort func() for LL
    ListNode *newHead = mergeSortLL(head);
    printLL(newHead);

    return 0;
}