#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 private:
  int translate_int(int num, vector<int>& mapping) {
    if (num == 0) {
      return mapping[0];
    }
    int res = 0;
    int multiplier = 1;
    while (num > 0) {
      int digit = num % 10;
      num /= 10;
      res += mapping[static_cast<size_t>(digit)] * multiplier;
      multiplier *= 10;
    }
    return res;
  }

 public:
  vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    unordered_map<int, int> num_mapping;
    for (int num : nums) {
      if (num_mapping.find(num) == num_mapping.end()) {
        num_mapping[num] = translate_int(num, mapping);
      }
    }

    sort(nums.begin(), nums.end(),
         [&](int a, int b) { return num_mapping[a] < num_mapping[b]; });

    return nums;
  }

  void output(vector<int>& mapping, vector<int>& nums) {
    cout << "Mapping: { ";
    for (auto m : mapping) cout << m << ' ';
    cout << "}, nums: { ";
    for (auto n : nums) cout << n << ' ';
    cout << "}, result sorted by mapped nums: { ";
    for (auto n : sortJumbled(mapping, nums)) cout << n << ' ';
    cout << "}\n";
  }
};

int main() {
  Solution s;
  vector<int> m1{8, 9, 4, 0, 2, 1, 3, 5, 7, 6};
  vector<int> n1{991, 338, 38};
  s.output(m1, n1);

  vector<int> m2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> n2{789, 456, 123};
  s.output(m2, n2);
  return 0;
}