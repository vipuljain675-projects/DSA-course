#include <iostream>
using namespace std;

// 1. Descending: n to 1
void printDescending(int n) {
    if (n == 0) {
        return;
    }

    cout << n << " ";
    printDescending(n - 1);
}

// 2. Ascending: 1 to n
void printAscending(int n) {
    if (n == 0) {
        return;
    }

    printAscending(n - 1);
    cout << n << " ";
}

// 3. Factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return n * factorial(n - 1);
}

// 4. Sum of first n natural numbers
int sumN(int n) {
    if (n == 0) {
        return 0;
    }

    return n + sumN(n - 1);
}

int main() {

    cout << "Descending Order:\n";
    printDescending(5);

    cout << "\n\nAscending Order:\n";
    printAscending(5);

    cout << "\n\nFactorial of 5:\n";
    cout << factorial(5);

    cout << "\n\nSum of first 5 natural numbers:\n";
    cout << sumN(5);

    cout << endl;

    return 0;
}