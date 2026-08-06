#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<pair<int, int>> st;

public:
    MinStack() {
    }

    void push(int val) {

        if (st.empty()) {
            st.push({val, val});
        }
        else {
            int minVal = min(val, st.top().second);
            st.push({val, minVal});
        }
    }

    void pop() {
        if (!st.empty())
            st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

int main() {

    MinStack s;

    s.push(-2);
    s.push(0);
    s.push(-3);

    cout << "Minimum = " << s.getMin() << endl;

    s.pop();

    cout << "Top = " << s.top() << endl;
    cout << "Minimum = " << s.getMin() << endl;

    return 0;
}