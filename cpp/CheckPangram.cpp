#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> letters(26);
        for(unsigned long i = 0; i < sentence.size(); i++) {
            letters[(unsigned long)(sentence[i] - 'a')] = 1;
        }
        for(unsigned long i = 0; i < 26; i++) {
            if(letters[i] == 0) return false;
        }
        return true;
    }

    void output(string sentence) {
        cout << "String \"" << sentence << "\" is ";
        if(!checkIfPangram(sentence)) cout << "not ";
        cout << "a pangram" << endl;
    }
};

int main() {
    Solution s;
    cout << "Pangram is a sentence that contains every letter of alphabet at least once" << endl;
    s.output("thequickbrownfoxjumpsoverthelazydog");
    s.output("leetcode");
    return 0;
}