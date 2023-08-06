#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int thirdMax(vector<int>& nums) {
    int firstmax = *max_element(nums.begin(), nums.end());
    if (nums.size() < 3) return firstmax;
    int secondmax = INT_MIN, thirdmax = INT_MIN;
    for (int x : nums) {
      if (x > secondmax && x != firstmax) secondmax = x;
    }
    if (secondmax == INT_MIN) return firstmax;
    bool isINTMIN = false;
    for (int x : nums) {
      if ((x > thirdmax || x == INT_MIN) && x != firstmax && x != secondmax) {
        thirdmax = x;
        if (x == INT_MIN) isINTMIN = true;
      }
    }
    if (thirdmax == INT_MIN && !isINTMIN) return firstmax;
    return thirdmax;
  }

  void output(vector<int>& nums) {
    cout << "Third maximum in array { ";
    for (int x : nums) cout << x << " ";
    cout << "} is " << thirdMax(nums) << endl;
  }
};

int main() {
  Solution s;
  vector<int> v1{3, 2, 1};
  s.output(v1);
  vector<int> v2{2, 0};
  s.output(v2);
  vector<int> v3{2, 3, 2, 1};
  s.output(v3);
  vector<int> v4{3, 2, 3, INT_MIN};
  s.output(v4);
  return 0;
}