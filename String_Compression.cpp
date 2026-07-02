#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();
        int idx = 0;

        for (int i = 0; i < n; ) {

            char ch = chars[i];
            int count = 0;

            // Count consecutive occurrences
            while (i < n && chars[i] == ch) {
                count++;
                i++;
            }

            // Store character
            chars[idx++] = ch;

            // Store count if greater than 1
            if (count > 1) {

                string str = to_string(count);

                for (char dig : str) {
                    chars[idx++] = dig;
                }
            }
        }

        return idx;
    }
};

int main() {

    vector<char> chars = {'a','a','b','b','c','c','c'};

    Solution obj;

    int len = obj.compress(chars);

    cout << "Compressed Length = " << len << endl;

    cout << "Compressed Array = ";

    for (int i = 0; i < len; i++) {
        cout << chars[i] << " ";
    }

    cout << endl;

    return 0;
}