#include <stdio.h>

int countDigits(int num) {
  int copy = num, count = 0;
  for (int i = 0; copy != 0; i++) {
    int digit = copy % 10;
    copy /= 10;
    if (num % digit == 0) count++;
  }
  return count;
}

void output(int num) {
  printf("In num %d there are %d digits that divide it\n", num,
         countDigits(num));
}

int main() {
  output(7);
  output(121);
  output(1248);
  return 0;
}