#include <iostream>
#include <climits> // Required for INT_MAX and INT_MIN
using namespace std;

// ============================================================================
// CHAPTER 1: PASS BY VALUE VS PASS BY REFERENCE (Taught at 24:04)
// ============================================================================
void demonstratePassByValue(int x) {
    x = 500;
}

void demonstratePassByReference(int arr[], int size) {
    arr[0] = 999; 
}

// ============================================================================
// CHAPTER 2: SMALLEST/LARGEST VALUE & INDEX FINDER (Taught at 15:45)
// ============================================================================
void findMinMaxAndIndices(int arr[], int size) {
    int smallestValue = INT_MAX, largestValue = INT_MIN;
    int smallestIndex = -1, largestIndex = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] < smallestValue) {
            smallestValue = arr[i];
            smallestIndex = i;
        }
        if (arr[i] > largestValue) {
            largestValue = arr[i];
            largestIndex = i;
        }
    }
    cout << "Smallest Value discovered: " << smallestValue << " at Index: [" << smallestIndex << "]" << endl;
    cout << "Largest Value discovered : " << largestValue << " at Index: [" << largestIndex << "]" << endl;
}

// ============================================================================
// CHAPTER 3: LINEAR SEARCH ALGORITHM ENGINE (Taught at 30:09)
// ============================================================================
int executeLinearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// ============================================================================
// CHAPTER 4: TWO-POINTER IN-PLACE ARRAY REVERSAL (Taught at 37:38)
// ============================================================================
void reverseArrayInPlace(int arr[], int size) {
    int start = 0, end = size - 1;
    while (start < end) {
        swap(arr[start], arr[end]); // C++ built-in swap function for cleaner code
        start++;
        end--;
    }

    cout << "Array after reversal: " << endl;

    for (int i = 0; i < size; i++) {cout << arr[i] << " ";
}
    cout << endl;
}

// ============================================================================
// CHAPTER 5: HOMEWORK EXERCISES (Visible on Screen)
// ============================================================================

// HW 1: Calculate Sum and Product of all elements
void printSumAndProduct(int arr[], int size) {
    int sum = 0;
    long long product = 1; // Long long used to handle large multiplications safely
    
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        product *= arr[i];
    }
    cout << "HW 1 -> Sum of array elements: " << sum << " | Product: " << product << endl;
}

// HW 2: Swap the maximum and minimum values in-place
void swapMaxAndMin(int arr[], int size) {
    int smallestVal = INT_MAX, largestVal = INT_MIN;
    int smallestIdx = -1, largestIdx = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i] < smallestVal) { smallestVal = arr[i]; smallestIdx = i; }
        if (arr[i] > largestVal) { largestVal = arr[i]; largestIdx = i; }
    }
    
    if (smallestIdx != -1 && largestIdx != -1) {
        swap(arr[smallestIdx], arr[largestIdx]);
    }
}

// HW 3: Print all unique values using a nested loop
void printUniqueValues(int arr[], int size) {
    cout << "HW 3 -> Unique values in the array: ";
    for (int i = 0; i < size; i++) {
        int count = 0;
        // Inner loop checks the rest of the array for duplicates
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        // If it only appeared once, it's completely unique!
        if (count == 1) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

// HW 4: Print intersection of 2 arrays using a nested loop
void printIntersection(int arr1[], int size1, int arr2[], int size2) {
    cout << "HW 4 -> Intersection of the 2 arrays: ";
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";
                break; // Break loop early to prevent double printing if arr2 has duplicate values
            }
        }
    }
    cout << endl;
}


// Standard Utilities
int SumOfElementsArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return sum;
}

double AverageOfElementsArray(int arr[], int size) {
    if (size == 0) return 0;
    return double(SumOfElementsArray(arr, size)) / size;
}

void doubleEveryElement(int arr[], int size) {
    for (int i = 0; i < size; i++) arr[i] *= 2;
}

void halveElementAtIndex(int arr[], int size, int index) {
    if (index >= 0 && index < size) arr[index] /= 2;
}

// ============================================================================
// SYSTEM MAIN EXECUTION ENGINE
// ============================================================================
int main() {
    cout << "=========================================================" << endl;
    cout << "   COMPLETED LECTURE 8 MASTER ARCHIVE WITH HOMEWORK      " << endl;
    cout << "=========================================================" << endl;

    int sampleData[] = {15, 22, 1, -15, 24};
    int size = sizeof(sampleData) / sizeof(sampleData[0]);

    cout << "Initial Data Array Output: ";
    for (int i = 0; i < size; i++) cout << sampleData[i] << " ";
    cout << "\n----------------------------------------------------------" << endl;

    // Run core lecture operations
    demonstratePassByReference(sampleData, size);
    findMinMaxAndIndices(sampleData, size);
    reverseArrayInPlace(sampleData, size);

    // RUNNING HOMEWORK TASKS
    printSumAndProduct(sampleData, size);

    cout << "Executing HW 2 (Swapping Max and Min elements)..." << endl;
    swapMaxAndMin(sampleData, size);
    cout << "Array after Swap Max/Min: ";
    for (int i = 0; i < size; i++) cout << sampleData[i] << " ";
    cout << endl;

    // Testing Unique Elements (Let's insert a duplicate '22' value temporarily in a test array)
    int duplicateTest[] = {1, 2, 3, 1, 2, 3, 4}; // Matching Ma'am's board sample!
    printUniqueValues(duplicateTest, 7); // Should print only 4

    // Testing Intersection
    int arrayA[] = {1, 2, 3, 4, 5};
    int arrayB[] = {3, 4, 5, 6, 7};
    printIntersection(arrayA, 5, arrayB, 5); // Should print 3 4 5

    cout << "=========================================================" << endl;
    return 0;
}


