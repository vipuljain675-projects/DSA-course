#include <iostream>
using namespace std;

int decimalToBinary(int dec) {
  int ans = 0, pow = 1;

  while (dec > 0) {
    int rem = dec % 2; // remainder will be either 0 or 1
    ans += rem * pow;
    pow *= 10;
    dec /= 2; // Integer division by 2 to move to the next bit
  }
  return ans;
}

int BinaryToDecimal(int bin) {
  int ans = 0, pow = 1;

  while (bin > 0) {
    int rem = bin % 10; // Get the last digit (0 or 1)
    ans += rem * pow; 
    pow *= 2;
    bin /= 10;  // Integer division by 10 to move to the next digit
  }
  return ans;
}

int main() {
  int decimalNumber;
  cout << "Enter a decimal number: ";
  cin >> decimalNumber;

  int BinaryNumber;
  cout << "Enter a binary number: ";
  cin >> BinaryNumber;

  int binaryNumber = decimalToBinary(decimalNumber);
  cout << "Binary representation: " << binaryNumber << endl;

  int decimalFromBinary = BinaryToDecimal(BinaryNumber);
  cout << "Decimal representation: " << decimalFromBinary << endl;

  return 0;
}

 