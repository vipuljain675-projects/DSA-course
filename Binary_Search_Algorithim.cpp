#include <iostream>
#include <vector>

using namespace std;

// =========================================================================
// METHOD 1: THE SIMPLE TEXTBOOK APPROACH (Iterative)
// Uses the standard midpoint calculation. Simple to read, but vulnerable
// to integer overflow bugs when dealing with massive datasets.
// =========================================================================
int binarySearchSimple(const vector<int>& arr, int tar) {
    int st = 0;
    int end = arr.size() - 1;

    while (st <= end) {
        int mid = (st + end) / 2; // Vulnerable to overflow

        if (tar > arr[mid]) {
            st = mid + 1;
        } else if (tar < arr[mid]) {
            end = mid - 1;
        } else {
            return mid; // Element found!
        }
    }
    return -1;
}

// =========================================================================
// METHOD 2: THE OPTIMIZED APPROACH (Iterative)
// Uses subtraction to calculate the offset distance first. This prevents 
// 'st + end' from exceeding the upper capacity limit of an integer.
// =========================================================================
int binarySearchOptimized(const vector<int>& arr, int tar) {
    int st = 0;
    int end = arr.size() - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2; // Overflow-safe

        if (tar > arr[mid]) {
            st = mid + 1;
        } else if (tar < arr[mid]) {
            end = mid - 1;
        } else {
            return mid; // Element found!
        }
    }
    return -1;
}

// =========================================================================
// METHOD 3: THE OPTIMIZED RECURSIVE APPROACH
// Achieves the exact same overflow-safe result by passing modified 
// boundaries down into a new recursive stack frame.
// =========================================================================
int binarySearchRecursive(const vector<int>& arr, int tar, int st, int end) {
    // Base Case: If search space shrinks to nothing, target is missing
    if (st > end) {
        return -1;
    }

    int mid = st + (end - st) / 2; // Overflow-safe

    if (arr[mid] == tar) {
        return mid; // Element found!
    } 
    else if (tar > arr[mid]) {
        // Search right half by moving 'st' past mid
        return binarySearchRecursive(arr, tar, mid + 1, end);
    } 
    else {
        // Search left half by moving 'end' behind mid
        return binarySearchRecursive(arr, tar, st, mid - 1);
    }
}

// =========================================================================
// MAIN RUNTIME TESTING ENVIRONMENT
// =========================================================================
int main() {
    // Test Case 1: Odd length array (Matches arr1 on Shradha Ma'am's screen)
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; 
    int tar1 = 12;

    // Test Case 2: Even length array (Matches arr2 on Shradha Ma'am's screen)
    vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; 
    int tar2 = 0;

    cout << "=========================================================" << endl;
    cout << "          LECTURE 17: COMPLETE BINARY SEARCH MATRIX      " << endl;
    cout << "=========================================================" << endl;

    // --- Running Simple Iterative ---
    cout << "[1. SIMPLE ITERATIVE METHOD RUN]" << endl;
    cout << "Searching for " << tar1 << " in arr1: Index -> " << binarySearchSimple(arr1, tar1) << endl;
    cout << "Searching for " << tar2 << " in arr2: Index -> " << binarySearchSimple(arr2, tar2) << "\n\n";

    // --- Running Optimized Iterative ---
    cout << "[2. OPTIMIZED ITERATIVE METHOD RUN]" << endl;
    cout << "Searching for " << tar1 << " in arr1: Index -> " << binarySearchOptimized(arr1, tar1) << endl;
    cout << "Searching for " << tar2 << " in arr2: Index -> " << binarySearchOptimized(arr2, tar2) << "\n\n";

    // --- Running Optimized Recursive ---
    cout << "[3. OPTIMIZED RECURSIVE METHOD RUN]" << endl;
    cout << "Searching for " << tar1 << " in arr1: Index -> " << binarySearchRecursive(arr1, tar1, 0, arr1.size() - 1) << endl;
    cout << "Searching for " << tar2 << " in arr2: Index -> " << binarySearchRecursive(arr2, tar2, 0, arr2.size() - 1) << endl;
    cout << "=========================================================" << endl;

    return 0;
}