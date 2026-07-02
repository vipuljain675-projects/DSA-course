#include <iostream>
#include <vector>
#include <algorithm> // Required for std::sort and std::next_permutation
#include <cmath>     // Required for sqrt()

using namespace std;

// =========================================================================
// 1. CONSTANT TIME: O(1)
// =========================================================================
void demonstrateConstantTime(const vector<int>& nums) {
    cout << "--- [1] O(1) Constant Time ---" << endl;
    int firstElement = nums[0]; // Instant 1-step retrieval
    cout << "Array size (n) = " << nums.size() << " | CPU Operations = 1" << endl;
    cout << "Value: " << firstElement << "\n\n";
}

// =========================================================================
// 2. LOGARITHMIC TIME: O(log n)
// =========================================================================
void demonstrateLogarithmicTime(int n) {
    cout << "--- [2] O(log n) Logarithmic Time ---" << endl;
    int opCount = 0;
    int i = n;
    while (i > 1) {
        opCount++;
        i /= 2; // Cutting work in half
    }
    cout << "Input value (n) = " << n << " | CPU Operations = " << opCount << "\n\n";
}

// =========================================================================
// 3. SQUARE ROOT TIME: O(sqrt(n))
// =========================================================================
void demonstrateSquareRootTime(int n) {
    cout << "--- [3] O(sqrt(n)) Square Root Time ---" << endl;
    int opCount = 0;
    for (int i = 2; i * i <= n; i++) {
        opCount++;
    }
    cout << "Input value (n) = " << n << " | CPU Operations = " << opCount << "\n\n";
}

// =========================================================================
// 4. LINEAR TIME: O(n)
// =========================================================================
void demonstrateLinearTime(const vector<int>& nums) {
    cout << "--- [4] O(n) Linear Time ---" << endl;
    int opCount = 0;
    for (int i = 0; i < nums.size(); i++) {
        opCount++;
    }
    cout << "Array size (n) = " << nums.size() << " | CPU Operations = " << opCount << "\n\n";
}

// =========================================================================
// 5. LINEARITHMIC TIME: O(n log n)
// =========================================================================
// This mimics the performance behavior of high-efficiency sorting (like Merge Sort).
void demonstrateLinearithmicTime(int n) {
    cout << "--- [5] O(n log n) Linearithmic Time ---" << endl;
    int opCount = 0;
    
    // An outer linear loop combined with an inner halving process
    for (int i = 0; i < n; i++) {
        int j = n;
        while (j > 1) {
            opCount++;
            j /= 2;
        }
    }
    cout << "Input size (n) = " << n << " | CPU Operations = " << opCount << "\n\n";
}

// =========================================================================
// 6. QUADRATIC TIME: O(n^2)
// =========================================================================
void demonstrateQuadraticTime(int n) {
    cout << "--- [6] O(n^2) Quadratic Time ---" << endl;
    int opCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            opCount++;
        }
    }
    cout << "Input size (n) = " << n << " | CPU Operations = " << opCount << "\n\n";
}

// =========================================================================
// 7. EXPONENTIAL TIME: O(2^n)
// =========================================================================
// Classic trigger: Generating all subsets or an unoptimized Fibonacci recursion tree.
// To keep things safe for your terminal run, we track how operations double dynamically.
void demonstrateExponentialTime(int n) {
    cout << "--- [7] O(2^n) Exponential Time ---" << endl;
    long long opCount = 1; 
    
    for (int i = 0; i < n; i++) {
        opCount *= 2; // Operations double with every single extra item added!
    }
    cout << "Input elements (n) = " << n << " | CPU Operations (2^n) = " << opCount << "\n\n";
}

// =========================================================================
// 8. FACTORIAL TIME: O(n!)
// =========================================================================
// Classic trigger: Generating every single possible arrangement/permutation of a string.
void demonstrateFactorialTime(int n) {
    cout << "--- [8] O(n!) Factorial Time ---" << endl;
    long long opCount = 1;
    
    for (int i = 1; i <= n; i++) {
        opCount *= i; // 1 * 2 * 3 * ... * n
    }
    cout << "Input elements (n) = " << n << " | CPU Operations (n!) = " << opCount << "\n";
    cout << "(Danger zone: If n was just 20, operations would hit 2,432,902,008,176,640,000!)\n\n";
}

// =========================================================================
// EXECUTION CENTRAL MONITOR
// =========================================================================
int main() {
    cout << "=========================================================" << endl;
    cout << "    DSA LECTURE 12 COMPLETE MASTER: ALL BIG-O MATRIX     " << endl;
    cout << "=========================================================" << endl;

    // Using a test scale baseline of n = 8 to cleanly observe how fast the speeds diverge
    int testSize = 8;
    vector<int> sampleVector(testSize, 100);

    demonstrateConstantTime(sampleVector);
    demonstrateLogarithmicTime(testSize);
    demonstrateSquareRootTime(testSize);
    demonstrateLinearTime(sampleVector);
    demonstrateLinearithmicTime(testSize);
    demonstrateQuadraticTime(testSize);
    demonstrateExponentialTime(testSize);
    demonstrateFactorialTime(testSize);

    cout << "=========================================================" << endl;
    return 0;
}