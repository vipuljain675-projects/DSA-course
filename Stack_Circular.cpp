#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int cap;
    int currSize;
    int f;
    int r;

public:
    CircularQueue(int size) {
        cap = size;
        arr = new int[cap];
        f = 0;
        r = -1;
        currSize = 0;
    }

    // Function 1: Push / Enqueue
    void push(int data) {
        if (currSize == cap) {
            cout << "CQ is FULL\n";
            return;
        }

        r = (r + 1) % cap;
        arr[r] = data;
        currSize++;
    }

    // Function 2: Pop / Dequeue
    void pop() {
        if (empty()) {
            cout << "CQ is EMPTY\n";
            return;
        }

        f = (f + 1) % cap;
        currSize--;
    }

    // Function 3: Check if queue is empty
    bool empty() {
        return currSize == 0;
    }
};

int main() {
    CircularQueue cq(5);

    cq.push(10);
    cq.push(20);
    cq.push(30);

    cq.pop();

    return 0;
}