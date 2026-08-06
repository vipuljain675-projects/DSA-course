#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> st;   // {price, span}

public:
    // Constructor
    StockSpanner() {

    }

    // Returns the span of the current stock price
    int next(int price) {

        int span = 1;

        // Merge all previous prices less than or equal to current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        // Push current price and its span
        st.push({price, span});

        return span;
    }

    // Display stack (for understanding only)
    void display() {
        stack<pair<int, int>> temp = st;

        cout << "\nCurrent Stack (Top -> Bottom)\n";
        while (!temp.empty()) {
            cout << "(" << temp.top().first << ", "
                 << temp.top().second << ")\n";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {

    StockSpanner sp;

    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    cout << "Prices : ";
    for (int price : prices)
        cout << price << " ";
    cout << "\n\n";

    cout << "Price\tSpan\n";
    cout << "-----------------\n";

    for (int price : prices) {
        int span = sp.next(price);

        cout << price << "\t" << span << endl;

        // Uncomment if you want to see the stack after every insertion
        // sp.display();
    }

    return 0;
}