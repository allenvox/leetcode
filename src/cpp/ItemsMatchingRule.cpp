#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int countMatches(vector<vector<string>>& items, string ruleKey,
                   string ruleValue) {
    unsigned long target;
    if (ruleKey == "type")
      target = 0;
    else if (ruleKey == "color")
      target = 1;
    else
      target = 2;

    int count = 0;
    for (vector<string> i : items)
      if (i[target] == ruleValue) count++;
    return count;
  }

  void output(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    cout << "In array { ";
    for (vector<string> i : items) {
      cout << "{ ";
      for (string x : i) cout << x << " ";
      cout << "} ";
    }
    cout << "} there are " << countMatches(items, ruleKey, ruleValue)
         << " items matching \"" << ruleKey << "\" rule \"" << ruleValue << "\""
         << endl;
  }
};

int main() {
  Solution s;
  vector<vector<string>> i{{"phone", "blue", "pixel"},
                           {"computer", "silver", "lenovo"},
                           {"phone", "gold", "iphone"}};
  string rK1 = "color", rV1 = "silver";
  s.output(i, rK1, rV1);
  string rK2 = "type", rV2 = "phone";
  s.output(i, rK2, rV2);
  return 0;
}