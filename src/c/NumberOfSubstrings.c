#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numOfStrings(char **patterns, int patternsSize, char *word) {
  int res = 0;
  for (int i = 0; i < patternsSize; i++) {
    if (strstr(word, patterns[i]) != NULL) {
      res += 1;
    }
  }
  return res;
}

void output(char **patterns, int patternsSize, char *word) {
  printf("In a word \"%s\" appear %d substrings from array { ", word,
         numOfStrings(patterns, patternsSize, word));
  for (int i = 0; i < patternsSize; i++) {
    printf("\"%s\" ", patterns[i]);
  }
  printf("}\n");
}

int main() {
  int size = 4;
  char **p1 = malloc(sizeof(char *) * (unsigned long)size);
  p1[0] = "a";
  p1[1] = "abc";
  p1[2] = "bc";
  p1[3] = "d";
  output(p1, 4, "abc");
  free(p1);

  size = 3;
  char **p2 = malloc(sizeof(char *) * (unsigned long)size);
  p2[0] = "a";
  p2[1] = "b";
  p2[2] = "c";
  output(p2, 3, "aaaaabbbbb");
  free(p2);

  char **p3 = malloc(sizeof(char *) * (unsigned long)size);
  p3[0] = "a";
  p3[1] = "a";
  p3[2] = "a";
  output(p3, 3, "ab");
  free(p3);
  return 0;
}