#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int maxPages) {

    int studentCount = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {

        // If a single book has more pages than maxPages
        if (arr[i] > maxPages) {
            return false;
        }

        if (pagesSum + arr[i] <= maxPages) {
            pagesSum += arr[i];
        }
        else {
            studentCount++;

            if (studentCount > m) {
                return false;
            }

            pagesSum = arr[i];
        }
    }

    return true;
}

int bookAllocation(vector<int>& arr, int n, int m) {

    // Not enough books for students
    if (m > n) {
        return -1;
    }

    int start = 0;
    int end = 0;

    // Calculate total pages
    for (int i = 0; i < n; i++) {
        end += arr[i];
    }

    int ans = -1;

    while (start <= end) {

        int mid = start + (end - start) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;      // Try smaller answer
        }
        else {
            start = mid + 1;    // Need larger answer
        }
    }

    return ans;
}

int main() {

    vector<int> arr = {10, 20, 30, 40};

    int n = arr.size();
    int m = 2;

    int result = bookAllocation(arr, n, m);

    cout << "Minimum possible maximum pages = "
         << result << endl;

    return 0;
}