#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;

        int tank = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++) {

            totalGas += gas[i];
            totalCost += cost[i];

            tank += gas[i] - cost[i];

            // Cannot reach the next station
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        // Not enough gas overall
        if (totalGas < totalCost) {
            return -1;
        }

        return start;
    }
};

int main() {
    Solution sol;

    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    cout << sol.canCompleteCircuit(gas, cost) << endl;

    return 0;
}