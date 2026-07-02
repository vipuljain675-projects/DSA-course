#include <iostream>
#include <vector>
using namespace std;

// ==================================================
// 1. Fibonacci Number (Recursive)
// ==================================================

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fib(n - 1) + fib(n - 2);
}

// ==================================================
// 2. Check if Array is Sorted
// ==================================================

bool isSorted(vector<int>& arr, int n) {

    if (n == 1) {
        return true;
    }

    if (arr[n - 1] < arr[n - 2]) {
        return false;
    }

    return isSorted(arr, n - 1);
}

// ==================================================
// 3. Recursive Binary Search
// ==================================================

int binarySearch(vector<int>& arr, int target,
                 int start, int end) {

    if (start > end) {
        return -1;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == target) {
        return mid;
    }

    if (arr[mid] < target) {
        return binarySearch(arr, target,
                            mid + 1, end);
    }

    return binarySearch(arr, target,
                        start, mid - 1);
}

// ==================================================
// Main Function
// ==================================================

int main() {

    // -------------------------------
    // Fibonacci
    // -------------------------------

    cout << "Fibonacci of 5 = ";
    cout << fib(5);

    // -------------------------------
    // Sorted Array Check
    // -------------------------------

    vector<int> arr1 = {1, 2, 3, 4, 5};

    cout << "\n\nArray Sorted? ";

    if (isSorted(arr1, arr1.size())) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    // -------------------------------
    // Recursive Binary Search
    // -------------------------------

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12};

    int target = 9;

    int index =
        binarySearch(arr2, target,
                     0, arr2.size() - 1);

    cout << "\n\nIndex of " << target
         << " = " << index << endl;

    return 0;
}