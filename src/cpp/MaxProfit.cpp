#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int maxProfit = 0, minPrice = 10001;
    for (int x : prices) {
      minPrice = min(minPrice, x);
      maxProfit = max(maxProfit, x - minPrice);
    }
    return maxProfit;
  }

  void output(vector<int> &prices) {
    cout << "Max profit from stock prices by days { ";
    for (int x : prices) cout << x << " ";
    cout << "} equals to " << maxProfit(prices) << endl;
  }
};

int main() {
  Solution s;
  vector<int> v1{7, 1, 5, 3, 6, 4};
  s.output(v1);
  vector<int> v2{7, 6, 4, 3, 1};
  s.output(v2);
  return 0;
}