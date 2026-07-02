#include <iostream>
#include <vector>
#include <algorithm> // Required for reverse()

using namespace std;

class Solution {
public:
    // =========================================================================
    // PROBLEM 1: MERGE SORTED ARRAY (LeetCode #88)
    // Time Complexity: O(m + n) | Space Complexity: O(1)
    // Strategy: Three-pointer backward traversal utilizing trailing zero padding.
    // =========================================================================
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;         // Pointer for last valid element in nums1
        int j = n - 1;         // Pointer for last element in nums2
        int idx = m + n - 1;   // Pointer for the absolute back door slot of nums1

        // Compare elements starting from the back and move the larger value
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[idx] = nums1[i];
                i--;
            } else {
                nums1[idx] = nums2[j];
                j--;
            }
            idx--; // Shift the target slot forward
        }

        // Cleanup Edge Case: If nums1 runs out of elements early, 
        // copy the remaining items from nums2 directly.
        while (j >= 0) {
            nums1[idx] = nums2[j];
            j--;
            idx--;
        }
    }

    // =========================================================================
    // PROBLEM 2: NEXT PERMUTATION (LeetCode #31)
    // Time Complexity: O(n) | Space Complexity: O(1)
    // Strategy: Find dip pivot, swap with next highest value, reverse suffix.
    // =========================================================================
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        // Step 1: Scan backward to find the pivot element break point
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // If a valid pivot is found (array is not completely descending)
        if (pivot != -1) {
            // Step 2: Find the element from the right just larger than nums[pivot]
            for (int i = n - 1; i > pivot; i--) {
                if (nums[i] > nums[pivot]) {
                    swap(nums[pivot], nums[i]);
                    break;
                }
            }
        }

        // Step 3: Reverse the suffix to get the smallest next structural sequence
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};

// =========================================================================
// HELPER PRINTER FUNCTION
// =========================================================================
void printVector(const vector<int>& vec) {
    cout << "[ ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << "]" << endl;
}

// =========================================================================
// LOCAL VS CODE TESTING SUITE
// =========================================================================
int main() {
    Solution solver;

    cout << "=========================================================" << endl;
    cout << "          DSA MASTER ENGINE: LECTURE 26 DATASET          " << endl;
    cout << "=========================================================" << endl;

    // -------------------------------------------------------------------------
    // EXECUTION BLOCK 1: MERGE SORTED ARRAY
    // -------------------------------------------------------------------------
    vector<int> mergeNums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> mergeNums2 = {2, 5, 6};
    int n = 3;

    cout << "[TEST 1] Merge Sorted Array Target Initialized:" << endl;
    cout << "  nums1: "; printVector(mergeNums1);
    cout << "  nums2: "; printVector(mergeNums2);
    
    solver.merge(mergeNums1, m, mergeNums2, n);
    
    cout << "-> Merge Output Result            : "; 
    printVector(mergeNums1);
    cout << "---------------------------------------------------------" << endl;

    // -------------------------------------------------------------------------
    // EXECUTION BLOCK 2: NEXT PERMUTATION
    // -------------------------------------------------------------------------
    vector<int> permNums = {1, 2, 3};

    cout << "[TEST 2] Next Permutation Target Initialized:" << endl;
    cout << "  Sequence: "; printVector(permNums);
    
    solver.nextPermutation(permNums);
    
    cout << "-> Next Lexicographical Mutation  : "; 
    printVector(permNums);
    cout << "=========================================================" << endl;

    return 0;
}
