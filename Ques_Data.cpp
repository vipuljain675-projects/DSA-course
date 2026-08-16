#include <iostream>
#include <queue>
#include <deque>
using namespace std;

// =====================================================
// 1. Queue using STL
// Functions: push(), pop(), front()
// =====================================================
void stlQueueDemo() {
    queue<int> q;

    // push() -> insert at rear
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "STL Queue\n";
    cout << "Front: " << q.front() << endl;

    // pop() -> removes from front
    q.pop();

    cout << "After pop(), Front: " << q.front() << endl;
}


// =====================================================
// 2. Queue using Linked List
// Functions: push(), pop(), front()
// =====================================================
class LinkedListQueue {
private:
    struct Node {
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
    };

    Node* frontNode;
    Node* rearNode;

public:
    LinkedListQueue() {
        frontNode = nullptr;
        rearNode = nullptr;
    }

    // push(): Insert element at the rear
    void push(int value) {
        Node* newNode = new Node(value);

        if (rearNode == nullptr) {
            // Queue is empty
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
    }

    // pop(): Remove element from the front
    void pop() {
        if (frontNode == nullptr) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = frontNode;
        frontNode = frontNode->next;

        // If queue becomes empty
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }

        delete temp;
    }

    // front(): Return the front element
    int front() {
        if (frontNode == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }

        return frontNode->data;
    }

    ~LinkedListQueue() {
        while (frontNode != nullptr) {
            pop();
        }
    }
};


// =====================================================
// 3. Deque using STL
// Double-Ended Queue
//
// push_front()  -> insert at front
// push_back()   -> insert at rear
// pop_front()   -> remove from front
// pop_back()    -> remove from rear
// front()       -> access front
// back()        -> access rear
// =====================================================
void dequeDemo() {
    deque<int> dq;

    // Insert from rear
    dq.push_back(20);
    dq.push_back(30);

    // Insert from front
    dq.push_front(10);

    cout << "Deque\n";

    cout << "Front: " << dq.front() << endl;
    cout << "Rear: " << dq.back() << endl;

    // Remove from front
    dq.pop_front();

    cout << "After pop_front(), Front: "
         << dq.front() << endl;

    // Remove from rear
    dq.pop_back();

    cout << "After pop_back(), Rear: "
         << dq.back() << endl;
}


// =====================================================
// Main
// =====================================================
int main() {

    // ---------- STL Queue ----------
    stlQueueDemo();

    cout << "\n--------------------------\n\n";

    // ---------- Linked List Queue ----------
    LinkedListQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Linked List Queue\n";
    cout << "Front: " << q.front() << endl;

    q.pop();

    cout << "After pop(), Front: "
         << q.front() << endl;

    q.pop();

    cout << "After another pop(), Front: "
         << q.front() << endl;

    cout << "\n--------------------------\n\n";

    // ---------- Deque ----------
    dequeDemo();

    return 0;
}