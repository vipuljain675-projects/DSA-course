#include <iostream>
#include <string>    // Required for std::string
#include <cstring>   // Required for C-style string functions like strlen()
#include <algorithm> // Required for std::reverse
using namespace std;

int main() {
    // =========================================================================
    // SECTION 1: CHARACTER ARRAYS (C-STYLE STRINGS)
    // =========================================================================
    cout << "=== 1. Character Arrays Section ===\n";

    char str[] = {'a' , 'b', 'c', '\0'}; // Explicit null-terminated array
    char str2[] = "Hello, World!";       // Implicitly null-terminated string literal
    char str3[20];                       // Fixed-size char array for input

    cout << "Enter character array text: ";
    cin.getline(str3, 20); 

    cout << "Raw loop through str3 slots: ";
    for(char ch : str3) {
        cout << ch << " "; 
    }
    cout << "\n\n";

    cout << "C-Style length of str: " << strlen(str) << endl;   // Output: 3
    cout << "C-Style length of str2: " << strlen(str2) << endl; // Output: 13
    cout << "Char at index 2 of str: " << str[2] << endl;        // Output: c
    cout << "Char at index 9 of str2: " << str2[9] << endl;      // Output: r
    cout << "===================================\n\n";


    // =========================================================================
    // SECTION 2: MODERN C++ STRINGS (DECLARATION & INPUT)
    // =========================================================================
    cout << "=== 2. Modern C++ std::string Section ===\n";

    string s1 = "apna";
    string s2 = "college";
    
    // Concatenation & Length Properties
    string s3 = s1 + " " + s2; // Results in "apna college"
    cout << "Concatenated String (s3): " << s3 << endl;
    cout << "Length of s3 using .size(): " << s3.size() << endl; // Output: 12

    // Dynamic Input Reading using global getline()
    string standard_input;
    cout << "\nEnter a line of text for standard string: ";
    getline(cin, standard_input); 
    cout << "Stored standard string value: " << standard_input << endl;
    cout << "===================================\n\n";


    // =========================================================================
    // SECTION 3: LOOPING THROUGH STRINGS (NEW INTEGRATION)
    // =========================================================================
    cout << "=== 3. Ways to Loop Through a String ===\n";
    string loop_str = "DSA";

    // Method A: Traditional Index-Based Loop
    // Best used when you need to know or manipulate the exact index position numbers.
    cout << "Index-Based Loop: ";
    for (int i = 0; i < loop_str.length(); i++) {
        cout << loop_str[i] << " ";
    }
    cout << "\n";

    // Method B: Range-Based (For-Each) Loop
    // The cleanest syntax. Creates a temporary copy of each character as it passes through.
    cout << "Range-Based Loop: ";
    for (char ch : loop_str) {
        cout << ch << " ";
    }
    cout << "\n";

    // Method C: Modern Iterator-Based Loop
    // Standard STL way to move pointers from the memory beginning to the memory end.
    cout << "Iterator-Based Loop: ";
    for (auto it = loop_str.begin(); it != loop_str.end(); ++it) {
        cout << *it << " "; // Requires dereference star to pull character out
    }
    cout << "\n===================================\n\n";


    // =========================================================================
    // SECTION 4: STRING REVERSAL TECHNIQUES (NEW INTEGRATION)
    // =========================================================================
    cout << "=== 4. String Reversal Section ===\n";
    string rev_target = "apna";
    cout << "Original String: " << rev_target << endl;

    // Method A: Manual Two-Pointer Swap Loop
    // Highly valued in interviews. Modifies string in-place with O(1) space.
    int left = 0;
    int right = rev_target.length() - 1;
    while (left < right) {
        swap(rev_target[left], rev_target[right]);
        left++;
        right--;
    }
    cout << "After Manual Reverse:  " << rev_target << endl; // Output: anpa

    // Method B: STL Quick Reverse Algorithm
    // Instantly flips it back to original state using built-in iterators.
    reverse(rev_target.begin(), rev_target.end());
    cout << "After STL Re-Reverse:  " << rev_target << endl; // Output: apna
    cout << "===================================\n";

    return 0;
}