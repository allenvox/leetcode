#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<double> convertTemperature(double celsius) {
    return vector<double>{celsius + 273.15, celsius * 1.8 + 32.0};
  }

  void output(double celsius) {
    vector<double> res = convertTemperature(celsius);
    cout << "Temperature at " << celsius << " Celsius converted in Kelvin is "
         << res[0] << " and converted in Fahrenheit is " << res[1] << endl;
  }
};

int main() {
  Solution s;
  s.output(36.5);
  s.output(122.11);
  s.output(0.0);
  s.output(-20.0);
  return 0;
}