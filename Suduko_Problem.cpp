/*
=========================================================
            LeetCode 37 - Sudoku Solver
=========================================================

Problem:
Given a partially filled Sudoku board, fill the empty
cells ('.') so that every row, column and 3x3 box
contains digits from 1 to 9 exactly once.

---------------------------------------------------------
Approach : Backtracking

1. Find an empty cell.
2. Try placing digits from 1 to 9.
3. If a digit is safe:
      - Place the digit.
      - Solve the remaining board.
      - If it fails, remove the digit (Backtrack).
4. Continue until the board is completely filled.

---------------------------------------------------------
Time Complexity:
Worst Case : O(9^(Empty Cells))

Space Complexity:
O(Empty Cells)  (Recursion Stack)

=========================================================
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:

    //-----------------------------------------------------
    // Check whether placing a number is safe or not
    //-----------------------------------------------------
    bool isSafe(vector<vector<char>>& board,
                int row,
                int col,
                char num)
    {

        // Check Row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == num)
                return false;
        }

        // Check Column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num)
                return false;
        }

        // Check 3x3 Box

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {

            for (int j = startCol; j < startCol + 3; j++) {

                if (board[i][j] == num)
                    return false;
            }
        }

        return true;
    }

    //-----------------------------------------------------
    // Recursive Backtracking Function
    //-----------------------------------------------------
    bool solve(vector<vector<char>>& board)
    {

        // Traverse the complete board
        for (int row = 0; row < 9; row++) {

            for (int col = 0; col < 9; col++) {

                // Found an Empty Cell
                if (board[row][col] == '.') {

                    // Try every digit from 1 to 9
                    for (char num = '1'; num <= '9'; num++) {

                        if (isSafe(board, row, col, num)) {

                            // Choose
                            board[row][col] = num;

                            // Recursive Call
                            if (solve(board))
                                return true;

                            // Backtracking
                            board[row][col] = '.';
                        }
                    }

                    // No digit worked
                    return false;
                }
            }
        }

        // Entire board solved
        return true;
    }

    //-----------------------------------------------------
    // Main Function
    //-----------------------------------------------------
    void solveSudoku(vector<vector<char>>& board) {

        solve(board);
    }
};



//=========================================================
// Driver Code
//=========================================================

int main() {

    vector<vector<char>> board = {

        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},

        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},

        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}

    };

    Solution obj;

    obj.solveSudoku(board);

    cout << "Solved Sudoku Board\n\n";

    for (int i = 0; i < 9; i++) {

        for (int j = 0; j < 9; j++) {

            cout << board[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}