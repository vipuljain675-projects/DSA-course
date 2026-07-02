/*
=========================================================
        LeetCode 131 - Palindrome Partitioning
=========================================================

Problem:
Given a string s, partition it such that every substring
of the partition is a palindrome.

Return all possible palindrome partitions.

---------------------------------------------------------
Example:

Input:
s = "aab"

Output:
[
    ["a","a","b"],
    ["aa","b"]
]

---------------------------------------------------------
Approach : Backtracking

1. Start from index = 0.
2. Try every possible substring.
3. If the substring is a palindrome:
      - Add it to current answer.
      - Recurse for remaining string.
      - Backtrack.
4. When index reaches end of string,
   store the current partition.

---------------------------------------------------------
Time Complexity:
O(n × 2^n) (approximately)

Space Complexity:
O(n) (Recursion Stack)

=========================================================
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {

public:

    //-----------------------------------------------------
    // Check if substring is Palindrome
    //-----------------------------------------------------
    bool isPalindrome(string &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
                return false;

            start++;
            end--;
        }

        return true;
    }

    //-----------------------------------------------------
    // Recursive Backtracking Function
    //-----------------------------------------------------
    void solve(int index,
               string &s,
               vector<string> &path,
               vector<vector<string>> &result)
    {
        // Base Case
        if (index == s.size())
        {
            result.push_back(path);
            return;
        }

        // Try every substring
        for (int i = index; i < s.size(); i++)
        {
            // Check if current substring is palindrome
            if (isPalindrome(s, index, i))
            {
                // Choose
                path.push_back(s.substr(index, i - index + 1));

                // Recursive Call
                solve(i + 1, s, path, result);

                // Backtracking
                path.pop_back();
            }
        }
    }

    //-----------------------------------------------------
    // Main Function
    //-----------------------------------------------------
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> path;

        solve(0, s, path, result);

        return result;
    }
};


//=========================================================
// Driver Code
//=========================================================

int main()
{
    Solution obj;

    string s = "aab";

    vector<vector<string>> result = obj.partition(s);

    cout << "Palindrome Partitions\n\n";

    for (auto partition : result)
    {
        cout << "[ ";

        for (auto str : partition)
        {
            cout << "\"" << str << "\" ";
        }

        cout << "]" << endl;
    }

    return 0;
}