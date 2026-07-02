#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// =====================================================
// CONCEPT 1: PRIME NUMBER CHECK
// =====================================================
string isPrime(int n) {

    if (n < 2)
        return "not prime";

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return "not prime";
    }

    return "prime";
}

// =====================================================
// CONCEPT 2: SIEVE OF ERATOSTHENES
// LeetCode 204 - Count Primes
// =====================================================
int countPrimes(int n) {

    vector<bool> isPrimeArr(n + 1, true);

    int count = 0;

    for (int i = 2; i < n; i++) {

        if (isPrimeArr[i]) {

            count++;

            for (int j = i * 2; j < n; j += i) {
                isPrimeArr[j] = false;
            }
        }
    }

    return count;
}

// =====================================================
// CONCEPT 3: DIGIT EXTRACTION
// Count Digits + Sum of Digits
// =====================================================
void PrintDigits(int n) {

    int count = 0;
    int sum = 0;

    while (n != 0) {

        int digit = n % 10;

        sum += digit;
        count++;

        cout << "Digit = " << digit << endl;
        cout << "Count so far = " << count << endl;
        cout << "Sum so far = " << sum << endl;

        n /= 10;
    }

    cout << "\nTotal Digits = " << count << endl;
    cout << "Total Sum = " << sum << endl;
}

// =====================================================
// CONCEPT 4: ARMSTRONG NUMBER
// =====================================================
bool isArmstrong(int n) {

    int original = n;
    int digits = 0;
    int sum = 0;

    int temp = n;

    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    temp = n;

    while (temp != 0) {

        int digit = temp % 10;

        sum += pow(digit, digits);

        temp /= 10;
    }

    return sum == original;
}

// =====================================================
// CONCEPT 5: EUCLID'S ALGORITHM (GCD)
// =====================================================
int gcd(int a, int b) {

    while (b != 0) {

        int rem = a % b;

        a = b;
        b = rem;
    }

    return a;
}

// =====================================================
// CONCEPT 6: LCM
// =====================================================
int lcm(int a, int b) {

    return (a / gcd(a, b)) * b;
}

// =====================================================
// CONCEPT 7: REVERSE A NUMBER
// =====================================================
int reverseNumber(int n) {

    int revNum = 0;

    while (n != 0) {

        int digit = n % 10;

        revNum = (revNum * 10) + digit;

        n /= 10;
    }

    return revNum;
}

// =====================================================
// CONCEPT 8: PALINDROME NUMBER
// =====================================================
bool isPalindrome(int n) {

    if (n < 0)
        return false;

    return n == reverseNumber(n);
}

// =====================================================
// CONCEPT 9: MODULAR ARITHMETIC
// =====================================================
void modularArithmeticDemo() {

    int a = 15;
    int b = 17;
    int mod = 7;

    cout << "(a + b) % mod = "
         << (a + b) % mod
         << endl;

    cout << "(a * b) % mod = "
         << (a * b) % mod
         << endl;

    cout << "(a - b + mod) % mod = "
         << ((a - b + mod) % mod)
         << endl;
}

// =====================================================
// MAIN FUNCTION
// =====================================================
int main() {

    // -----------------------------
    // PRIME NUMBER CHECK
    // -----------------------------
    cout << "===== PRIME NUMBER CHECK =====" << endl;

    int num = 47;

    cout << num << " is "
         << isPrime(num) << endl;

    // -----------------------------
    // SIEVE OF ERATOSTHENES
    // -----------------------------
    cout << "\n===== SIEVE OF ERATOSTHENES =====" << endl;

    int n = 10;

    cout << "Number of primes less than "
         << n << " = "
         << countPrimes(n) << endl;

    // -----------------------------
    // DIGIT EXTRACTION
    // -----------------------------
    cout << "\n===== DIGIT EXTRACTION =====" << endl;

    int n3 = 2345;

    PrintDigits(n3);

    // -----------------------------
    // ARMSTRONG NUMBER
    // -----------------------------
    cout << "\n===== ARMSTRONG NUMBER =====" << endl;

    int arm = 153;

    if (isArmstrong(arm))
        cout << arm << " is an Armstrong Number" << endl;
    else
        cout << arm << " is NOT an Armstrong Number" << endl;

    // -----------------------------
    // EUCLID'S ALGORITHM (GCD)
    // -----------------------------
    cout << "\n===== EUCLID'S ALGORITHM (GCD) =====" << endl;

    int a = 20;
    int b = 28;

    cout << "GCD of "
         << a << " and "
         << b << " = "
         << gcd(a, b)
         << endl;

    // -----------------------------
    // LCM
    // -----------------------------
    cout << "\n===== LCM =====" << endl;

    int x = 12;
    int y = 18;

    cout << "LCM of "
         << x << " and "
         << y << " = "
         << lcm(x, y)
         << endl;

    // -----------------------------
    // REVERSE A NUMBER
    // -----------------------------
    cout << "\n===== REVERSE A NUMBER =====" << endl;

    int num2 = 4537;

    cout << "Original Number = "
         << num2
         << endl;

    cout << "Reversed Number = "
         << reverseNumber(num2)
         << endl;

    // -----------------------------
    // PALINDROME NUMBER
    // -----------------------------
    cout << "\n===== PALINDROME NUMBER =====" << endl;

    int pal = 121;

    if (isPalindrome(pal))
        cout << pal << " is a Palindrome Number" << endl;
    else
        cout << pal << " is NOT a Palindrome Number" << endl;

    // -----------------------------
    // MODULAR ARITHMETIC
    // -----------------------------
    cout << "\n===== MODULAR ARITHMETIC =====" << endl;

    modularArithmeticDemo();

    return 0;
}