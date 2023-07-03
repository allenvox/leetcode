#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> map1;
    stack<int> stack1;
    for (int i = nums2.size() - 1; i >= 0; i--) {  // from end to beginning
      // pop all elements to the right that are less than current num
      while (!stack1.empty() && stack1.top() < nums2[i]) {
        stack1.pop();
      }
      // if stack is empty -> no elements to the right greater than current, ans
      // = -1, if not empty -> ans = stack.top
      if (stack1.empty())
        map1[nums2[i]] = -1;
      else
        map1[nums2[i]] = stack1.top();
      // push current num to the stack (it's to the right to others)
      stack1.push(nums2[i]);
    }
    // write answers from unordered map to vector
    vector<int> ans;
    for (int x : nums1) {
      ans.push_back(map1[x]);
    }
    return ans;
  }

  void output(vector<int> &nums1, vector<int> &nums2) {
    cout << "For vector { ";
    for (int x : nums1) {
      cout << x << " ";
    }
    cout << "} next greater values from { ";
    for (int x : nums2) {
      cout << x << " ";
    }
    cout << "} will be { ";
    vector<int> ans = nextGreaterElement(nums1, nums2);
    for (int x : ans) {
      cout << x << " ";
    }
    cout << "}\n";
  }
};

int main() {
  Solution s;
  cout << "(-1 means that there is no greater element for num)\n";
  vector<int> v1{4, 1, 2}, v2{1, 3, 4, 2};
  s.output(v1, v2);
  vector<int> v3{2, 4}, v4{1, 2, 3, 4};
  s.output(v3, v4);
  return 0;
}