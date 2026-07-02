#include <iostream>
#include <vector>
#include <climits> // Gives access to INT_MIN
using namespace std;

// ============================================================================
// CHAPTER 1: PRINT ALL SUBARRAYS (Taught at 1:02)
// ============================================================================
void printAllSubarrays(const vector<int> nums) {
    cout << "--- 1. All Possible Subarrays ---" << endl;
    int n = nums.size();
    
    // Outer loop picks the starting index
    for (int i = 0; i < n; i++) {
        // Inner loop picks the ending index
        for (int j = i; j < n; j++) {
            cout << "[ ";
            // Third loop prints elements from start to end
            for (int k = i; k <= j; k++) {
                cout << nums[k] << " ";
            }
            cout << "] ";
        }
        cout << endl;
    }
    cout << endl;
}

// ============================================================================
// CHAPTER 2: MAXIMUM SUBARRAY SUM - BRUTE FORCE (Taught at 6:18)
// Time Complexity: O(N^2)
// ============================================================================
int maxSubarraySumBruteForce(const vector<int>& nums) {
    int maxSubSum = INT_MIN;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int currentRunningSum = 0;
        for (int j = i; j < n; j++) {
            currentRunningSum += nums[j];
            maxSubSum = max(maxSubSum, currentRunningSum);
        }
    }

     return maxSubSum;
}

// ============================================================================
// CHAPTER 3: KADANE'S ALGORITHM (Taught at 12:40)
// Time Complexity: O(N) | Space Complexity: O(1)
// ============================================================================
int maxSubarraySumKadane(const vector<int>& nums) {
    int maxSum = INT_MIN;
    int currentSum = 0;

    // Single loop walkthrough -> O(N) linear time
    for (int val : nums) {
        currentSum += val;
        
        // Update the maximum found so far
        maxSum = max(currentSum, maxSum);
        
        // The Golden Rule: If the sum goes negative, drop the baggage and reset!
        if (currentSum < 0) {
            currentSum = 0;
        }
    }
    return maxSum;
}

// ============================================================================
// SYSTEM MAIN FUNCTION ENGINE
// ============================================================================
int main() {
    cout << "=========================================================" << endl;
    cout << "     LECTURE 10 MASTER ARCHIVE: KADANE'S ALGORITHM       " << endl;
    cout << "=========================================================" << endl;

    // Sample dataset containing mix of positive and negative numbers
    vector<int> numbers = {1,2,3};

    // 1. Display all continuous subarrays
    printAllSubarrays(numbers);
    cout << "---------------------------------------------------------" << endl;

    // 2. Compute Max Subarray Sum via Brute Force O(N^2)
    int bruteResult = maxSubarraySumBruteForce(numbers);
    cout << "--- 2. Brute Force Method ---" << endl;
    cout << "Maximum Subarray Sum calculated: " << bruteResult << "\n\n";
    cout << "---------------------------------------------------------" << endl;

    // 3. Compute Max Subarray Sum via Kadane's Algorithm O(N)
    int kadaneResult = maxSubarraySumKadane(numbers);
    cout << "--- 3. Kadane's Algorithm Method ---" << endl;
    cout << "Maximum Subarray Sum calculated: " << kadaneResult << "\n";
    cout << "=========================================================" << endl;

    return 0;
}
