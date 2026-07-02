#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// =====================================================
// CONCEPT 1: PRINT MATRIX
// =====================================================
void printMatrix(int matrix[][3], int rows, int cols) {

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

// =====================================================
// CONCEPT 2: ACCESS & MODIFY ELEMENTS
// =====================================================
void accessElements() {

    int matrix[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };

    cout << "Original Value at matrix[2][1] = "
         << matrix[2][1] << endl;

    matrix[2][1] = 18;

    cout << "Updated Value at matrix[2][1] = "
         << matrix[2][1] << endl;
}

// =====================================================
// CONCEPT 3: LINEAR SEARCH IN MATRIX
// =====================================================
bool linearSearch(int matrix[][3],
                  int rows,
                  int cols,
                  int key) {

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            if (matrix[i][j] == key) {
                return true;
            }
        }
    }

    return false;
}

// =====================================================
// CONCEPT 4: HOMEWORK 1
// FIND ROW & COLUMN OF KEY
// =====================================================
void findPosition(int matrix[][3],
                  int rows,
                  int cols,
                  int key) {

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            if (matrix[i][j] == key) {

                cout << "Key Found!" << endl;
                cout << "Row = " << i << endl;
                cout << "Column = " << j << endl;

                return;
            }
        }
    }

    cout << "Key Not Found!" << endl;
}

// =====================================================
// CONCEPT 5: MAXIMUM ROW SUM
// =====================================================
int maxRowSum(int matrix[][3],
              int rows,
              int cols) {

    int maxSum = 0;

    for (int i = 0; i < rows; i++) {

        int rowSum = 0;

        for (int j = 0; j < cols; j++) {

            rowSum += matrix[i][j];
        }

        maxSum = max(maxSum, rowSum);
    }

    return maxSum;
}

// =====================================================
// CONCEPT 6: HOMEWORK 2
// MAXIMUM COLUMN SUM
// =====================================================
int maxColumnSum(int matrix[][3],
                 int rows,
                 int cols) {

    int maxSum = 0;

    for (int j = 0; j < cols; j++) {

        int colSum = 0;

        for (int i = 0; i < rows; i++) {

            colSum += matrix[i][j];
        }

        maxSum = max(maxSum, colSum);
    }

    return maxSum;
}

// =====================================================
// CONCEPT 7: DIAGONAL SUM O(n²)
// Primary Diagonal + Secondary Diagonal
// =====================================================
int diagonalSumN2(int matrix[][3], int n) {

    int sum = 0;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            // Primary Diagonal
            if (i == j) {

                sum += matrix[i][j];
            }

            // Secondary Diagonal
            else if (j == n - i - 1) {

                sum += matrix[i][j];
            }
        }
    }

    return sum;
}


// =====================================================
// CONCEPT 8: DIAGONAL SUM O(n)
// Primary Diagonal + Secondary Diagonal
// =====================================================
int diagonalSumN(int matrix[][3], int n) {

    int sum = 0;

    for (int i = 0; i < n; i++) {

        // Primary Diagonal
        sum += matrix[i][i];

        // Secondary Diagonal
        if (i != n - i - 1) {

            sum += matrix[i][n - i - 1];
        }
    }

    return sum;
}

// =====================================================
// CONCEPT 9: 2D VECTORS
// =====================================================
void vectors2D() {

    vector<vector<int>> mat = {

        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "2D Vector:\n" << endl;

    // rows => mat.size()
    // cols => mat[i].size()

    for (int i = 0; i < mat.size(); i++) {

        for (int j = 0; j < mat[i].size(); j++) {

            cout << mat[i][j] << " ";
        }

        cout << endl;
    }
}


// =====================================================
// MAIN FUNCTION
// =====================================================
int main() {

    int matrix[3][3] = {

        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int rows = 3;
    int cols = 3;

    // -----------------------------
    // PRINT MATRIX
    // -----------------------------
    cout << "===== PRINT MATRIX =====" << endl;

    printMatrix(matrix, rows, cols);

    // -----------------------------
    // ACCESS ELEMENTS
    // -----------------------------
    cout << "\n===== ACCESS ELEMENTS =====" << endl;

    accessElements();

    // -----------------------------
    // LINEAR SEARCH
    // -----------------------------
    cout << "\n===== LINEAR SEARCH =====" << endl;

    int key = 8;

    if (linearSearch(matrix, rows, cols, key))
        cout << key << " Found" << endl;
    else
        cout << key << " Not Found" << endl;

    // -----------------------------
    // HOMEWORK 1
    // FIND POSITION
    // -----------------------------
    cout << "\n===== FIND POSITION OF KEY =====" << endl;

    findPosition(matrix, rows, cols, 8);

    // -----------------------------
    // MAXIMUM ROW SUM
    // -----------------------------
    cout << "\n===== MAXIMUM ROW SUM =====" << endl;

    cout << "Maximum Row Sum = "
         << maxRowSum(matrix, rows, cols)
         << endl;

    // -----------------------------
    // HOMEWORK 2
    // MAXIMUM COLUMN SUM
    // -----------------------------
    cout << "\n===== MAXIMUM COLUMN SUM =====" << endl;

    cout << "Maximum Column Sum = "
         << maxColumnSum(matrix, rows, cols)
         << endl;

    // -----------------------------
    // DIAGONAL SUM O(n²)
    // -----------------------------
    cout << "\n===== DIAGONAL SUM O(n²) =====" << endl;

    cout << diagonalSumN2(matrix, 3)
         << endl;

    // -----------------------------
    // DIAGONAL SUM O(n)
    // -----------------------------
    cout << "\n===== DIAGONAL SUM O(n) =====" << endl;

    cout << diagonalSumN(matrix, 3)
         << endl;

    // -----------------------------
    // 2D VECTORS
    // -----------------------------
    cout << "\n===== 2D VECTORS =====" << endl;

    vectors2D();

    return 0;
}