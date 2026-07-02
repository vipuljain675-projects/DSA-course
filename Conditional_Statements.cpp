#include <iostream>
using namespace std;

int main() {
    // 1. Your existing if-else if-else logic
    int salary;
    cout << "Enter your annual salary (in thousands): ";
    cin >> salary;

    if (salary < 10) {
        cout << "Tax Rate: 0% (Tax Exempt)" << endl;
    } 
    else if (salary >= 10 && salary < 50) {
        cout << "Tax Rate: 10%" << endl;
    } 
    else {
        cout << "Tax Rate: 30%" << endl;
    }

    cout << "------------------------------------------" << endl;

    // 2. New Ternary Operator Example
    int age;
    cout << "Enter your age to check filing status: ";
    cin >> age;

    // Condition ? True Output : False Output
    string status = (age >= 60) ? "Senior Citizen Tax Bracket" : "Standard Tax Bracket";
    
    cout << "Your Status: " << status << endl;


    //  3. While loop 
    int n = 100;
    int count = 1;
    cout << "Counting from 1 to " << n << " using a while loop:" << endl;
    while (count <= n) {
        cout << count << " ";
        count++;
    }
    cout << endl;

    // 4. for loop

    int b = 50;
    int sum = 0;

    for(int i = 1; i <= b; i++) {
        sum += i; // sum = sum + i
        cout << "Current number: " << i << ", Running Sum: " << sum << endl;
    }
    cout << "Final Sum: " << sum << endl;

    int i = 1;

    do {
        cout << i << " ";
        i++;
    } while (i <= 5); // Don't forget this semicolon at the end!

    cout << endl;

    return 0;
}
