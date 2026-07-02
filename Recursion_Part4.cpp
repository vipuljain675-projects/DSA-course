/*
=========================================================
        LeetCode 46 & 47 - Permutations
=========================================================

---------------------------------------------------------
LeetCode 46 - Permutations

Given an array of DISTINCT integers,
return all possible permutations.

Example:
Input : [1,2,3]

Output:
[
 [1,2,3],
 [1,3,2],
 [2,1,3],
 [2,3,1],
 [3,1,2],
 [3,2,1]
]

Approach:
1. Choose an unused element.
2. Mark it used.
3. Add into current permutation.
4. Recurse.
5. Undo (Backtracking).

Time : O(n × n!)
Space: O(n)

=========================================================
LeetCode 47 - Permutations II

Given an array that MAY CONTAIN DUPLICATES,
return all UNIQUE permutations.

Example:
Input : [1,1,2]

Output:
[
 [1,1,2],
 [1,2,1],
 [2,1,1]
]

Extra Step:
1. Sort the array first.
2. Skip duplicate numbers carefully.

Condition:

if(i>0 && nums[i]==nums[i-1] && !used[i-1])
    continue;

Meaning:
If previous duplicate wasn't used in this branch,
skip current duplicate.

Time : O(n × n!)
Space: O(n)

=========================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//=========================================================
//                  LEETCODE 46
//=========================================================

class Solution46 {
public:

    void solve(vector<int>& nums,
               vector<int>& ans,
               vector<vector<int>>& result,
               vector<bool>& used)
    {
        // Base Case
        if(ans.size()==nums.size())
        {
            result.push_back(ans);
            return;
        }

        // Try every element
        for(int i=0;i<nums.size();i++)
        {
            if(used[i])
                continue;

            // Choose
            used[i]=true;
            ans.push_back(nums[i]);

            // Recurse
            solve(nums,ans,result,used);

            // Backtrack
            ans.pop_back();
            used[i]=false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> ans;
        vector<bool> used(nums.size(),false);

        solve(nums,ans,result,used);

        return result;
    }
};



//=========================================================
//                  LEETCODE 47
//=========================================================

class Solution47 {
public:

    void solve(vector<int>& nums,
               vector<int>& ans,
               vector<vector<int>>& result,
               vector<bool>& used)
    {
        // Base Case
        if(ans.size()==nums.size())
        {
            result.push_back(ans);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            // Already used
            if(used[i])
                continue;

            // Skip duplicates
            if(i>0 &&
               nums[i]==nums[i-1] &&
               !used[i-1])
            {
                continue;
            }

            // Choose
            used[i]=true;
            ans.push_back(nums[i]);

            // Recurse
            solve(nums,ans,result,used);

            // Backtrack
            ans.pop_back();
            used[i]=false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        // VERY IMPORTANT
        sort(nums.begin(),nums.end());

        vector<vector<int>> result;
        vector<int> ans;
        vector<bool> used(nums.size(),false);

        solve(nums,ans,result,used);

        return result;
    }
};



//=========================================================
//                      DRIVER CODE
//=========================================================

int main()
{
    //-----------------------------------------------------
    // LeetCode 46
    //-----------------------------------------------------

    Solution46 obj1;

    vector<int> nums1={1,2,3};

    vector<vector<int>> result1=obj1.permute(nums1);

    cout<<"========== LeetCode 46 ==========\n\n";

    for(auto permutation:result1)
    {
        cout<<"[ ";

        for(int num:permutation)
            cout<<num<<" ";

        cout<<"]\n";
    }


    //-----------------------------------------------------
    // LeetCode 47
    //-----------------------------------------------------

    Solution47 obj2;

    vector<int> nums2={1,1,2};

    vector<vector<int>> result2=obj2.permuteUnique(nums2);

    cout<<"\n\n========== LeetCode 47 ==========\n\n";

    for(auto permutation:result2)
    {
        cout<<"[ ";

        for(int num:permutation)
            cout<<num<<" ";

        cout<<"]\n";
    }

    return 0;
}