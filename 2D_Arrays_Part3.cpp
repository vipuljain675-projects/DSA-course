/*
=========================================================
LECTURE 3 : SPIRAL MATRIX
LeetCode 54 - Spiral Matrix
=========================================================

APPROACH:

Maintain 4 boundaries:

srow = starting row
erow = ending row

scol = starting column
ecol = ending column

Traverse in order:

1. Top
2. Right
3. Bottom
4. Left

After one complete round:

srow++;
erow--;
scol++;
ecol--;

CORNER CASES:

1. If only one row remains:
   srow == erow

   Avoid printing bottom row again.

2. If only one column remains:
   scol == ecol

   Avoid printing left column again.

TIME COMPLEXITY:
O(m * n)

SPACE COMPLEXITY:
O(1)
(excluding answer vector)
=========================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {

        vector<int> ans;

        int m = mat.size();
        int n = mat[0].size();

        int srow = 0;
        int erow = m - 1;

        int scol = 0;
        int ecol = n - 1;

        while (srow <= erow && scol <= ecol) {

            // TOP
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(mat[srow][j]);
            }

            // RIGHT
            for (int i = srow + 1; i <= erow; i++) {
                ans.push_back(mat[i][ecol]);
            }

            // BOTTOM
            for (int j = ecol - 1; j >= scol; j--) {

                if (srow == erow) {
                    break;
                }

                ans.push_back(mat[erow][j]);
            }

            // LEFT
            for (int i = erow - 1; i >= srow + 1; i--) {

                if (scol == ecol) {
                    break;
                }

                ans.push_back(mat[i][scol]);
            }

            srow++;
            erow--;

            scol++;
            ecol--;
        }

        return ans;
    }
};

int main() {

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution obj;
    vector<int> ans = obj.spiralOrder(matrix);

    cout << "Spiral Order: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}