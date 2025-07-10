#include <iostream>
#include <vector> 
using namespace std;

class Node {
    public :
    int data;
    Node* next;
    Node* back;

    // constructor
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


Node* convertVecToDLL (vector<int> &vec, int vecSize) {
    Node* head = new Node(vec[0]); 
    Node* mover = head;
    // head -> next = nullptr; 
    // head -> back = nullptr;
    for (int i = 1; i < vecSize; i++) {
        Node* temp = new Node(vec[i],nullptr,mover);
        mover -> next = temp;
        mover = mover -> next;
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


Node* reverseDLL (Node* head) {
    if (head == NULL && head -> next == nullptr) {
        return head;
    }

    Node* prev = NULL;
    Node* temp = head;

    while (temp != NULL) {
        prev = temp -> back;
        temp -> back = temp -> next;
        temp -> next = prev;
        temp = temp -> back;
    }

    return prev -> back;
}


int main () {
    vector <int> vec = {10,12,15,20,25};
    int vecSize = vec.size();

    Node* head = convertVecToDLL (vec, vecSize);
    print(head);
    cout << endl;
    head = reverseDLL(head);
    print(head);

    return 0;
}