#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isPalindrome(char *s) {
  int size = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    if (isalpha(s[i]) || isdigit(s[i])) size++;
  }
  char *letters = malloc(sizeof(char) * (unsigned long)size);
  int cur = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    if (isalpha(s[i]) || isdigit(s[i])) letters[cur++] = tolower(s[i]);
  }
  for (int i = 0; i < size / 2; i++) {
    if (letters[i] != letters[size - i - 1]) {
      free(letters);
      return false;
    }
  }
  free(letters);
  return true;
}

void output(char *s) {
  printf("Phrase \"%s\" is ", s);
  if (!isPalindrome(s)) printf("not ");
  printf("a valid alphanumeric palindrome\n");
}

int main() {
  output("A man, a plan, a canal: Panama");
  output("race a car");
  output(" ");
  return 0;
}