#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> umap;
    vector<int> ans;
    for (unsigned long i = 0; i < nums1.size(); i++) umap[nums1[i]]++;
    for (unsigned long i = 0; i < nums2.size(); i++) {
      if (umap[nums2[i]] > 0) {
        ans.push_back(nums2[i]);
        umap[nums2[i]]--;
      }
    }
    return ans;
  }

  void output(vector<int>& nums1, vector<int>& nums2) {
    cout << "Intersection of arrays { ";
    for (int x : nums1) cout << x << " ";
    cout << "} and { ";
    for (int x : nums2) cout << x << " ";
    cout << "} is { ";
    for (int x : intersect(nums1, nums2)) cout << x << " ";
    cout << "}" << endl;
  }
};

int main() {
  Solution s;
  vector<int> v1{1, 2, 2, 1}, v2{2, 2};
  s.output(v1, v2);
  vector<int> v3{4, 9, 5}, v4{9, 4, 9, 9, 5, 1};
  s.output(v3, v4);
  vector<int> v5{1, 0}, v6{};
  s.output(v5, v6);
  return 0;
}