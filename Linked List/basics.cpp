#include <iostream>
#include <vector>
using namespace std;

// struct -> By default, it doesn't hide it's implementation details.
// class -> By default, class hide it's implementation details.
class Node {
    public :
    int data;
    Node* next;

    public:
    Node (int data1, Node* next1) {
        data = data1;
        next1 = next;
    }

    public:
    Node (int data1) {
        data = data1;
        next = nullptr;
    }
};

int main () {

    // int x = 10;
    // int* y = &x;
    // cout << y << endl;

    vector<int> vec = {10,12,14,4};
    //Node z = Node(10,nullptr); // object
    //cout << z.next << endl;
    Node* y = new Node(vec[0],nullptr);
    cout << y->data;

    return 0;
}