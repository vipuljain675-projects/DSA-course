#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {
    }

    void push(int x) {

        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element into s1
        s1.push(x);

        // Move everything back from s2 to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {

        int val = s1.top();
        s1.pop();

        return val;
    }

    int peek() {

        return s1.top();
    }

    bool empty() {

        return s1.empty();
    }
};

int main() {

    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl;

    cout << "Popped: " << q.pop() << endl;
    cout << "Popped: " << q.pop() << endl;

    cout << "Front element: " << q.peek() << endl;

    cout << "Is queue empty? "
         << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}