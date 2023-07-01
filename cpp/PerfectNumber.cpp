#include <iostream>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for(int i = 1; i <= num / 2; i++) {
            if(num % i == 0) sum += i;
        }
        return sum == num;
    }

    void output(int num) {
        bool res = checkPerfectNumber(num);
        cout << num << " is ";
        if(!res) cout << "not ";
        cout << "a perfect number (number's divisors sum ";
        if(!res) cout << "!";
        cout << "= number)" << endl;
    }
};

int main() {
    Solution s;
    s.output(28);
    s.output(7);
    return 0;
}