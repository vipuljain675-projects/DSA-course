#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < 2 * n; i++) {

            int num = nums[i % n];

            while (!st.empty() && nums[st.top()] < num) {
                ans[st.top()] = num;
                st.pop();
            }

            if (i < n) {
                st.push(i);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 1};

    vector<int> ans = sol.nextGreaterElements(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}