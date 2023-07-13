#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string w1 = "", w2 = "";
    for (string x : word1) w1 += x;
    for (string x : word2) w2 += x;
    if (w1 == w2) return true;
    return false;
  }

  void output(vector<string>& word1, vector<string>& word2) {
    string w1 = "", w2 = "";
    for (string x : word1) w1 += x;
    for (string x : word2) w2 += x;
    cout << "Concatenated string arrays \"" << w1 << "\" and \"" << w2
         << "\" are ";
    if (!arrayStringsAreEqual(word1, word2)) cout << "not ";
    cout << "equal" << endl;
  }
};

int main() {
  Solution s;
  vector<string> w1{"ab", "c"}, w2{"a", "bc"};
  s.output(w1, w2);
  vector<string> w3{"abc", "d", "efg"}, w4{"abcdefg"};
  s.output(w3, w4);
  vector<string> w5{"a", "cb"}, w6{"abc"};
  s.output(w5, w6);
  return 0;
}