#include <iostream>
#include <bits/stdc++.h>
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


int lengthOfLoop (Node* head) {
    unordered_map<Node*, int> visitedNodes;
    Node* temp = head;
    int timer = 1;

    while (temp != NULL) {
        if (visitedNodes.find(temp) != visitedNodes.end()) {
            int loopLength = timer - visitedNodes[temp];
            return loopLength;
        } else {
           visitedNodes[temp] = timer;
           temp = temp -> next;
           timer ++;
        }
    }

    return 0;
}

int lengthOfLoop2 (Node* head) {

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if (slow == fast) {
            // loop is present in the linked list
            int ctr = 1;
            fast = fast -> next;
            while (slow != fast) {
                ctr ++;
                fast = fast -> next;
            }
            return ctr;
        }
    }
    return 0;
}

int main() {
    // Create a sample linked
    // list with a loop
    
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Create a loop from
    // fifth to second
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    // This creates a loop
    fifth->next = second; 

    int loopLength = lengthOfLoop2 (head);
    if (loopLength > 0) {
        cout << "Length of the loop: " << loopLength << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }

    return 0;
}


