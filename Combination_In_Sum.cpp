/*
=========================================================
            LeetCode 39 - Combination Sum
=========================================================

Problem:
Given an array of distinct integers (candidates) and a
target value, return all unique combinations where the
chosen numbers sum to the target.

A number may be chosen UNLIMITED times.

---------------------------------------------------------
Example:

Input:
candidates = [2,3,6,7]
target = 7

Output:
[
 [2,2,3],
 [7]
]

---------------------------------------------------------
Approach : Backtracking

At every index we have two choices:

1. Take the current element
   - Add it to the answer.
   - Stay on the SAME index because the element
     can be used again.

2. Don't Take the current element
   - Move to the next index.

---------------------------------------------------------
Time Complexity:
Exponential (depends on target and candidates)

Space Complexity:
O(target)   (Recursion Stack)

=========================================================
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:

    //-----------------------------------------------------
    // Recursive Function
    //-----------------------------------------------------
    void solve(int idx,
               vector<int>& candidates,
               int target,
               vector<int>& ans,
               vector<vector<int>>& result)
    {

        // Base Case
        if (target == 0) {

            result.push_back(ans);
            return;
        }

        // Out of elements
        if (idx == candidates.size()) {
            return;
        }

        //-------------------------------------------------
        // TAKE
        //-------------------------------------------------
        if (candidates[idx] <= target) {

            ans.push_back(candidates[idx]);

            // Stay on same index
            solve(idx,
                  candidates,
                  target - candidates[idx],
                  ans,
                  result);

            // Backtracking
            ans.pop_back();
        }

        //-------------------------------------------------
        // DON'T TAKE
        //-------------------------------------------------
        solve(idx + 1,
              candidates,
              target,
              ans,
              result);
    }

    //-----------------------------------------------------
    // Main Function
    //-----------------------------------------------------
    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target)
    {

        vector<vector<int>> result;
        vector<int> ans;

        solve(0,
              candidates,
              target,
              ans,
              result);

        return result;
    }
};


//=========================================================
// Driver Code
//=========================================================

int main() {

    Solution obj;

    vector<int> candidates = {2,3,6,7};

    int target = 7;

    vector<vector<int>> result =
        obj.combinationSum(candidates, target);

    cout << "Possible Combinations\n\n";

    for (auto combination : result) {

        cout << "[ ";

        for (int num : combination) {
            cout << num << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}