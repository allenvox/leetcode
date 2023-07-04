#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int> &digits) {
    unsigned long n = digits.size() - 1;
    for (int i = n; i >= 0; i--) {
      if (digits[(unsigned long)i] == 9) {
        digits[(unsigned long)i] = 0;
      } else {
        digits[(unsigned long)i] += 1;
        return digits;
      }
    }
    digits.push_back(0);
    digits[0] = 1;
    return digits;
  }

  void output(vector<int> &digits) {
    for (unsigned long i = 0; i < digits.size(); i++) {
      cout << digits[i];
    }
    cout << " + 1 = ";
    digits = plusOne(digits);
    for (unsigned long i = 0; i < digits.size(); i++) {
      cout << digits[i];
    }
    cout << endl;
  }
};

int main() {
  Solution solution;
  vector<int> d1{1, 2, 3};
  solution.output(d1);
  vector<int> d2{9, 9};
  solution.output(d2);
  return 0;
}