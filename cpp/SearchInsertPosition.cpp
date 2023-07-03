#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int searchInsert(vector<int> &nums, int target) {
    for (int i = 0; i < (int)nums.size(); i++) {
      if (nums[i] == target || nums[i] > target) return i;
    }
    return nums.size();
  }

  void output(vector<int> &nums, int target) {
    cout << "In 'nums' vector { ";
    for (int x : nums) {
      cout << x << " ";
    }
    cout << "} target num " << target << " should be inserted at nums["
         << searchInsert(nums, target) << "]" << endl;
  }
};

int main() {
  Solution s;
  vector<int> v{1, 3, 5, 6};
  s.output(v, 5);
  s.output(v, 2);
  s.output(v, 7);
  return 0;
}