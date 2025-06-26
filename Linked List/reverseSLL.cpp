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


Node* convertVecToSLL (vector<int> &vec, int vecSize) {
    Node* head = new Node(vec[0]);
    Node* mover = head;

    for (int i = 1; i < vecSize; i++) {
        Node* temp = new Node(vec[i]);
        mover -> next = temp;
        mover = temp;
    }

    return head;
}


void print (Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}


// TC : O(N), SC : O(N)
Node* reverseRecursion (Node* head) {
    if (head == NULL || head -> next == nullptr) {
        return head;
    }

    Node* newNode = reverseRecursion(head -> next);

    Node* front = head -> next;
    front -> next = head;
    head -> next = nullptr;

    return newNode;
}


int main () {
    vector<int> vec = {10,12,15,20,25};
    int vecSize = vec.size();
    

    Node* head = convertVecToSLL (vec, vecSize);
    print (head);
    cout << endl;


    head = reverseRecursion(head);
    print (head);

    return 0;
}