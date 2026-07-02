#include <iostream>
using namespace std;

// ============================================================================
// GLOBAL SCOPE DEMONSTRATION (Taught at 18:03)
// ============================================================================
// This variable lives outside all functions. It is visible and modifiable everywhere.
int globalStrategicScore = 999; 

void scopeShowcase() {
    int localToFunction = 45; // Local variable to this function container
    cout << "Inside scopeShowcase() -> Global variable: " << globalStrategicScore << endl;
    cout << "Inside scopeShowcase() -> Local to function: " << localToFunction << endl;
}


int main() {
    // ============================================================================
    // 1. BITWISE OPERATORS DEMONSTRATION (Taught at 0:39)
    // ============================================================================
    cout << "=========================================" << endl;
    cout << "   1. BITWISE OPERATORS DEMONSTRATION    " << endl;
    cout << "=========================================" << endl;
    
    int a = 6; // Binary representation layout: 110
    int b = 5; // Binary representation layout: 101

    // Bitwise AND (&): Output is 1 only if both matching column bits are 1
    cout << "Bitwise AND (6 & 5)   : " << (a & b) << "  (Binary result: 100)" << endl; 

    // Bitwise OR (|): Output is 1 if at least one matching column bit is 1
    cout << "Bitwise OR  (6 | 5)   : " << (a | b) << "  (Binary result: 111)" << endl; 

    // Bitwise XOR (^): Output is 1 if matching column bits are different
    cout << "Bitwise XOR (6 ^ 5)   : " << (a ^ b) << "  (Binary result: 011)" << endl; 

    // Bitwise NOT (~): Flips all bits. Turn positive to negative via 2's complement
    cout << "Bitwise NOT (~6)      : " << (~a) << endl; 
    
    cout << endl;


    // ============================================================================
    // 2. BIT SHIFTING TRICKS (Taught at 0:39)
    // ============================================================================
    cout << "=========================================" << endl;
    cout << "         2. BIT SHIFTING TRICKS          " << endl;
    cout << "=========================================" << endl;

    // Left Shift (<<): Shifts bits left. Formula: a << z = a * (2^z)
    cout << "Left Shift  (4 << 1)  : " << (4 << 1) << "  (Math: 4 * 2^1 = 8)" << endl;
    cout << "Left Shift  (4 << 2)  : " << (4 << 2) << "  (Math: 4 * 2^2 = 16)" << endl;

    // Right Shift (>>): Shifts bits right. Formula: a >> z = a / (2^z)
    cout << "Right Shift (8 >> 1)  : " << (8 >> 1) << "   (Math: 8 / 2^1 = 4)" << endl;
    cout << "Right Shift (8 >> 2)  : " << (8 >> 2) << "   (Math: 8 / 2^2 = 2)" << endl;

    cout << endl;


    // ============================================================================
    // 3. SCOPE (LOCAL VS GLOBAL) DEMONSTRATION (Taught at 18:03)
    // ============================================================================
    cout << "=========================================" << endl;
    cout << "      3. LOCAL VS GLOBAL SCOPE           " << endl;
    cout << "=========================================" << endl;

    int localToMain = 10; // Variable born inside main()
    cout << "Inside main() -> Reading localToMain: " << localToMain << endl;
    cout << "Inside main() -> Reading global variable: " << globalStrategicScore << endl;

    // Call external function block to see its scope routing
    scopeShowcase();

    // Block Scope Inside Curly Braces {}
    if (true) {
        int blockVariable = 777; // Born inside this specific IF block context
        cout << "Inside IF Block -> blockVariable: " << blockVariable << endl;
        cout << "Inside IF Block -> Reading global variable: " << globalStrategicScore << endl;
    }
    
    // cout << blockVariable; 
    // ^⚠️ CRITICAL COMPILER ERROR: If you uncomment the line above, the engine will crash! 
    // blockVariable died permanently the microsecond the execution passed the closing curly brace '}'.

    cout << endl;


    // ============================================================================
    // 4. DATA TYPE MODIFIERS MASTERCLASS (Taught at 24:12)
    // ============================================================================
    cout << "=========================================" << endl;
    cout << "       4. DATA TYPE MODIFIERS            " << endl;
    cout << "=========================================" << endl;

    // short: Shrinks hardware memory to 2 bytes (16 bits). Limit: 32,767
    short int smallContainer = 32700;
    cout << "Short Int Value       : " << smallContainer 
         << "   (Memory Allocation: " << sizeof(smallContainer) << " bytes)" << endl;

    // long: Allocates at least 4 bytes (32 bits)
    long int standardLarge = 2147483640;
    cout << "Long Int Value        : " << standardLarge 
         << "   (Memory Allocation: " << sizeof(standardLarge) << " bytes)" << endl;

    // long long: Allocates a massive 8 bytes (64 bits) of RAM hardware space
    long long int cryptographicKey = 9223372036854775800LL; 
    cout << "Long Long Value       : " << cryptographicKey 
         << " (Memory Allocation: " << sizeof(cryptographicKey) << " bytes)" << endl;

    // signed: Default setup. The leading MSB bit tracks positive/negative states
    signed int negativeTrace = -10; // Uses the 2's complement blackboard logic
    cout << "Signed Int Value      : " << negativeTrace << endl;

    // unsigned: Removes sign bit. Converts it to double your maximum positive capacity limit!
    unsigned int doubleCapacityPositives = 4294967290U; 
    cout << "Unsigned Int Value    : " << doubleCapacityPositives 
         << " (Can hold values up to 4.29 Billion!)" << endl;

    cout << "=========================================" << endl;
    return 0;
}
