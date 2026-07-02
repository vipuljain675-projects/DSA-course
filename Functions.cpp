#include <iostream>
using namespace std;

// =================================================================
// 🛠️ LAYER 1: THE HELPER FUNCTIONS BLUEPRINT
// =================================================================

// Task A: Simple Math Summation
int sum(int a, int b) {
    int c = a + b;
    return c;
}

// Task B: Conditional Comparison (Finding Min)
int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

// Task C: Loop Traversal & Accumulation (Factorial)
long long factorial(int n) {
    long long fac = 1;
    for (int i = 1; i <= n; i++) {
        fac *= i; 
    }
    return fac;
}

// Task D: Math Modulo Chipping (Sum of Digits)
int SumofDigits(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10; 
        sum += digit;       
        n /= 10;            
    }
    return sum;
}

// Homework Task E: Optimized Prime Check
// Returns true if prime, false if not
bool isPrime(int n) {
    if (n <= 1) return false;
    
    // Loop optimized to check factors up to the square root of n
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false; // Found a factor, not prime
        }
    }
    return true; 
}

// Homework Task G: Find nth Fibonacci Number
// Matches blackboard: 0th->0, 1st->1, 2nd->1, 3rd->2, 4th->3, 5th->5...
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int prev2 = 0; // Represents (i-2)
    int prev1 = 1; // Represents (i-1)
    int current = 0;

    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

// =================================================================
// 🏗️ LAYER 2: ADVANCED COMPOSITE FUNCTIONS (Functions Calling Functions)
// =================================================================

// Task A: Calculates nCr using factorial() helper
long long calculateNCr(int n, int r) {
    if (r > n || r < 0) return 0;

    long long fact_n = factorial(n);       
    long long fact_r = factorial(r);       
    long long fact_nmr = factorial(n - r); 

    long long nCr = fact_n / (fact_r * fact_nmr);
    return nCr;
}

// Homework Task F: Prints all prime numbers from 2 to N using isPrime() helper
void printPrimesFrom2ToN(int N) {
    bool first = true;
    for (int i = 2; i <= N; i++) {
        if (isPrime(i)) { // Modular delegation: asking Layer 1 if 'i' is prime
            if (!first) {
                cout << ", ";
            }
            cout << i;
            first = false;
        }
    }
    cout << endl;
}

// =================================================================
// 💻 LAYER 3: THE EXECUTION CONSOLE
// =================================================================
int main() {
    cout << "========= LECTURE 5 FUNCTION EXECUTION =========" << endl;

    // 1. Testing Sum Function
    int sumResult = sum(3, 4);
    cout << "1. Sum Calculation (3 + 4)       = " << sumResult << endl;

    // 2. Testing Min Function
    int minResult = min(10, 20);
    cout << "2. Minimum Check min(10, 20)      = " << minResult << endl;

    // 3. Testing Factorial Function
    long long factResult = factorial(5);
    cout << "3. Factorial Calculation (5!)     = " << factResult << endl;

    // 4. Testing Digit Chipping Loop Function
    int digitSumResult = SumofDigits(12345);
    cout << "4. Digits Summing of 12345        = " << digitSumResult << endl;

    // 5. Testing Composite Stack Interactivity (nCr Binomial)
    long long nCrResult = calculateNCr(5, 2);                                              
    cout << "5. Binomial Coefficient (5C2)     = " << nCrResult << endl; 

    cout << "------------------------------------------------" << endl;
    cout << "========= HOMEWORK PROBLEMS EXECUTION =========" << endl;

    // 6. Testing Homework 1: Prime Verification Check
    int primeCheckNum = 17;
    cout << "6. Is " << primeCheckNum << " a Prime Number?           = " 
         << (isPrime(primeCheckNum) ? "TRUE (Yes)" : "FALSE (No)") << endl;

    // 7. Testing Homework 2: Print Prime Sequence up to N
    int primeLimit = 20;
    cout << "7. All Prime Numbers from 2 to " << primeLimit << " = ";
    printPrimesFrom2ToN(primeLimit);

    // 8. Testing Homework 3: Find nth Fibonacci Number
    int fibTarget = 6; // Should yield 8 according to her board trace
    cout << "8. The " << fibTarget << "th Fibonacci Number is       = " << fibonacci(fibTarget) << endl;

    cout << "================================================" << endl;
    return 0;
}