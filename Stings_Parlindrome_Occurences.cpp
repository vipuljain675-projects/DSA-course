#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// =========================================================================
// ALGORITHM 1: OPTIMIZED TWO-POINTER PALINDROME VERIFIER
// =========================================================================
// Checks if a string reads the same forward and backward in O(n) time, O(1) space.
bool checkPalindrome(const string& s) {
    int start = 0;
    int end = s.length() - 1;

    while (start < end) {
        if (s[start] != s[end]) {
            return false; // Mismatch caught immediately
        }
        start++;
        end--;
    }
    return true; // Passed all boundary matches
}

int main() {
    // Fast I/O Optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "=== C++ STRINGS PART 2 ALGORITHMS MASTER ===\n\n";

    // =========================================================================
    // SECTION 1: PALINDROME TRACKING
    // =========================================================================
    cout << "--- 1. Palindrome Verification ---\n";
    string sample1 = "racecar";
    string sample2 = "apna";

    cout << "Is \"" << sample1 << "\" a Palindrome? -> " 
         << (checkPalindrome(sample1) ? "TRUE" : "FALSE") << "\n"; // TRUE
         
    cout << "Is \"" << sample2 << "\" a Palindrome? -> " 
         << (checkPalindrome(sample2) ? "TRUE" : "FALSE") << "\n\n"; // FALSE


    // =========================================================================
    // SECTION 2: REMOVE ALL OCCURRENCES OF SUBSTRING (LEETCODE 1910)
    // =========================================================================
    cout << "--- 2. Substring Elimination (In-Place Mutation) ---\n";
    string source_str = "daabcbaabcbc";
    string target_part = "abc";

    cout << "Original Layout: " << source_str << "\n";
    cout << "Target Substring:  \"" << target_part << "\"\n";

    // Shradha Ma'am's single-scan boundary check optimization loop
    // Evaluates presence and extracts position indexes simultaneously
    while (source_str.length() > 0 && source_str.find(target_part) < source_str.length()) {
        int target_index = source_str.find(target_part);
        source_str.erase(target_index, target_part.length());
    }

    cout << "Mutated Layout:  " << source_str << "\n"; // Output: dab
    cout << "===========================================\n";

    return 0;
}