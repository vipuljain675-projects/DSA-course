#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> previousSmallerElement(vector<int>& arr) {

        vector<int> ans;
        stack<int> st;

        // Traverse from left to right
        for (int num : arr) {

            // Remove all elements greater than or equal to current
            while (!st.empty() && st.top() >= num) {
                st.pop();
            }

            // If stack is empty, no previous smaller exists
            if (st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());

            // Push current element
            st.push(num);
        }

        return ans;
    }
};

int main() {

    Solution obj;

    // Example Input
    vector<int> arr = {4, 5, 2, 10, 8};

    vector<int> result = obj.previousSmallerElement(arr);

    cout << "Array: ";
    for (int x : arr)
        cout << x << " ";

    cout << "\n\nPrevious Smaller Elements: ";
    for (int x : result)
        cout << x << " ";

    cout << endl;

    return 0;
}