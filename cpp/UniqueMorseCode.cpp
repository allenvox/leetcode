#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> code{".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                        "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                        "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                        "...-", ".--",  "-..-", "-.--", "--.."};
    vector<string> morse;
    for (unsigned long i = 0; i < words.size(); i++) {
      string buff = "";
      for (char c : words[i]) {
        buff += code[(unsigned long)(c - 'a')];
      }
      bool alreadyIs = false;
      for (string x : morse) {
        if (x == buff) alreadyIs = true;
      }
      if (!alreadyIs) morse.push_back(buff);
    }
    return (int)morse.size();
  }

  void output(vector<string>& words) {
    cout << "There are " << uniqueMorseRepresentations(words)
         << " unique Morse Code representations of words { ";
    for (string x : words) cout << "\"" << x << "\" ";
    cout << "}" << endl;
  }
};

int main() {
  Solution s;
  vector<string> w1{"gin", "zen", "gig", "msg"};
  s.output(w1);
  vector<string> w2{"a"};
  s.output(w2);
  return 0;
}