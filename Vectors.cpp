#include <iostream>
#include <vector> // CRITICAL: Gives access to the dynamic vector container class
using namespace std;

// ============================================================================
// CHAPTER 1: FOR-EACH LOOP DEMONSTRATION (Modern Vector Syntax)
// ============================================================================
void demonstrateForEachLoop() {
    cout << "--- 1. Modern For-Each Loop Syntax Demonstration ---" << endl;
    
    vector<char> grades = {'A', 'B', 'C', 'A', 'F'};

    // Modern Range-Based For Loop (For-Each Loop)
    cout << "Reading vector grades using For-Each loop: ";
    for (char singleGrade : grades) {
        cout << singleGrade << " "; // 'singleGrade' automatically takes the value of each element
    }
    cout << "\n\n";
}



// ============================================================================
// CHAPTER 2: VECTOR FUNCTIONS TRACE (Taught at 10:04)
// ============================================================================
void demonstrateVectorAPIs() {
    cout << "--- 2. Vector Functions & Dynamic Growth Tracking ---" << endl;
    
    vector<int> vec;

    cout << "Initial state   -> Size: " << vec.size() << " | Capacity: " << vec.capacity() << endl;

    vec.push_back(10);
    cout << "After pushing 10 -> Size: " << vec.size() << " | Capacity: " << vec.capacity() << endl;

    vec.push_back(20);
    cout << "After pushing 20 -> Size: " << vec.size() << " | Capacity: " << vec.capacity() << endl;

    vec.push_back(30); // Size exceeds capacity! Vector capacity doubles from 2 to 4 automatically.
    cout << "After pushing 30 -> Size: " << vec.size() << " | Capacity: " << vec.capacity() << endl;

    vec.push_back(40); // Size is now 4, which matches capacity. Next push will trigger another capacity expansion.
    cout << "After pushing 40 -> Size: " << vec.size() << " | Capacity: " << vec.capacity() << endl;

    vec.push_back(50); // Size exceeds capacity again! Vector capacity doubles from 4 to 8 automatically.
    cout << "After pushing 50 -> Size: " << vec.size() << " | Capacity: " << vec.capacity() << endl;

    // Using a For-Each loop to display current internal state
    cout << "Current Elements in vec: ";
    for (int items : vec) {
        cout << items << " ";
    }
    cout << endl;

    vec.pop_back(); // Destroys the trailing element (30)
    cout << "After pop_back   -> Size: " << vec.size() << " | Capacity: " << vec.capacity() << endl;
    cout << "Front Element: " << vec.front() << " | Back Element: " << vec.back() << "\n\n";
}


// ============================================================================
// CHAPTER 3: INTERVIEW PROBLEM - SINGLE NUMBER (Taught at 23:13)
// ============================================================================
int findSingleNumber(const vector<int>& nums) {
    int uniqueResult = 0;
    
    // Using For-Each loop here to cleanly process the dataset for bitwise math
    for (int currentNum : nums) {
        uniqueResult ^= currentNum; // XOR accumulations cancel out identical pairs
    }
    return uniqueResult;
}


// ============================================================================
// SYSTEM MAIN FUNCTION ENGINE
// ============================================================================
int main() {
    cout << "=========================================================" << endl;
    cout << "        LECTURE 9 MASTER ARCHIVE: C++ VECTORS            " << endl;
    cout << "=========================================================" << endl;

    // 1. Run modern syntax display block
    demonstrateForEachLoop();

    // 2. Run dynamic size vs capacity growth exploration
    demonstrateVectorAPIs();

    cout << "---------------------------------------------------------" << endl;

    // 3. Run LeetCode Practice Problem: Single Number
    vector<int> numbersList = {4, 1, 2, 1, 2}; 
    
    cout << "--- 3. Practice Problem: Single Number (LeetCode 136) ---" << endl;
    cout << "Input Dataset: ";
    for (int num : numbersList) cout << num << " ";
    cout << endl;

    int singleton = findSingleNumber(numbersList);
    cout << "The unique element appearing exactly once is: " << singleton << endl;

    cout << "=========================================================" << endl;
    return 0;
}

