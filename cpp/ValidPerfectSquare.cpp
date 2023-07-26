#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isPerfectSquare(int num) {
    vector<int> squares{1};
    for (int i = 2; i < sqrt(INT_MAX); i++) {
      squares.push_back(i * i);
    }
    if (count(squares.begin(), squares.end(), num)) return true;
    return false;
  }

  void output(int num) {
    cout << num << " is ";
    if (!isPerfectSquare(num)) cout << "not ";
    cout << "a perfect square" << endl;
  }
};

int main() {
  Solution s;
  s.output(1);
  s.output(6);
  s.output(10000);
  s.output(256);
  s.output(91919);
  return 0;
}