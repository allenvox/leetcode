#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char *s) {
  int cur = strlen(s) - 1, len = 0;
  while (s[cur] == ' ' && cur >= 0) cur--;
  while (cur >= 0 && s[cur--] != ' ') len++;
  return len;
}

void output(char *s) {
  printf("Length of last word in phrase \"%s\" is %d\n", s,
         lengthOfLastWord(s));
}

int main() {
  output("Hello World");
  output("   fly me   to   the moon  ");
  output("luffy is still joyboy");
  return 0;
}