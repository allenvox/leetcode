#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    for (unsigned long i = 2; i < cost.size(); i++)
      cost[i] += min(cost[i - 1], cost[i - 2]);
    return min(cost[cost.size() - 1], cost[cost.size() - 2]);
  }

  void output(vector<int>& cost) {
    cout << "Minimum cost of climbing array of stairs { ";
    for (int x : cost) cout << x << " ";
    cout << "} equals to " << minCostClimbingStairs(cost) << endl;
  }
};

int main() {
  Solution s;
  vector<int> v1{10, 15, 20};
  s.output(v1);
  vector<int> v2{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  s.output(v2);
  return 0;
}