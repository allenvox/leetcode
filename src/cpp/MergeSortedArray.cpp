#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for (unsigned long i = (unsigned long)m; (int)i < m + n; i++) {
      nums1[i] = nums2[i - (unsigned long)m];
    }
    sort(nums1.begin(), nums1.end());
  }

  void output(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    cout << "Arrays { ";
    for (unsigned long i = 0; (int)i < m; i++) cout << nums1[i] << " ";
    cout << "} and { ";
    for (int x : nums2) cout << x << " ";
    cout << "} after merge will become { ";
    merge(nums1, m, nums2, n);
    for (int x : nums1) cout << x << " ";
    cout << "}" << endl;
  }
};

int main() {
  Solution s;
  vector<int> v1{1, 2, 3, 0, 0, 0}, v2{2, 5, 6};
  s.output(v1, 3, v2, 3);
  vector<int> v3{1}, v4{};
  s.output(v3, 1, v4, 0);
  return 0;
}