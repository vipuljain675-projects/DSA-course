#include <iostream>
#include <vector>

using namespace std;

// =========================================================================
// FUNCTION PATTERNS FOR PASS-BY-REFERENCE DEMONSTRATION
// =========================================================================

// Pass-by-Value: Makes a copy. Original values will NOT change.
void changeValueByValue(int num) {
    num = 500; 
}

// Pass-by-Reference (Using Pointers): Receives raw memory addresses!
void changeValueByPointer(int* ptr) {
    *ptr = 999; // Modifies the actual original variable sitting in main memory!
}

// Pass-by-Reference (Using Alias '&'): The cleaner, modern C++ way
void changeValueByAlias(int &numRef) {
    numRef = 777; // Modifies the original directly without needing * symbols
}

// =========================================================================
// MAIN CORE EXECUTION ENGINE
// =========================================================================
int main() {
    cout << "=========================================================" << endl;
    cout << "             LECTURE 16: POINTERS IN C++ MASTER          " << endl;
    cout << "=========================================================" << endl;

    // ---------------------------------------------------------------------
    // 1. BASIC MEMORY TRACKING & CREATION
    // ---------------------------------------------------------------------
    int a = 10;
    
    // An integer pointer (int*) can ONLY store the memory address of an integer.
    int* ptr = &a; 

    cout << "[1] Core Address Mapping:" << endl;
    cout << "Value of 'a'               = " << a << endl;
    cout << "Address-of 'a' (&a)        = " << &a << endl;
    cout << "Value stored in 'ptr'      = " << ptr << endl;
    cout << "Address of 'ptr' itself    = " << &ptr << "\n\n";

    // ---------------------------------------------------------------------
    // 2. THE DEREFERENCE OPERATOR (*)
    // ---------------------------------------------------------------------
    // Putting a * in front of a pointer variable means "Value At Address"
    cout << "[2] Dereferencing Logic (*ptr):" << endl;
    cout << "Value at address held by ptr = " << *ptr << endl;
    
    *ptr = 25; // Directly altering the data in that box via its address!
    cout << "New value of 'a' after *ptr modification = " << a << "\n\n";

    // ---------------------------------------------------------------------
    // 3. POINTER TO POINTER (Double Pointers)
    // ---------------------------------------------------------------------
    // Stores the memory address of another pointer variable
    int** q = &ptr; 

    cout << "[3] Double Pointer Hierarchy:" << endl;
    cout << "Address of ptr stored in q   = " << q << endl;
    cout << "Dereferencing q once (*q)     = " << *q << " (Gives address of a)" << endl;
    cout << "Dereferencing q twice (**q)   = " << **q << " (Gives value of a: 25)" << "\n\n";

    // ---------------------------------------------------------------------
    // 4. THE NULL POINTER SAFETY GAP
    // ---------------------------------------------------------------------
    // Always initialize pointers to null if they don't point to data yet
    int* safePtr = nullptr; // Explicitly points to nothing (0)
    
    cout << "[4] Safe Pointers Initialization:" << endl;
    cout << "Value of safePtr = " << safePtr << endl;
    if (safePtr == nullptr) {
        cout << "-> Safety Triggered: Pointer is unassigned. Do not dereference!" << "\n\n";
    }

    // ---------------------------------------------------------------------
    // 5. PASS BY VALUE VS PASS BY REFERENCE (Taught at 21:45)
    // ---------------------------------------------------------------------
    int score = 100;
    cout << "[5] Memory Parameter Passing States (Original Score = " << score << "):" << endl;

    // A. Testing Pass-by-Value
    changeValueByValue(score);
    cout << "-> After changeValueByValue()   : " << score << " (No change!)" << endl;

    // B. Testing Pass-by-Reference via Pointer
    changeValueByPointer(&score); // We pass the physical address of score
    cout << "-> After changeValueByPointer() : " << score << " (Value changed successfully!)" << endl;

    // C. Testing Pass-by-Reference via Alias
    changeValueByAlias(score); // Clean passing syntax
    cout << "-> After changeValueByAlias()   : " << score << " (Value changed successfully!)" << endl;

    cout << "=========================================================" << endl;
    

    // Array pointer 
    int arr[] = {1,2,3,4};
    int* ptpr = arr;
    cout << ptpr << endl;


    //Pointer arthimetic 

    ptpr++;

    cout << ptpr << endl;


    

  
    return 0;
}