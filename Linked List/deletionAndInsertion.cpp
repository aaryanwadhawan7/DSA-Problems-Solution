#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
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


Node* convertToLL (vector<int> &nums, int vecSize) {
    Node* head = new Node(nums[0]);
    Node* mover = head;
    for (int i = 1; i < vecSize; i++) {
        // i -> [1 to vecSize]
        Node* temp = new Node(nums[i]);
        mover -> next = temp;
        mover = temp;
    }

    return head;
}


void print (Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}


Node* deleteHead (Node*  head) {
    if (head == NULL) return head;
    Node* temp = head;
    // point the head ptr to next element
    head = head -> next;
    // C++ doesn't have garbage collector so we need to free the space 
    // allocated to prev head node manually
    delete temp;
    return head;
}


Node* deleteTail (Node* head) {
    // in case of sigle node, head and tail points to same element
    // then on deleting the node it will give us NULL

    if (head == NULL || head -> next == NULL) {
        return NULL;
    }

    Node* temp = head;
    // go to 2nd last node of LL
    while(temp -> next -> next != NULL) {
        temp = temp -> next;
    }

    delete temp -> next;
    temp -> next = nullptr;

    return head;
}


Node* deleteKth (Node* head, int k) {
    if (head == NULL) {
        return head;
    }

    // k == 1 : Remove head of LL
    if (k == 1) {
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }

    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while (temp) {
        cnt ++;
        if (cnt == k) {
            prev -> next = prev -> next -> next;
            delete temp;
            break;
        } else {
            // update prev node
            prev = temp;
            // move temp to next node
            temp = temp -> next;
        }
    }

    return head;
}


Node* removeEle (Node* head, int val) {
    if (head == NULL) {
        return head;
    }

    if (head -> data == val) {
        // remove head of LL
        Node* temp = head;
        head = head -> next;
        free (temp);
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL) {
        if (temp -> data == val) {
            prev -> next = prev -> next -> next;
            delete temp;
            break;
        } else {
            prev = temp;
            temp = temp -> next;
        }
    }

    return head;
}

Node* insertAtHead (Node* head, int value) {
    Node* newNode = new Node(value,head);

    return newNode;
}

Node* insertAtTail (Node* head, int value) {
    Node* newNode = new Node(value,nullptr);
    // point towards the last node of LL

    Node* temp = head;
    while (temp != NULL && temp -> next != nullptr) {
        temp = temp -> next;
    }

    temp -> next = newNode;

    return head;
}

Node* insertKth (Node* head, int  k, int value) {
    Node* newNode = new Node (value);

    if (k == 1) {
        // insert at head
        newNode -> next = head;
        return head;
    }
    
    Node* temp = head;
    int cnt = 0;
    while (temp -> next != nullptr) {
        cnt ++;
        if (cnt == k - 1) {
            Node* newNode = new Node(value);
            newNode -> next = temp -> next;
            temp -> next = newNode;
        } else {
            temp = temp -> next;
        }
    }
    
    return head;
}

Node* insertAtValue (Node* head, int value) {
    if (head == NULL) {
        return head;
    }

    if (head != NULL && head -> data == value) {
        // insert at head
        Node* newNode = new Node(value);
        Node* temp = head;
        newNode -> next = temp -> next;
        head -> next = newNode;
        delete temp;
        return head;
    }

    Node* temp = head -> next;
    while (temp -> next != nullptr) {
        if (temp -> data == value) {
            Node* newNode = new Node (value);
            newNode -> next = temp -> next;
            temp -> next = newNode;
            break;
        } else {
            temp = temp -> next;
        }
    }

    return head;
}


Node* reverseLL (Node* head) {
    if (head == NULL || head -> next == nullptr) {
        // means either head pts to NULL or 
        // there is single element in LL (head/tail)
        return head;
    }

    // 2 pointer approach
    Node* currNode = head;
    Node* prevNode = NULL;

    while (currNode != NULL) {
        Node* front = currNode -> next;
        currNode -> next = prevNode;
        prevNode = currNode;
        currNode = front;
    }

    return prevNode;
}


int main () {
    vector <int> nums = {10,12,15,8,7};
    int vecSize = nums.size();

    Node * head = convertToLL (nums,vecSize);

    // print(head);

    // 1. Delete the head of LL
    // head = deleteHead(head);

    // 2. Delete the tail of LL
    // head = deleteTail (head);

    // 3. Delete the kth node of LL
    // head = deleteKth (head,5);

    // 4. Delete the element with particular val
    // head = removeEle (head,15);

    // 5. Insert Node at the head of LL
    // head = insertAtHead (head, 100);

    // 6. Insert at tail 
    // head = insertAtTail (head, 200);

    // 7. Insert at Kth element
    // head = insertKth (head, 3, 24);

    // 8. Insert Node at val
    // head = insertAtValue (head, 12);

    head = reverseLL (head);
    print(head);

    return 0;
}