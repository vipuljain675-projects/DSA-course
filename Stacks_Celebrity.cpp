#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Celebrity Problem using Stack
//
// A celebrity is a person who:
// 1. Does not know anyone else.
// 2. Is known by everyone else.
//
// arr[i][j] = 1  -> person i knows person j
// arr[i][j] = 0  -> person i does not know person j

int getCelebrity(vector<vector<int>>& arr, int n) {

    // Step 1: Put every person into the stack
    stack<int> s;

    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    // Step 2: Eliminate non-celebrities
    while (s.size() > 1) {

        int i = s.top();
        s.pop();

        int j = s.top();
        s.pop();

        // If i knows j:
        // i cannot be the celebrity
        // so j remains a candidate.
        if (arr[i][j] == 1) {
            s.push(j);
        }
        else {
            // If i does NOT know j:
            // j cannot be the celebrity
            // so i remains a candidate.
            s.push(i);
        }
    }

    // The last person left is the only possible celebrity
    int celeb = s.top();

    // Step 3: Verify the candidate
    for (int i = 0; i < n; i++) {

        // Celebrity should not know anyone
        if (i != celeb && arr[celeb][i] == 1) {
            return -1;
        }

        // Everyone should know the celebrity
        if (i != celeb && arr[i][celeb] == 0) {
            return -1;
        }
    }

    return celeb;
}

int main() {

    int n = 4;

    vector<vector<int>> arr = {
        {0, 1, 1, 1},
        {0, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0}
    };

    int ans = getCelebrity(arr, n);

    if (ans == -1) {
        cout << "There is no celebrity" << endl;
    }
    else {
        cout << "Celebrity is person: " << ans << endl;
    }

    return 0;
}