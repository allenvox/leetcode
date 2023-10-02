#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> ans(nums.size(), 0);
    for (unsigned long i = 0; i < (unsigned long)n; i++) {
      ans[2 * i] = nums[i];
      ans[2 * i + 1] = nums[i + (unsigned long)n];
    }
    return ans;
  }

  void output(vector<int>& nums, int n) {
    cout << "{ ";
    for (int x : nums) cout << x << " ";
    cout << "} after shuffle will be { ";
    for (int x : shuffle(nums, n)) cout << x << " ";
    cout << '}' << endl;
  }
};

int main() {
  Solution s;
  vector<int> v1{2, 5, 1, 3, 4, 7};
  s.output(v1, v1.size() / 2);
  vector<int> v2{1, 2, 3, 4, 4, 3, 2, 1};
  s.output(v2, v2.size() / 2);
  vector<int> v3{1, 1, 2, 2};
  s.output(v3, v3.size() / 2);
  return 0;
}