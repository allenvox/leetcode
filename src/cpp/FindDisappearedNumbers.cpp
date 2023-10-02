#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;
    for (unsigned long i = 0; i < nums.size(); i++) {
      if (nums[(unsigned long)abs(nums[i]) - 1] > 0)
        nums[(unsigned long)abs(nums[i]) - 1] *= -1;
    }
    for (unsigned long i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) ans.push_back(i + 1);
    }
    return ans;
  }

  void output(vector<int>& nums) {
    cout << "Disappeared numbers from array { ";
    for (int x : nums) cout << x << " ";
    cout << "} are { ";
    for (int x : findDisappearedNumbers(nums)) cout << x << " ";
    cout << "}" << endl;
  }
};

int main() {
  Solution s;
  vector<int> v1{4, 3, 2, 7, 8, 2, 3, 1};
  s.output(v1);
  vector<int> v2{1, 1};
  s.output(v2);
  return 0;
}