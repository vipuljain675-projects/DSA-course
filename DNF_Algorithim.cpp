#include <iostream>
#include <vector>

using namespace std;

// =========================================================================
// APPROACH 1: THE COUNTING METHOD (2-Pass Approach)
// Time Complexity: O(n) | Space Complexity: O(1)
// Strategy: Counts frequencies of 0, 1, 2 and overwrites the array.
// =========================================================================
void sortColorsCounting(vector<int>& nums) {
    int n = nums.size();
    int count0 = 0, count1 = 0, count2 = 0;

    // First Pass: Read the array to collect counts
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) count0++;
        else if (nums[i] == 1) count1++;
        else count2++;
    }

    // Second Pass: Overwrite the original array sequentially
    int idx = 0;
    
    for (int i = 0; i < count0; i++) {
        nums[idx] = 0;
        idx++;
    }
    for (int i = 0; i < count1; i++) {
        nums[idx] = 1;
        idx++;
    }
    for (int i = 0; i < count2; i++) {
        nums[idx] = 2;
        idx++;
    }
}

// =========================================================================
// APPROACH 2: DUTCH NATIONAL FLAG ALGORITHM (1-Pass Approach)
// Time Complexity: O(n) | Space Complexity: O(1)
// Strategy: Uses 3 pointers to bucket 0s to the front and 2s to the back.
// =========================================================================
void sortColorsDNF(vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } 
        else if (nums[mid] == 1) {
            mid++;
        } 
        else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

// =========================================================================
// HELPER PRINTER FUNCTION
// =========================================================================
void printArray(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

// =========================================================================
// VS CODE RUNTIME TEST ENVIRONMENT
// =========================================================================
int main() {
    // Resetting unique datasets for both test passes
    vector<int> dataset1 = {2, 0, 2, 1, 1, 0};
    vector<int> dataset2 = {2, 0, 2, 1, 1, 0};

    cout << "=========================================================" << endl;
    cout << "           LECTURE 25: SORT COLORS (0s, 1s, & 2s)        " << endl;
    cout << "=========================================================" << endl;
    cout << "Original Dataset : ";
    printArray(dataset1);
    cout << "---------------------------------------------------------" << endl;

    // Run Approach 1
    sortColorsCounting(dataset1);
    cout << "-> Approach 1 (Counting 2-Pass) : ";
    printArray(dataset1);

    // Run Approach 2
    sortColorsDNF(dataset2);
    cout << "-> Approach 2 (DNF Pointer 1-Pass): ";
    printArray(dataset2);
    cout << "=========================================================" << endl;

    return 0;
}