#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool isValid(vector<vector<int>>& grid,
                 int r,
                 int c,
                 int n,
                 int expVal)
    {
        // Out of bounds
        if (r < 0 || r >= n || c < 0 || c >= n)
            return false;

        // Expected value not found
        if (grid[r][c] != expVal)
            return false;

        // Entire tour checked
        if (expVal == n * n - 1)
            return true;

        // Check all 8 knight moves

        bool ans1 = isValid(grid, r - 2, c + 1, n, expVal + 1);
        bool ans2 = isValid(grid, r - 1, c + 2, n, expVal + 1);
        bool ans3 = isValid(grid, r + 1, c + 2, n, expVal + 1);
        bool ans4 = isValid(grid, r + 2, c + 1, n, expVal + 1);
        bool ans5 = isValid(grid, r + 2, c - 1, n, expVal + 1);
        bool ans6 = isValid(grid, r + 1, c - 2, n, expVal + 1);
        bool ans7 = isValid(grid, r - 1, c - 2, n, expVal + 1);
        bool ans8 = isValid(grid, r - 2, c - 1, n, expVal + 1);

        return ans1 || ans2 || ans3 || ans4 ||
               ans5 || ans6 || ans7 || ans8;
    }

    bool checkValidGrid(vector<vector<int>>& grid)
    {
        int n = grid.size();

        if (grid[0][0] != 0)
            return false;

        return isValid(grid, 0, 0, n, 0);
    }
};

int main()
{
    vector<vector<int>> grid = {
        {0,11,16,5,20},
        {17,4,19,10,15},
        {12,1,8,21,6},
        {3,18,23,14,9},
        {24,13,2,7,22}
    };

    Solution obj;

    if (obj.checkValidGrid(grid))
        cout << "Valid Knight Tour";
    else
        cout << "Invalid Knight Tour";

    return 0;
}