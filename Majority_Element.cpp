#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort

using namespace std;

// =========================================================================
// SECTION A: TARGET PAIR SUM PROBLEMS
// =========================================================================

// APPROACH 1: TARGET PAIR SUM (Brute Force - O(n^2))
vector<int> FindTargetPairBruteForce(const vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {}; 
}

// APPROACH 2: TARGET PAIR SUM (Optimal Two-Pointer - O(n log n))
vector<int> FindTargetPairOptimal(const vector<int>& nums, int target) {
    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());

    int left = 0;
    int right = sortedNums.size() - 1;

    while (left < right) {
        int currentSum = sortedNums[left] + sortedNums[right];
        if (currentSum == target) {
            return {sortedNums[left], sortedNums[right]};
        }
        else if (currentSum < target) {
            left++;  
        } 
        else {
            right--; 
        }
    }
    return {}; 
}

// =========================================================================
// SECTION B: MAJORITY ELEMENT PROBLEMS
// =========================================================================

// APPROACH 1: BRUTE FORCE (O(n^2) Time | O(1) Space)
int majorityElementBruteForce(const vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[i] == nums[j]) {
                count++;
            }
        }
        if (count > n / 2) {
            return nums[i];
        }
    }
    return -1; 
}

// APPROACH 2: BETTER APPROACH - SORTING (O(n log n) Time)
int majorityElementSortingConsecutive(vector<int> nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    sort(nums.begin(), nums.end()); 
    int freq = 1;
    int ans = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1]) {
            freq++;
        } else {
            freq = 1;
            ans = nums[i];
        }
        if (freq > n / 2) return ans;
    }
    return -1;
}

// APPROACH 2B: SORTING TRICK - MIDDLE ELEMENT (O(n log n) Time)

int majorityElementSortingTrick(vector<int> nums) {

    int n = nums.size()/2;

    sort(nums.begin(), nums.end());
    return nums[n]; 
}

// UPDATED: APPROACH 3 - MOORE'S VOTING ALGORITHM (O(n) Time | O(1) Space)
// Using Shradha Ma'am's exact index loop layout style from her LeetCode screen
int majorityElementMooresVoting(const vector<int>& nums) {
    int freq = 0; // 'count' variable named 'freq' on her screen
    int ans = 0;  // 'candidate' variable named 'ans' on her screen

    // Standard loop setup running from index 0 to size-1
    for (int i = 0; i < nums.size(); i++) {
        // 1. If our frequency pool drops to 0, current candidate is eliminated
        if (freq == 0) {
            ans = nums[i]; // Reset current element as the dominant candidate leader
        }
        
        // 2. Voting Check
        if (ans == nums[i]) {
            freq++; // Matching number strengthens our candidate's position
        } else {
            freq--; // Opposing number cancels out one vote
        }
    }

    return ans; // The survivor is guaranteed to be the majority element
}

// =========================================================================
// MAIN EXECUTION ENGINE
// =========================================================================
int main() {
    cout << "=========================================================" << endl;
    cout << "       LECTURE 11 MASTER FILE: STANDARD LOOP STYLE        " << endl;
    cout << "=========================================================" << endl;

    vector<int> numbers = {1, 5, 3, 4, 2};
    int target = 7;

    cout << "[SECTION A] Target Pair Sum Results:" << endl;
    vector<int> bfResult = FindTargetPairBruteForce(numbers, target);
    cout << "-> Brute Force Indices: [" << bfResult[0] << ", " << bfResult[1] << "]" << endl;
    
    vector<int> optResult = FindTargetPairOptimal(numbers, target);
    cout << "-> Optimal Values     : " << optResult[0] << " + " << optResult[1] << " = " << target << endl;
    cout << "---------------------------------------------------------" << endl;

    // Test data matching her screen: [3, 2, 3] -> 3 wins election
    vector<int> majoritySample = {3, 2, 3}; 
    
    cout << "[SECTION B] Majority Element Results for {3, 2, 3}:" << endl;
    
    int m1 = majorityElementBruteForce(majoritySample);
    cout << "-> M1: Brute Force Result             : " << m1 << endl;

    int m2B = majorityElementSortingTrick(majoritySample);
    cout << "-> M2B: Sorting Middle Trick Result    : " << m2B << endl;

    int m3 = majorityElementMooresVoting(majoritySample);
    cout << "-> M3: Moore's Voting (Ma'am's Loop) : " << m3 << endl;

    cout << "=========================================================" << endl;
    return 0;
}

