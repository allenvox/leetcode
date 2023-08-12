#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    for (int x : nums1) {
      if (count(nums2.begin(), nums2.end(), x) > 0 &&
          count(result.begin(), result.end(), x) == 0)
        result.push_back(x);
    }
    return result;
  }

  void output(vector<int>& nums1, vector<int>& nums2) {
    cout << "Intersection of arrays { ";
    for (int x : nums1) cout << x << " ";
    cout << "} and { ";
    for (int x : nums2) cout << x << " ";
    cout << "} is { ";
    for (int x : intersection(nums1, nums2)) cout << x << " ";
    cout << "}" << endl;
  }
};

int main() {
  Solution s;
  vector<int> v1{1, 2, 2, 1}, v2{2, 2};
  s.output(v1, v2);
  vector<int> v3{4, 9, 5}, v4{9, 4, 9, 8, 4};
  s.output(v3, v4);
  return 0;
}