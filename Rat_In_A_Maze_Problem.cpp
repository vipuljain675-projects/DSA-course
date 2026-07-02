/*
=========================================================
            Rat in a Maze Problem (GFG)
=========================================================

Problem:
A rat starts from the top-left corner (0,0)
and wants to reach the bottom-right corner (n-1,n-1).

1 = Open Cell
0 = Blocked Cell

The rat can move in:
D = Down
L = Left
R = Right
U = Up

Print all possible paths.

---------------------------------------------------------
Approach : Backtracking

1. Start from (0,0).
2. Try all 4 directions.
3. If the move is safe:
      - Mark current cell as visited.
      - Move to next cell.
      - Backtrack.
4. Store the path whenever destination is reached.

---------------------------------------------------------
Time Complexity:
Worst Case : O(4^(N*N))

Space Complexity:
Visited Matrix : O(N²)
Recursion Stack : O(N²)

=========================================================
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {

public:

    //-----------------------------------------------------
    // Check whether next move is safe
    //-----------------------------------------------------
    bool isSafe(int x,
                int y,
                vector<vector<int>>& maze,
                vector<vector<int>>& visited,
                int n)
    {
        if (x >= 0 &&
            x < n &&
            y >= 0 &&
            y < n &&
            maze[x][y] == 1 &&
            visited[x][y] == 0)
        {
            return true;
        }

        return false;
    }

    //-----------------------------------------------------
    // Recursive Backtracking Function
    //-----------------------------------------------------
    void solve(int x,
               int y,
               vector<vector<int>>& maze,
               int n,
               string path,
               vector<string>& ans,
               vector<vector<int>>& visited)
    {

        // Destination Reached
        if (x == n - 1 && y == n - 1) {

            ans.push_back(path);
            return;
        }

        // Mark Current Cell as Visited
        visited[x][y] = 1;

        //---------------------------
        // Down
        //---------------------------
        if (isSafe(x + 1, y, maze, visited, n)) {

            solve(x + 1,
                  y,
                  maze,
                  n,
                  path + 'D',
                  ans,
                  visited);
        }

        //---------------------------
        // Left
        //---------------------------
        if (isSafe(x, y - 1, maze, visited, n)) {

            solve(x,
                  y - 1,
                  maze,
                  n,
                  path + 'L',
                  ans,
                  visited);
        }

        //---------------------------
        // Right
        //---------------------------
        if (isSafe(x, y + 1, maze, visited, n)) {

            solve(x,
                  y + 1,
                  maze,
                  n,
                  path + 'R',
                  ans,
                  visited);
        }

        //---------------------------
        // Up
        //---------------------------
        if (isSafe(x - 1, y, maze, visited, n)) {

            solve(x - 1,
                  y,
                  maze,
                  n,
                  path + 'U',
                  ans,
                  visited);
        }

        //---------------------------
        // Backtracking
        //---------------------------
        visited[x][y] = 0;
    }

    //-----------------------------------------------------
    // Main Function
    //-----------------------------------------------------
    vector<string> findPath(vector<vector<int>>& maze, int n)
    {

        vector<string> ans;

        // If starting cell is blocked
        if (maze[0][0] == 0)
            return ans;

        vector<vector<int>> visited(
            n,
            vector<int>(n, 0));

        solve(0,
              0,
              maze,
              n,
              "",
              ans,
              visited);

        return ans;
    }
};


//=========================================================
// Driver Code
//=========================================================

int main() {

    vector<vector<int>> maze = {

        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}

    };

    int n = maze.size();

    Solution obj;

    vector<string> paths = obj.findPath(maze, n);

    cout << "Possible Paths\n\n";

    for (string path : paths) {

        cout << path << endl;
    }

    return 0;
}