#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> umap;
    for (int i : nums) umap[i]++;
    for (auto i : umap)
      if (i.second > 1) return true;
    return false;
  }

  void output(vector<int>& nums) {
    cout << "Array { ";
    for (int x : nums) cout << x << " ";
    cout << "} ";
    if (containsDuplicate(nums))
      cout << "contains";
    else
      cout << "doesn't contain any";
    cout << " duplicates" << endl;
  }
};

int main() {
  Solution s;
  vector<int> v1{1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  s.output(v1);
  vector<int> v2{1, 2, 3, 4};
  s.output(v2);
  vector<int> v3{1, 2, 3, 1};
  s.output(v3);
  return 0;
}