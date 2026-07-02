#include <iostream>
#include <vector>

using namespace std;

// =========================================================================
// METHOD 1: SELECTION SORT (Hunts for the smallest and locks Left-to-Right)
// =========================================================================
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// =========================================================================
// METHOD 2: BUBBLE SORT (Sinks the heaviest and locks Back-to-Front)
// =========================================================================
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool hasSwapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                hasSwapped = true;
            }
        }
        if (!hasSwapped) break;
    }
}

// =========================================================================
// METHOD 3: INSERTION SORT (Shifts and inserts elements like a deck of cards)
// Time Complexity: O(n^2) worst | O(n) best-case if already sorted
// =========================================================================
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    // Loop starts at 1 because index 0 is already considered "sorted" by default
    for (int i = 1; i < n; i++) {
        int curr = arr[i]; // The current card we want to insert
        int prev = i - 1;  // Pointer to scan backward through the sorted part

        // Shift elements of the sorted segment forward if they are greater than 'curr'
        while (prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev]; // Shift forward
            prev--;                    // Move pointer backward
        }

        // Insert 'curr' into its correct structural pocket
        arr[prev + 1] = curr;
    }
}

// =========================================================================
// HELPER PRINTER FUNCTION
// =========================================================================
void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

// =========================================================================
// MAIN RUNTIME TESTING SUITE
// =========================================================================
int main() {
    // Setting up separate datasets with your custom numbers
    vector<int> arrSelection = {5, 4, 0, 11, 1, 3, 2};
    vector<int> arrBubble    = {5, 4, 0, 11, 1, 3, 2};
    vector<int> arrInsertion = {5, 4, 0, 11, 1, 3, 2};

    cout << "=========================================================" << endl;
    cout << "          THE BIG THREE SORTING ALGORITHMS MATRIX        " << endl;
    cout << "=========================================================" << endl;
    cout << "Original Dataset: ";
    printArray(arrSelection);
    cout << "--------------------------------------------------------..." << endl;

    // 1. Selection Sort
    selectionSort(arrSelection);
    cout << "-> 1. Selection Sort Result : ";
    printArray(arrSelection);

    // 2. Bubble Sort
    bubbleSort(arrBubble);
    cout << "-> 2. Bubble Sort Result    : ";
    printArray(arrBubble);

    // 3. Insertion Sort
    insertionSort(arrInsertion);
    cout << "-> 3. Insertion Sort Result : ";
    printArray(arrInsertion);
    cout << "=========================================================" << endl;

    return 0;
} 