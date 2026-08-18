#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <algorithm>

using namespace std;

// ============================================================
// LEETCODE 239 - SLIDING WINDOW MAXIMUM
// ============================================================

// ------------------------------------------------------------
// SOLUTION 1: BRUTE FORCE
// Time:  O(n * k)
// Space: O(1) extra (excluding answer)
// ------------------------------------------------------------
vector<int> bruteForce(vector<int>& nums, int k) {

    vector<int> ans;

    for (int i = 0; i <= nums.size() - k; i++) {

        int maxi = INT_MIN;

        // Check all k elements in the current window
        for (int j = i; j < i + k; j++) {
            maxi = max(maxi, nums[j]);
        }

        ans.push_back(maxi);
    }

    return ans;
}


// ------------------------------------------------------------
// SOLUTION 2: OPTIMIZED - DEQUE / MONOTONIC QUEUE
// Time:  O(n)
// Space: O(k)
// ------------------------------------------------------------
vector<int> optimizedDeque(vector<int>& nums, int k) {

    vector<int> ans;

    // Stores indices
    deque<int> dq;

    for (int i = 0; i < nums.size(); i++) {

        // ----------------------------------------------------
        // STEP 1:
        // Remove indices which are outside the current window
        // ----------------------------------------------------
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }


        // ----------------------------------------------------
        // STEP 2:
        // Remove smaller elements from the back
        //
        // If nums[i] is greater than nums[dq.back()],
        // then dq.back() can never be the maximum again.
        // ----------------------------------------------------
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }


        // ----------------------------------------------------
        // STEP 3:
        // Add current index
        // ----------------------------------------------------
        dq.push_back(i);


        // ----------------------------------------------------
        // STEP 4:
        // Once the first complete window is formed,
        // the front of deque contains the maximum.
        // ----------------------------------------------------
        if (i >= k - 1) {
            ans.push_back(nums[dq.front()]);
        }
    }

    return ans;
}


// ============================================================
// HELPER FUNCTION
// ============================================================

void printVector(vector<int>& arr) {

    cout << "[";

    for (int i = 0; i < arr.size(); i++) {

        cout << arr[i];

        if (i != arr.size() - 1) {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}


// ============================================================
// MAIN
// ============================================================

int main() {

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};

    int k = 3;


    // --------------------------------------------------------
    // BRUTE FORCE
    // --------------------------------------------------------

    vector<int> bruteAnswer = bruteForce(nums, k);

    cout << "Brute Force Answer: ";
    printVector(bruteAnswer);


    // --------------------------------------------------------
    // OPTIMIZED DEQUE
    // --------------------------------------------------------

    vector<int> optimizedAnswer = optimizedDeque(nums, k);

    cout << "Optimized Answer:    ";
    printVector(optimizedAnswer);


    // --------------------------------------------------------
    // COMPLEXITY
    // --------------------------------------------------------

    cout << endl;

    cout << "Brute Force: O(n * k)" << endl;
    cout << "Deque:       O(n)" << endl;


    return 0;
}