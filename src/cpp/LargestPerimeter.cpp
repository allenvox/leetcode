#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int largestPerimeter(vector<int>& nums) {
    sort(nums.rbegin(), nums.rend());
    for (size_t i = 0; i < nums.size() - 2; ++i) {
      auto two_sides = nums[i + 1] + nums[i + 2];
      if (nums[i] < two_sides) {
        return nums[i] + two_sides;
      }
    }
    return 0;
  }

  void output(vector<int>& nums) {
    cout << "Largest perimeter of a triangle from side lengths { ";
    for (int x : nums) cout << x << " ";
    cout << "} is " << largestPerimeter(nums) << '\n';
  }
};

int main() {
  Solution s;
  vector<int> v1{1, 1, 4, 2, 1, 3};
  s.output(v1);
  vector<int> v2{1, 2, 3, 4, 5};
  s.output(v2);
  vector<int> v3{5, 1, 2, 3, 4};
  s.output(v3);
  return 0;
}