#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// ======================================================
// METHOD 1 : Brute Force + Set
// Time Complexity : O(n^3)
// Space Complexity: O(k)
// ======================================================

vector<vector<int>> threeSumBruteForce(vector<int>& nums) {

    int n = nums.size();

    vector<vector<int>> ans;
    set<vector<int>> s;

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            for (int k = j + 1; k < n; k++) {

                if (nums[i] + nums[j] + nums[k] == 0) {

                    vector<int> trip = {
                        nums[i],
                        nums[j],
                        nums[k]
                    };

                    sort(trip.begin(), trip.end());

                    if (s.find(trip) == s.end()) {
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }

    return ans;
}

// ======================================================
// METHOD 2 : Optimal (Sorting + Two Pointers)
// Time Complexity : O(n^2)
// Space Complexity: O(1)
// ======================================================

vector<vector<int>> threeSumOptimal(vector<int>& nums) {

    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {

        // Skip duplicate first elements
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = n - 1;

        while (left < right) {

            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {

                ans.push_back({
                    nums[i],
                    nums[left],
                    nums[right]
                });

                left++;
                right--;

                // Skip duplicate left values
                while (left < right &&
                       nums[left] == nums[left - 1]) {
                    left++;
                }

                // Skip duplicate right values
                while (left < right &&
                       nums[right] == nums[right + 1]) {
                    right--;
                }
            }

            else if (sum < 0) {
                left++;
            }

            else {
                right--;
            }
        }
    }

    return ans;
}

// ======================================================
// Print Function
// ======================================================

void printTriplets(vector<vector<int>>& ans) {

    for (auto triplet : ans) {

        cout << "[ ";

        for (int num : triplet) {
            cout << num << " ";
        }

        cout << "]" << endl;
    }
}

// ======================================================
// Main Function
// ======================================================

int main() {

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    cout << "Brute Force Answer:" << endl;

    vector<vector<int>> ans1 =
        threeSumBruteForce(nums);

    printTriplets(ans1);

    cout << endl;

    cout << "Optimal Answer:" << endl;

    // IMPORTANT: nums2 is vector<int>, NOT vector<vector<int>>
    vector<int> nums2 = nums;

    vector<vector<int>> ans2 =
        threeSumOptimal(nums2);

    printTriplets(ans2);

    return 0;
}