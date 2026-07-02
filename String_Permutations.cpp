#include <iostream>
#include <string>
using namespace std;

bool isFreqSame(int freq1[26], int freq2[26]) {

    for (int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            return false;
        }
    }

    return true;
}

bool checkInclusion(string s1, string s2) {

    int freq[26] = {0};

    // Store frequency of s1
    for (int i = 0; i < s1.length(); i++) {
        freq[s1[i] - 'a']++;
    }

    int windSize = s1.length();

    // Check every possible window in s2
    for (int i = 0; i < s2.length(); i++) {

        int windIdx = 0;
        int idx = i;

        int windFreq[26] = {0};

        while (windIdx < windSize && idx < s2.length()) {

            windFreq[s2[idx] - 'a']++;

            windIdx++;
            idx++;
        }

        if (isFreqSame(freq, windFreq)) {
            return true;
        }
    }

    return false;
}

int main() {

    string s1, s2;

    cout << "Enter s1: ";
    cin >> s1;

    cout << "Enter s2: ";
    cin >> s2;

    if (checkInclusion(s1, s2)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}