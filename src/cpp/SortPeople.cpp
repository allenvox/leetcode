#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  static bool comparePeople(pair<string, int>& a, pair<string, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
  }

  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    vector<pair<string, int>> v;
    for (unsigned long i = 0; i < names.size(); i++)
      v.push_back({names[i], heights[i]});
    sort(v.begin(), v.end(), comparePeople);
    vector<string> ans;
    for (unsigned long i = 0; i < names.size(); i++) ans.push_back(v[i].first);
    return ans;
  }

  void output(vector<string>& names, vector<int>& heights) {
    cout << "Array of people's names and heights { ";
    for (unsigned long i = 0; i < names.size(); i++)
      cout << names[i] << ':' << heights[i] << " ";
    cout << "} after sorting by height: { ";
    for (string x : sortPeople(names, heights)) cout << x << ' ';
    cout << '}' << endl;
  }
};

int main() {
  Solution s;
  vector<string> n1{"Mary", "John", "Emma"};
  vector<int> h1{180, 165, 170};
  s.output(n1, h1);
  vector<string> n2{"Alice", "Bob", "Bob"};
  vector<int> h2{155, 185, 150};
  s.output(n2, h2);
  return 0;
}