#include <stdio.h>

char nextGreatestLetter(char* letters, int lettersSize, char target) {
  for (int i = 0; i < lettersSize; i++) {
    if (letters[i] > target) {
      return letters[i];
    }
  }
  return letters[0];
}

void output(char* letters, int lettersSize, char target) {
  printf(
      "The smallest char lexicographically greater than '%c' in array \"%s\" "
      "is '%c'\n",
      target, letters, nextGreatestLetter(letters, lettersSize, target));
}

int main() {
  char l1[] = "cfj";
  output(l1, 3, 'a');
  char l2[] = "xxyy";
  output(l2, 4, 'z');
  return 0;
}