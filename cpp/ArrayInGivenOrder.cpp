#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    vector<int> res;
    for (unsigned long i = 0; i < index.size(); i++) {
      res.insert(res.begin() + index[i], nums[i]);
    }
    return res;
  }

  void output(vector<int>& nums, vector<int>& index) {
    cout << "Array { ";
    for (int x : nums) cout << x << " ";
    cout << "} after inserting elements on indexes { ";
    for (int x : index) cout << x << " ";
    cout << "} looks like { ";
    vector<int> res = createTargetArray(nums, index);
    for (int x : res) cout << x << " ";
    cout << "}" << endl;
  }
};

int main() {
  Solution s;
  vector<int> n1{0, 1, 2, 3, 4}, i1{0, 1, 2, 2, 1};
  s.output(n1, i1);
  vector<int> n2{1, 2, 3, 4, 0}, i2{0, 1, 2, 3, 0};
  s.output(n2, i2);
  return 0;
}