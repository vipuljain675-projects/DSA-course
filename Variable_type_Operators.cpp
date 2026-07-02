#include <iostream>
using namespace std;

int main() {
    // ==========================================
    // PART 1: Data Types & Type Casting
    // ==========================================
    int age = 25;
    float height = 1.75;
    char grade = 'A';
    bool isStudent = true;
    double weight = 70.5;

    int value = grade; 
    int due = (int)weight; 

    cout << "Hello, I am " << age << " years old." << endl;
    cout << "Size of int: " << sizeof(age) << " bytes" << endl;
    cout << "Size of float: " << sizeof(height) << " bytes" << endl;
    cout << "Size of char: " << sizeof(grade) << " bytes" << endl;
    cout << "Size of bool: " << sizeof(isStudent) << " bytes" << endl;
    cout << "Size of double: " << sizeof(weight) << " bytes" << endl;
    cout << "The ASCII value of '" << grade << "' is: " << value << endl;
    cout << "The integer value of weight is: " << due << endl;

    cout << "------------------------------------------" << endl;

    // ==========================================
    // PART 2: User Input
    // ==========================================
    double price;
    cout << "Enter the price: ";
    cin >> price; 
    cout << "You entered price = " << price << endl;

    cout << "------------------------------------------" << endl;

    // ==========================================
    // PART 3: Arithmetic Operators
    // ==========================================
    int a = 10;
    int b = 3;
    int c = 12;

    cout << "Arithmetic Operator Demonstrations (with a = 10, b = 3):" << endl;
    cout << "Addition (a + b)        = " << (a + b) << endl;
    cout << "Subtraction (a - b)     = " << (a - b) << endl;
    cout << "Multiplication (a * b)  = " << (a * b) << endl;
    
    // Pay close attention to these last two!
    cout << "Integer Division (a / b) = " << (a / b) << endl; 
    cout << "Modulo/Remainder (a % b) = " << (a % b) << endl; 
    cout << (10 == 3) << " (true if 10 equals 3, false otherwise)" << endl;
    cout << (10 != 3) << " (true if 10 does not equal 3, false otherwise)" << endl;
    cout << ((a > c) || (b < c)) << " (true if a > c OR b < c, false otherwise)" << endl;

    return 0;
}

// This code demonstrates the use of various data types, type casting, user input, and arithmetic operators in C++. It covers integer, float, char, bool, and double data types, as well as how to take user input and perform basic arithmetic operations. The output includes the sizes of different data types and the results of arithmetic operations.
