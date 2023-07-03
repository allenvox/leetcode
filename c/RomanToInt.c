#include <stdio.h>
#include <string.h>

int decimalNum(char r) {
  switch (r) {
    case 'M':
      return 1000;
    case 'D':
      return 500;
    case 'C':
      return 100;
    case 'L':
      return 50;
    case 'X':
      return 10;
    case 'V':
      return 5;
    case 'I':
      return 1;
    default:
      return -1;
  }
}

int romanToInt(char *s) {
  int res = 0, len = strlen(s);
  for (int i = 0; i < len; i++) {
    if (decimalNum(s[i]) < decimalNum(s[i + 1])) {
      res -= decimalNum(s[i]);
    } else {
      res += decimalNum(s[i]);
    }
  }
  return res;
}

void output(char *s) {
  printf("Roman number \"%s\" = %d decimal\n", s, romanToInt(s));
}

int main() {
  output("III");
  output("LVIII");
  output("MCMXCIV");
  return 0;
}