#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& nums) {
    vector<int> ans;
    for (int x : nums) {
      if (x % 2)
        ans.push_back(x);
      else
        ans.insert(ans.begin(), x);
    }
    return ans;
  }

  void output(vector<int>& nums) {
    cout << "Array { ";
    for (int x : nums) cout << x << " ";
    cout << "} sorted by parity: { ";
    for (int x : sortArrayByParity(nums)) cout << x << " ";
    cout << "}" << endl;
  }
};

int main() {
  Solution s;
  vector<int> v1{3, 1, 2, 4};
  s.output(v1);
  vector<int> v2{1, 1, 6, 8, 3, 1, 2, 4};
  s.output(v2);
  return 0;
}