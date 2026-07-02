#include <iostream>
using namespace std;

int main() {

  // Pattern 1: Number Grid
  int n = 4;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cout << j << " ";
    }
    cout << endl;
  }

  // Visual separator between the two patterns
  cout << "-----------------" << endl;

  // Pattern 2: Character Grid
  int v = 4;
  for(int i = 1; i <= v; i++) {
    char ch = 'A'; // Resets to 'A' at the start of EVERY new row
    for(int j = 1; j <= v; j++) {
      cout << ch << " ";
      ch++;
    }
    cout << endl;
  }

  cout << "-----------------" << endl;

  int a = 5;
  int num1 = 1;
  for(int i = 1; i <= a; i++) {
    for(int j = 1; j <= a; j++) {
      cout << num1 << " ";
      num1++;
    }
    cout << endl;
  }

  cout << "-----------------" << endl;

  int b = 5;
  for(int i = 1; i <= b; i++) {
    for(int j = 1; j < i + 1; j++) {
      cout << "*" << " ";
    }
    cout << endl;
  }

  cout << "-----------------" << endl;

  int c = 4;
  for(int i = 0; i < c; i++) {
    for(int j = 0; j < i + 1; j++) {
      cout << "*";
    }
    cout << endl;
  }

  cout << "-----------------" << endl;

  int d = 4;
  for(int i = 0; i < d; i++) {
    for(int j = 0; j < i + 1; j++) {
      cout << i+1 << " "; 
    }
    cout << endl;
  }

  cout << "-----------------" << endl;

  int e = 5;
  for(int i = 1; i < e; i++) {
    for(int j = 1; j < i + 1; j++) {
      cout << j << " ";
    }
    cout << endl;
  }

  cout << "-----------------" << endl;

  // ================================================
  // PATTERN 8: Reverse Triangle Pattern (From Slide)
  // ================================================
  int f = 4; 
  for(int i = 0; i < f; i++) {
    for(int j = i + 1; j > 0; j--) {
      cout << j << " ";
    }
    cout << endl;
  }

  cout << "-----------------" << endl;

  // ================================================
  // PATTERN 9: Floyd's Triangle
  // ================================================
  int g = 4;
  int floydNum = 1;
  
  for(int i = 0; i < g; i++) {
    for(int j = 0; j < i + 1; j++) {
      cout << floydNum << " ";
      floydNum++;
    }
    cout << endl;
  }

  cout << "-----------------" << endl;

  // ================================================
  // PATTERN 10: Inverted Triangle with Spaces (From Slide)
  // ================================================
  int h = 4;
  for(int i = 0; i < h; i++) {
      
      // 1. Inner loop to print leading spaces
      for(int j = 0; j < i; j++) {
          cout << "  "; // Two spaces to match the character spacing
      }
      
      // 2. Inner loop to print the numbers
      for(int j = 0; j < h - i; j++) {
          cout << (i + 1) << " ";
      }
      
      cout << endl;
  }

  cout << "-----------------" << endl;

  // ================================================
  // PATTERN 11: Full Pyramid Pattern (From Slide)
  // ================================================
  int pyr = 9;
  for (int i = 0; i < pyr; i++) {
      
      // 1. Print leading spaces
      for (int j = 0; j < pyr - i - 1; j++) {
          cout << "  "; // Match character spacing
      }
      
      // 2. Print increasing numbers
      for (int j = 1; j <= i + 1; j++) {
          cout << j << " ";
      }
      
      // 3. Print decreasing numbers
      for (int j = i; j >= 1; j--) {
          cout << j << " ";
      }
      
      cout << endl;
  }

  cout << "-----------------" << endl;

  // ================================================
  // PATTERN 12: Hollow Diamond Pattern (From Slide)
  // ================================================
  int dim = 4;

  // --- PART 1: TOP HALF ---
  for (int i = 0; i < dim; i++) {
      // 1. Print outer spaces
      for (int j = 0; j < dim - i - 1; j++) {
          cout << " ";
      }

      // 2. Print first star
      cout << "*";

      // 3. Print inner spaces and second star
      if (i != 0) {
          for (int j = 0; j < 2 * i - 1; j++) {
              cout << " ";
          }
          cout << "*";
      }
      cout << endl;
  }

  // --- PART 2: BOTTOM HALF ---
  for (int i = dim - 2; i >= 0; i--) {
      // 1. Print outer spaces
      for (int j = 0; j < dim - i - 1; j++) {
          cout << " ";
      }

      // 2. Print first star
      cout << "*";

      // 3. Print inner spaces and second star
      if (i != 0) {
          for (int j = 0; j < 2 * i - 1; j++) {
              cout << " ";
          }
          cout << "*";
      }
      cout << endl;
  }

  cout << "-----------------" << endl;

  // ================================================
  // PATTERN 13: The Butterfly Pattern (From Slide)
  // ================================================
  int bfly = 4;

  // --- PART 1: TOP WINGS ---
  for (int i = 1; i <= bfly; i++) {
      // 1. Left Stars
      for (int j = 1; j <= i; j++) {
          cout << "*";
      }
      // 2. Center Blank Spaces
      for (int j = 1; j <= 2 * (bfly - i); j++) {
          cout << " ";
      }
      // 3. Right Stars
      for (int j = 1; j <= i; j++) {
          cout << "*";
      }
      cout << endl;
  }

  // --- PART 2: BOTTOM WINGS ---
  for (int i = bfly; i >= 1; i--) {
      // 1. Left Stars
      for (int j = 1; j <= i; j++) {
          cout << "*";
      }
      // 2. Center Blank Spaces
      for (int j = 1; j <= 2 * (bfly - i); j++) {
          cout << " ";
      }
      // 3. Right Stars
      for (int j = 1; j <= i; j++) {
          cout << "*";
      }
      cout << endl;
  }

  cout << "-----------------" << endl;

  return 0; // The single, absolute exit door at the very end
}

