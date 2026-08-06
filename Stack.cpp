#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

//==================================================
// 1. Stack using Vector
//==================================================
class StackVector {
    vector<int> v;

public:
    void push(int val) {
        v.push_back(val);
    }

    void pop() {
        if (v.empty()) {
            cout << "Stack Underflow!\n";
            return;
        }
        v.pop_back();
    }

    int top() {
        if (v.empty()) {
            cout << "Stack is Empty!\n";
            return -1;
        }
        return v.back();
    }

    bool empty() {
        return v.empty();
    }

    int size() {
        return v.size();
    }

    void display() {
        if (v.empty()) {
            cout << "Stack is Empty!\n";
            return;
        }

        cout << "Top -> ";
        for (int i = v.size() - 1; i >= 0; i--)
            cout << v[i] << " ";
        cout << endl;
    }
};

//==================================================
// 2. Stack using Linked List (STL list)
//==================================================
class StackLL {
    list<int> ll;

public:
    void push(int val) {
        ll.push_front(val);
    }

    void pop() {
        if (ll.empty()) {
            cout << "Stack Underflow!\n";
            return;
        }
        ll.pop_front();
    }

    int top() {
        if (ll.empty()) {
            cout << "Stack is Empty!\n";
            return -1;
        }
        return ll.front();
    }

    bool empty() {
        return ll.empty();
    }

    int size() {
        return ll.size();
    }

    void display() {
        if (ll.empty()) {
            cout << "Stack is Empty!\n";
            return;
        }

        cout << "Top -> ";
        for (int x : ll)
            cout << x << " ";
        cout << endl;
    }
};

//==================================================
// 3. Stack using STL stack
//==================================================
class StackSTL {
    stack<int> st;

public:
    void push(int val) {
        st.push(val);
    }

    void pop() {
        if (st.empty()) {
            cout << "Stack Underflow!\n";
            return;
        }
        st.pop();
    }

    int top() {
        if (st.empty()) {
            cout << "Stack is Empty!\n";
            return -1;
        }
        return st.top();
    }

    bool empty() {
        return st.empty();
    }

    int size() {
        return st.size();
    }

    // Display stack without modifying the original stack
    void display() {
        if (st.empty()) {
            cout << "Stack is Empty!\n";
            return;
        }

        stack<int> temp = st;

        cout << "Top -> ";
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

//==================================================
// Driver Code
//==================================================
int main() {

    //================ Vector ==================
    cout << "========== Stack using Vector ==========\n";

    StackVector sv;
    sv.push(10);
    sv.push(20);
    sv.push(30);
    sv.push(40);

    sv.display();
    cout << "Top Element : " << sv.top() << endl;
    cout << "Size        : " << sv.size() << endl;

    sv.pop();
    cout << "After Pop : ";
    sv.display();

    //================ Linked List ==================
    cout << "\n========== Stack using Linked List ==========\n";

    StackLL sl;
    sl.push(100);
    sl.push(200);
    sl.push(300);
    sl.push(400);

    sl.display();
    cout << "Top Element : " << sl.top() << endl;
    cout << "Size        : " << sl.size() << endl;

    sl.pop();
    cout << "After Pop : ";
    sl.display();

    //================ STL Stack ==================
    cout << "\n========== Stack using STL stack ==========\n";

    StackSTL ss;
    ss.push(1000);
    ss.push(2000);
    ss.push(3000);
    ss.push(4000);

    ss.display();
    cout << "Top Element : " << ss.top() << endl;
    cout << "Size        : " << ss.size() << endl;

    ss.pop();
    cout << "After Pop : ";
    ss.display();

    return 0;
}