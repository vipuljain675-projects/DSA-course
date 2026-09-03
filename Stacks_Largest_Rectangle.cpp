#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// ============================================================
// Solution 1: Brute Force - O(n^2)
// ============================================================

class BruteForceSolution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        int maxArea = 0;

        // Fix the starting index
        for (int i = 0; i < n; i++) {

            int minHeight = heights[i];

            // Extend the rectangle to the right
            for (int j = i; j < n; j++) {

                // Minimum height of the current range [i...j]
                minHeight = min(minHeight, heights[j]);

                int width = j - i + 1;
                int area = minHeight * width;

                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};


// ============================================================
// Solution 2: Monotonic Stack - O(n)
// ============================================================

class StackSolution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {

            while (!st.empty() &&
                   (i == n || heights[st.top()] >= heights[i])) {

                int height = heights[st.top()];
                st.pop();

                int width;

                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                int area = height * width;

                maxArea = max(maxArea, area);
            }

            // Important: don't push n because n is outside
            // the valid index range.
            if (i < n)
                st.push(i);
        }

        return maxArea;
    }
};


// ============================================================
// Main
// ============================================================

int main() {

    vector<int> heights = {2, 1, 5, 6, 2, 3};

    BruteForceSolution brute;
    StackSolution optimal;

    cout << "Array: ";

    for (int x : heights)
        cout << x << " ";

    cout << "\n\n";

    cout << "Brute Force O(n^2): "
         << brute.largestRectangleArea(heights);

    cout << "\n";

    cout << "Monotonic Stack O(n): "
         << optimal.largestRectangleArea(heights);

    cout << endl;

    return 0;
}



 