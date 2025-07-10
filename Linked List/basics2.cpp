#include <iostream>
using namespace std;

class Node {
    public :
    int data;
    Node* next;

    Node (int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node (int data2) {
        data = data2;
        next = nullptr;
    }
};

Node* convertArrToLL (int arr[], int size) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < size; i++) {
        // create a new node 
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

// O(n)
int lengthOfLL (Node* head) {
    // NEVER EVER TEMPER THE HEAD PTR
    int cnt = 0;
    Node* temp = head;
    while (temp != nullptr) {
        cnt++;
        temp = temp -> next;
    }

    return cnt;
}

bool searchElement (Node* head, int target) {
    Node* temp = head;
    while (temp) {
        if (temp -> data == target) {
            return true;
        }
        temp = temp -> next;
    }

    return false;
}

int main () {
    int arr[] = {7,3,12,45,6};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node* head = convertArrToLL (arr,size);
    // cout << head -> data << endl;

    // LL TRAVERSAL : O(n)
    cout << "Traversing the Linked List : " << endl;
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;

    // LENGTH OF LL
    int len = lengthOfLL (head);
    cout << "Length of the Linked List :  " << len << endl;

    // LINEAR SEARCH IN LL : O(n)
    int target = 6;
    bool val = searchElement(head,target);
    cout << "Is " << target << " is present in LL : " << val << endl;
    return 0;
}