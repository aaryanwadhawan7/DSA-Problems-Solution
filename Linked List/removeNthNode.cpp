#include <iostream>
#include <vector>
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

Node* convertToLL (vector<int>& vec, int vecSize) {
    Node* head = new Node (vec[0]);
    Node* mover = head;

    for (int i = 1; i < vecSize; i++) {
        Node* temp = new Node (vec[i]);
        mover -> next = temp;
        mover = mover -> next;
    }

    return head;
}


void printLL (Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}


Node* deleteNthFromBack (Node* head, int x) {
     //    -1       ->      10     ->     12    ->    15     ->    20      ->    25 
     //  dummyNode        head                       temp    


    // Count the number of nodes of the LL
    Node* dummyNode = new Node (-1);
    dummyNode -> next = head;
    Node* temp = dummyNode;

    int cnt = 0;
    while (temp != NULL) {
        cnt ++;
        temp = temp -> next;
    }

    int diff = cnt - x;

    // Reach the node to be removed from the Linked List
    temp = head;
    for (int i = 0; i < diff; i++) {
        temp = temp -> next;
        // ptr will reach at the node just before the node to be remove from the Linked List
    } 

    Node* nodeToRemove = temp -> next;
     if (nodeToRemove -> next == nullptr) {
        // nodeToRemove is the tail of the LL
        temp -> next = nullptr;
        return head;
    }


    temp -> next = nodeToRemove -> next;
    nodeToRemove -> next = nullptr;
    delete nodeToRemove;

    Node* newHead = dummyNode -> next;
    dummyNode -> next =  nullptr;
    delete dummyNode;

    return head;
}


int main () {
    vector<int> vec = {10,12,15,20,25};
    //                 1  2  3  4  5
    int vecSize = vec.size();

    Node* head = convertToLL (vec,vecSize);
    printLL (head);

    head = deleteNthFromBack (head, 2);
    // means we have to remove node with val 20 from the back
    printLL (head);

    return 0;
}