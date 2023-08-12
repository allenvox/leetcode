#include <climits>
#include <iostream>
using namespace std;

class Solution {
 public:
  int reverse(int x) {
    int ans = 0, sign = 1;
    if (x < 0) {
      if (x == INT_MIN) return 0;
      x *= -1;
      sign *= -1;
    }
    while (x > 0) {
      if (ans > INT_MAX / 10) return 0;
      ans *= 10;
      ans += x % 10;
      x /= 10;
    }
    return ans * sign;
  }

  void output(int x) {
    cout << x << " after reverse will be " << reverse(x) << endl;
  }
};

int main() {
  Solution s;
  s.output(-120);
  s.output(505);
  s.output(-59102);
  s.output(120000);
  return 0;
}