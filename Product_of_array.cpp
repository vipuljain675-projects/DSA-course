#include <iostream>
#include <vector>

using namespace std;

// =========================================================================
// APPROACH 1: BRUTE FORCE (O(n^2) Time | O(1) Space)
// Checks every single pairing element combinations via nested loops.
// Will trigger TLE (Time Limit Exceeded) on large arrays.
// =========================================================================
vector<int> productExceptSelfBruteForce(const vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        int product = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                product *= nums[j]; // Multiply everything except current position
            }
        }
        ans[i] = product;
    }
    return ans;
}

// =========================================================================
// APPROACH 2: OPTIMAL THREE-ARRAY MATRIX (O(n) Time | O(n) Space)
// Explicitly builds out dedicated Prefix and Suffix storage vectors.
// Highly logical and perfect for initial interview explanations!
// =========================================================================
vector<int> productExceptSelfOptimalArrays(const vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);
    vector<int> ans(n);

    // 1. Fill Prefix Array (Left-to-Right computation)
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    // 2. Fill Suffix Array (Right-to-Left backward computation)
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    // 3. Merge products into final answer positions
    for (int i = 0; i < n; i++) {
        ans[i] = prefix[i] * suffix[i];
    }

    return ans;
}

// =========================================================================
// APPROACH 3: THE MEMORY-OPTIMIZED CHAMPION (O(n) Time | O(1) Space)
// Reuses the output array directly as a canvas. Computes prefix and suffix
// multiplication products on the fly using single variables.
// =========================================================================
vector<int> productExceptSelfSpaceChampion(const vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1); // Allocation doesn't count as extra space per LeetCode rules

    // Pass 1: Handle running Prefix multipliers moving Left-to-Right
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        ans[i] = prefix;   // Write current prefix directly into position
        prefix *= nums[i]; // Accumulate product for the next element slot
    }

    // Pass 2: Multiply by running Suffix values moving Right-to-Left
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] *= suffix;  // Multiply existing prefix data by our live suffix
        suffix *= nums[i]; // Accumulate backward product for the next element slot
    }

    return ans;
}

// =========================================================================
// HELPER PRINTER ENGINE
// =========================================================================
void printVector(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

// =========================================================================
// SYSTEM EXECUTION ENGINE
// =========================================================================
int main() {
    vector<int> nums = {1, 2, 3, 4};

    cout << "=========================================================" << endl;
    cout << "      LECTURE 13: PRODUCT OF ARRAY EXCEPT SELF MATRIX    " << endl;
    cout << "=========================================================" << endl;
    cout << "Input Array     : { 1, 2, 3, 4 }\n\n";

    // --- Test Method 1 ---
    cout << "-> Approach 1: Brute Force O(n^2)  : ";
    vector<int> ans1 = productExceptSelfBruteForce(nums);
    printVector(ans1);

    // --- Test Method 2 ---
    cout << "-> Approach 2: Three-Arrays O(n)  : ";
    vector<int> ans2 = productExceptSelfOptimalArrays(nums);
    printVector(ans2);

    // --- Test Method 3 ---
    cout << "-> Approach 3: Space Champion O(1): ";
    vector<int> ans3 = productExceptSelfSpaceChampion(nums);
    printVector(ans3);

    cout << "=========================================================" << endl;
    return 0;
}