#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isMonotonic(vector<int>& nums) {
    bool incr = true, decr = true;
    for (unsigned long i = 0; i < nums.size() - 1; i++) {
      if (nums[i] > nums[i + 1]) incr = false;
      if (nums[i] < nums[i + 1]) decr = false;
      if (!incr && !decr) return false;
    }
    return true;
  }

  void output(vector<int>& nums) {
    cout << "Array { ";
    for (int x : nums) cout << x << " ";
    cout << "} is ";
    if (!isMonotonic(nums)) cout << "not ";
    cout << "monotonic" << endl;
  }
};

int main() {
  Solution s;
  vector<int> v1{1, 1, 2, 4, 5};
  s.output(v1);
  vector<int> v2{3, 2, 2, 2, 0};
  s.output(v2);
  vector<int> v3{0, 1, 1, 2, 3, 0};
  s.output(v3);
  return 0;
}