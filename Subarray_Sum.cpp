#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Brute Force
int subarraySumBrute(vector<int>& nums, int k) {

    int count = 0;
    int n = nums.size();

    for(int i = 0; i < n; i++) {

        int sum = 0;

        for(int j = i; j < n; j++) {

            sum += nums[j];

            if(sum == k)
                count++;
        }
    }

    return count;
}

// Optimal
int subarraySumOptimal(vector<int>& nums, int k) {

    unordered_map<int,int> mp;

    mp[0] = 1;

    int prefixSum = 0;
    int count = 0;

    for(int num : nums) {

        prefixSum += num;

        if(mp.find(prefixSum - k) != mp.end()) {
            count += mp[prefixSum - k];
        }

        mp[prefixSum]++;
    }

    return count;
}

int main() {

    vector<int> nums = {9, 4, 20, 3, 10, 5};
    int k = 33;

    cout << "Brute Force Answer = "
         << subarraySumBrute(nums, k) << endl;

    cout << "Optimal Answer = "
         << subarraySumOptimal(nums, k) << endl;

    return 0;
}