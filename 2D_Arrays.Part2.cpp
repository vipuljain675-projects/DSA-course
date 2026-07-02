#include <iostream>
#include <vector>
using namespace std;

/*
=========================================================
LEETCODE 74 - SEARCH A 2D MATRIX
=========================================================

Matrix Property:
1. Each row is sorted.
2. First element of a row is greater than
   the last element of the previous row.

Example:

1   3   5   7
10 11 16 20
23 30 34 60

Target = 16

Approach:
1. Binary Search on rows.
2. Find the row that may contain target.
3. Binary Search inside that row.

Time Complexity:
O(log m + log n)

Space Complexity:
O(1)
=========================================================
*/

class Solution74 {
public:

    bool searchInRow(vector<vector<int>>& mat,
                     int target,
                     int row) {

        int n = mat[0].size();

        int st = 0;
        int end = n - 1;

        while (st <= end) {

            int mid = st + (end - st) / 2;

            if (mat[row][mid] == target) {
                return true;
            }
            else if (target > mat[row][mid]) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& mat,
                      int target) {

        int m = mat.size();
        int n = mat[0].size();

        int startRow = 0;
        int endRow = m - 1;

        while (startRow <= endRow) {

            int midRow =
                startRow + (endRow - startRow) / 2;

            // Target lies within this row
            if (target >= mat[midRow][0] &&
                target <= mat[midRow][n - 1]) {

                return searchInRow(
                    mat,
                    target,
                    midRow
                );
            }

            // Search lower rows
            else if (target > mat[midRow][n - 1]) {

                startRow = midRow + 1;
            }

            // Search upper rows
            else {

                endRow = midRow - 1;
            }
        }

        return false;
    }
};

/*
=========================================================
LEETCODE 240 - SEARCH A 2D MATRIX II
=========================================================

Matrix Property:

1  4  7 11 15
2  5  8 12 19
3  6  9 16 22
10 13 14 17 24
18 21 23 26 30

Rows sorted
Columns sorted

Observation:

Start from TOP RIGHT.

At every cell:

← Smaller values
↓ Larger values

If current > target:
Move LEFT

If current < target:
Move DOWN

Time Complexity:
O(m + n)

Space Complexity:
O(1)
=========================================================
*/

class Solution240 {
public:

    bool searchMatrix(vector<vector<int>>& matrix,
                      int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = n - 1;

        while (row < m && col >= 0) {

            if (matrix[row][col] == target) {

                return true;
            }

            else if (matrix[row][col] > target) {

                col--;
            }

            else {

                row++;
            }
        }

        return false;
    }
};

/*
=========================================================
MAIN FUNCTION (FOR VS CODE TESTING)
=========================================================
*/

int main() {

    // ---------- LeetCode 74 ----------

    vector<vector<int>> matrix74 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target74 = 16;

    Solution74 obj74;

    cout << "LeetCode 74 Answer: ";

    if (obj74.searchMatrix(matrix74, target74))
        cout << "True\n";
    else
        cout << "False\n";


    // ---------- LeetCode 240 ----------

    vector<vector<int>> matrix240 = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target240 = 16;

    Solution240 obj240;

    cout << "LeetCode 240 Answer: ";

    if (obj240.searchMatrix(matrix240, target240))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}