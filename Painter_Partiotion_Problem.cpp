#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& boards, int n, int painters, int maxTime) {

    int painterCount = 1;
    int boardSum = 0;

    for (int i = 0; i < n; i++) {

        // If a single board is larger than maxTime
        if (boards[i] > maxTime) {
            return false;
        }

        if (boardSum + boards[i] <= maxTime) {

            boardSum += boards[i];
        }
        else {

            painterCount++;

            if (painterCount > painters) {
                return false;
            }

            boardSum = boards[i];
        }
    }

    return true;
}

int painterPartition(vector<int>& boards, int n, int painters) {

    int start = 0;
    int end = 0;

    for (int i = 0; i < n; i++) {
        end += boards[i];
    }

    int ans = -1;

    while (start <= end) {

        int mid = start + (end - start) / 2;

        if (isPossible(boards, n, painters, mid)) {

            ans = mid;
            end = mid - 1;
        }
        else {

            start = mid + 1;
        }
    }

    return ans;
}

int main() {

    vector<int> boards = {10, 20, 30, 40};

    int n = boards.size();
    int painters = 2;

    int result = painterPartition(boards, n, painters);

    cout << "Minimum Time Required = " << result << endl;

    return 0;
}

