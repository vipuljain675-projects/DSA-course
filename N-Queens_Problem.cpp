/*
=========================================================
            N-Queens Problems (LeetCode 51 & 52)
=========================================================

LeetCode 51 - N Queens
----------------------
Return ALL possible valid chess boards.

LeetCode 52 - N Queens II
-------------------------
Return ONLY the number of valid solutions.

Approach:
---------
Backtracking

1. Place one queen in each row.
2. Try every column.
3. If position is safe:
      - Place Queen
      - Recurse for next row
      - Backtrack
4. Continue until all rows are processed.

=========================================================
Time Complexity (Basic Version)
---------------------------------------------------------
O(n × n!)

Space Complexity
---------------------------------------------------------
Board  : O(n²)
Stack  : O(n)

=========================================================
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {

public:

    //----------------------------------------------------
    // Check whether a queen can be placed safely
    //----------------------------------------------------
    bool isSafe(vector<string>& board, int row, int col, int n) {

        // Check Vertical Up
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check Left Upper Diagonal
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0;
             i--, j--) {

            if (board[i][j] == 'Q')
                return false;
        }

        // Check Right Upper Diagonal
        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n;
             i--, j++) {

            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    //----------------------------------------------------
    // LeetCode 51 Helper Function
    //----------------------------------------------------
    void solveBoard(vector<string>& board,
                    int row,
                    int n,
                    vector<vector<string>>& ans) {

        // Base Case
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try every column
        for (int col = 0; col < n; col++) {

            if (isSafe(board, row, col, n)) {

                // Choose
                board[row][col] = 'Q';

                // Recursive Call
                solveBoard(board, row + 1, n, ans);

                // Backtracking
                board[row][col] = '.';
            }
        }
    }

    //----------------------------------------------------
    // LeetCode 51
    //----------------------------------------------------
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        solveBoard(board, 0, n, ans);

        return ans;
    }

    //----------------------------------------------------
    // LeetCode 52 Helper Function
    //----------------------------------------------------
    void countBoards(vector<string>& board,
                     int row,
                     int n,
                     int &count) {

        // Base Case
        if (row == n) {
            count++;
            return;
        }

        // Try every column
        for (int col = 0; col < n; col++) {

            if (isSafe(board, row, col, n)) {

                // Choose
                board[row][col] = 'Q';

                // Recursive Call
                countBoards(board, row + 1, n, count);

                // Backtracking
                board[row][col] = '.';
            }
        }
    }

    //----------------------------------------------------
    // LeetCode 52
    //----------------------------------------------------
    int totalNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        int count = 0;

        countBoards(board, 0, n, count);

        return count;
    }
};


//--------------------------------------------------------
// Driver Code
//--------------------------------------------------------

int main() {

    Solution obj;

    int n = 4;

    cout << "==============================" << endl;
    cout << "LeetCode 51 - N Queens" << endl;
    cout << "==============================" << endl;

    vector<vector<string>> boards = obj.solveNQueens(n);

    int solutionNo = 1;

    for (auto board : boards) {

        cout << "\nSolution " << solutionNo++ << "\n\n";

        for (auto row : board) {
            cout << row << endl;
        }

        cout << endl;
    }

    cout << "==============================" << endl;
    cout << "LeetCode 52 - Total Solutions" << endl;
    cout << "==============================" << endl;

    cout << "\nTotal Solutions = "
         << obj.totalNQueens(n)
         << endl;

    return 0;
}