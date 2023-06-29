#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size() - 1;
        for(int i = n; i >= 0; i--) {
            if(digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i] += 1;
                return digits;
            }
        }
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }

    void output(vector<int> &digits) {
        for(int i = 0; i < (int)digits.size(); i++) {
            cout << digits[i];
        }
        cout << " + 1 = ";
        digits = plusOne(digits);
        for(int i = 0; i < (int)digits.size(); i++) {
            cout << digits[i];
        }
        cout << endl;
    }
};

int main() {
    Solution solution;
    vector<int> d1{1, 2, 3};
    solution.output(d1);
    vector<int> d2{9, 9};
    solution.output(d2);
    return 0;
}