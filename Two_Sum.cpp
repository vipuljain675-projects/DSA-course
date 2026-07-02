#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// ============================================================================
// PROBLEM 1: Find Missing and Repeated Values
// ============================================================================
class MissingAndRepeatedSolution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;

        int n = grid.size();
        int a, b;

        // Find repeated value
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If it is ALREADY in the set, it's our repeated number (a)
                if (s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }

        // Find missing value
        // Since the grid is n x n, the numbers should be from 1 to n^2
        for (int i = 1; i <= n * n; i++) {
            // If we look for 'i' and it hits s.end(), it means 'i' is missing!
            if (s.find(i) == s.end()) {
                b = i;
                ans.push_back(b);
                break;
            }
        }

        return ans;
    }
};

// ============================================================================
// PROBLEM 2: Find Duplicate Number
// ============================================================================
class DuplicateSolution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for(int i = 0; i < nums.size(); i++) {
            // If found before the end, it's a duplicate
            if(s.find(nums[i]) != s.end()) {
                return nums[i];
            }
            s.insert(nums[i]);
        }

        return -1;
    }
};

// ============================================================================
// MAIN FUNCTION (To execute and test in VS Code)
// ============================================================================
int main() {
    cout << "--- Testing Problem 1: Missing and Repeated Values ---" << endl;
    MissingAndRepeatedSolution prob1;
    
    // A 2x2 grid containing numbers 1 to 4, where 2 is repeated and 4 is missing
    vector<vector<int>> grid = {
        {1, 2},
        {2, 3}
    };
    
    vector<int> result1 = prob1.findMissingAndRepeatedValues(grid);
    cout << "Repeated: " << result1[0] << ", Missing: " << result1[1] << endl;


    cout << "\n--- Testing Problem 2: Find Duplicate Number ---" << endl;
    DuplicateSolution prob2;
    
    vector<int> nums = {3, 1, 3, 4, 2};
    int result2 = prob2.findDuplicate(nums);
    cout << "Duplicate value found: " << result2 << endl;

    return 0;
}