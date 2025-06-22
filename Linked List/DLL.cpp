#include <iostream>
#include <vector>
using namespace std;

class Node {
    public :
    int data;
    Node* next;
    Node* back;

    public :
    // Constructor
    Node (int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    Node (int data2) {
        data = data2;
        next = nullptr;
        back = nullptr;
    }
};


Node* convertVecToLL (vector<int> &vec) {
    // DON'T ALTER THE HEAD PTR 
    Node* head = new Node (vec[0]);
    Node* mover = head;
    for (int i = 1; i < vec.size(); i++) {
        Node* temp = new Node(vec[i],nullptr,mover);
        mover -> next = temp;
        mover = mover -> next;
    }

    return head;
}


void printDLL (Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

Node* deleteHead (Node* head) {
    // Edge cases
    if (head == NULL) {
        return head;
    }

    if (head -> next == nullptr && head -> back == nullptr) {
        // single element is present -> Head / Tail is at the same position
        delete head;
        return NULL;
    }

    Node* temp = head;
    head = head -> next;
    temp -> next = nullptr;
    head -> back = nullptr;
    delete temp;
    return head;
}


Node* deleteTail (Node* head) {
    Node* tail = head;

    if (head == NULL) {
        return head;
    }

    if (head -> next == nullptr) {
        delete head;
        return nullptr;
    }

    while (tail -> next != nullptr) {
        // this will stop at the last node of LL
        tail = tail -> next;
    }

    Node* prev = tail -> back;
    prev -> next = nullptr;
    tail -> back = nullptr;
    delete tail;

    return head;
}


Node* deleteKth (Node* head, int k) {
    if (head == NULL) {
        return head;
    }

    // this will deal with the case when only 1 node is present
    // or when many nodes are present in the LL
    if (k == 1) {
        // Delete head 
        return deleteHead (head);
    }

    // First reach to the Kth element
    int cnt = 1;
    Node* temp = head;

    // After loop breaks, temp will be at the kth position.
    while (temp != NULL && cnt < k) {
        temp = temp -> next;
        cnt ++;
    }

    // if kth node doesn't exists (out of bound)
    if (temp == NULL) {
        return head;
    }

    Node* prev = temp -> back;
    Node* front = temp -> next;

    if (prev != NULL) {
        prev -> next = front;
    }

    if (front != NULL) {
        front -> back = prev;
    }

    temp -> next = nullptr;
    temp -> back = nullptr;
    delete temp;

    return head;
}


Node* deleteVal (Node* head, int val) {
    // edge cases
    if (head == NULL) {
        return head;
    }

    if (head -> data == val) {
        // delete head
        return deleteHead (head);
    }

    // pts towards the node where node data is equals to val
    Node* temp = head;
    while (temp -> data != val) {
        temp = temp -> next;
    }

    if (temp == NULL) {
        // node didn't exist (out of bound) 
        return head;
    }

    Node* prev = temp -> back;
    Node* front = temp -> next;
    if (prev -> next != NULL) {
        prev -> next = front;
    }

    if (front != NULL) {
        front -> back = prev;
    }

    // free temp node
    temp -> next = nullptr;
    temp -> back = nullptr;
    delete temp;

    return head;
}

Node* insertionBeforeHead (Node* head, int val) {
    // edge cases
    if (head == NULL) {
        return head;
    }

    Node* temp = head;
    Node* newNode = new Node(val,temp,nullptr);
    temp -> back = newNode;
    head = head -> back;

    return head;
}


Node* insertionBeforeTail (Node* head, int val) {
    if (head == NULL) {
        return head;
    }

    // find tail of LL
    Node* temp = head;

    if (temp -> next == nullptr) {
        // single node in LL -> Head/Tail
        return insertionBeforeHead (head,val);
    }


    while (temp -> next != nullptr) {
        temp = temp -> next;
    }

    // temp pts to tail of LL
    Node* prev = temp -> back;
    Node* newNode = new Node (val,temp,prev);
    prev -> next = newNode;
    temp -> back = newNode;

    return head;
}

Node* insertionKth (Node* head, int val, int k) {
    if (head == NULL) {
        return head;
    }

    if (k == 1) {
        return insertionBeforeHead (head, val);
    }

    Node* temp = head;
    int cnt = 1;
    while (temp != NULL && cnt < k) {
        temp = temp -> next;
        cnt ++;
    }

    if (temp == NULL) {
        // temp didn't exist -> k might be out of bound
        return head;
    }

    // temp -> Node at kth postn in LL
    Node* prev = temp -> back;
    Node* newNode = new Node (val,temp,prev);
    prev -> next = newNode;
    temp -> back = newNode;

    return head;
}

// Similar to insertionKth (head,val,k) but intuition will be slightly different

// Reverse the DLL (Doubly Linked-List)

Node* reverseDLL (Node* head) {
    // edge case
    if (head == NULL || head -> next == nullptr) {
        return head;
    }

    Node* currNode = head;
    Node* lastNode = NULL;

    while (currNode != NULL) {
        lastNode = currNode -> back;
        currNode -> back = currNode -> next;
        currNode -> next = lastNode;
        currNode = currNode -> back;
    }

    return lastNode -> back;
}


int main () {
    vector <int> vec = {10,11,12,15,20};
    Node* head = convertVecToLL (vec);

    // Deletion -> head, tail, kth element, Node
    // Insertion (before) -> head, tail, Kth, Node
    // head = insertionKth (head,20,3);

    head = reverseDLL (head);
    printDLL (head);

    return 0;
}