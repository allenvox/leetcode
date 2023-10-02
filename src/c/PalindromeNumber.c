#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPalindrome(int x) {
  char x_str[32];
  sprintf(x_str, "%d", x);
  int l = strlen(x_str);
  for (int i = 0; i < l / 2; i++) {
    if (x_str[i] != x_str[l - i - 1]) {
      // printf("entered false while comparing %c and %c\n", x_str[i], x_str[l -
      // i - 1]);
      return false;
    }
  }
  return true;
}

int main() {
  int x = 101, y = 1012;
  printf("is x palindrome? - %s\nis y palindrome? - %s\n",
         isPalindrome(x) ? "true" : "false",
         isPalindrome(y) ? "true" : "false");
  return 0;
}