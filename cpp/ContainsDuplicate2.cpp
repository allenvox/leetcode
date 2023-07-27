#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> umap;
    for (unsigned long i = 0; i < nums.size(); i++) {
      if (umap.count(nums[i]) && abs((int)umap[nums[i]] - (int)i) <= k)
        return true;
      umap[nums[i]] = i;
    }
    return false;
  }

  void output(vector<int>& nums, int k) {
    cout << "Array { ";
    for (int x : nums) cout << x << " ";
    cout << "} ";
    if (containsNearbyDuplicate(nums, k))
      cout << "contains";
    else
      cout << "doesn't contain any";
    cout << " duplicates in near of " << k << " elements" << endl;
  }
};

int main() {
  Solution s;
  vector<int> v1{1, 0, 1, 1};
  s.output(v1, 1);
  vector<int> v2{1, 2, 3, 1, 2, 3};
  s.output(v2, 2);
  return 0;
}