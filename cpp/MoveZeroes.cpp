#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    stable_partition(nums.begin(), nums.end(), [](int n) { return n != 0; });
  }

  void output(vector<int>& nums) {
    cout << "Array { ";
    for (int x : nums) cout << x << " ";
    cout << "} after moving zeroes to the right equals to { ";
    moveZeroes(nums);
    for (int x : nums) cout << x << " ";
    cout << "}" << endl;
  }
};

int main() {
  Solution s;
  vector<int> v1{0, 1, 0, 3, 12};
  s.output(v1);
  vector<int> v2{0};
  s.output(v2);
  return 0;
}