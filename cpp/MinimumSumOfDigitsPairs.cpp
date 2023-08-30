#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumSum(int num) {
    vector<int> arr(4, 0);
    for (unsigned long i = 0; i < 4; i++) {
      arr[i] = num % 10;
      num = num / 10;
    }
    sort(arr.begin(), arr.end());
    int first = 10 * arr[0] + arr[2], second = 10 * arr[1] + arr[3];
    return first + second;
  }

  void output(int num) {
    cout << "Minimum sum of digits' pairs in number " << num << " is "
         << minimumSum(num) << endl;
  }
};

int main() {
  Solution s;
  s.output(2986);
  s.output(4009);
  s.output(6123);
  return 0;
}