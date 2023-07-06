#include <iostream>
using namespace std;

class Solution {
 public:
  unsigned int chunks[16] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

  uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    for (int i = 0; i < 8; i++) {
      ans <<= 4;
      unsigned long cur = n & 0b1111;
      ans |= chunks[cur];
      n >>= 4;
    }
    return ans;
  }

  void printbytes(uint32_t byte) {
    for (int i = 31; i >= 0; i--) {
      uint32_t b = byte >> i;
      if (b & 1)
        cout << '1';
      else
        cout << '0';
    }
  }

  void output(uint32_t n) {
    cout << "reverseBits(";
    printbytes(n);
    cout << ") (" << n << ") = ";
    uint32_t reverse = reverseBits(n);
    printbytes(reverse);
    cout << " (" << reverse << ")" << endl;
  }
};

int main() {
  Solution s;
  s.output(0b00000010100101000001111010011100);
  s.output(0b11111111111111111111111111111101);
  return 0;
}