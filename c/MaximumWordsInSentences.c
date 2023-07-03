#include <stdio.h>
#include <stdlib.h>

int mostWordsFound(char **sentences, int sentencesSize) {
  int max = 0;
  for (int i = 0; i < sentencesSize; i++) {
    int local = 0;
    for (int j = 0; sentences[i][j] != '\0'; j++) {
      if (sentences[i][j] == ' ') {
        local++;
      }
    }
    if (local > max) max = local;
  }
  return max + 1;
}

void output(char **sentences, int sentencesSize) {
  printf("There are %d sentences:\n", sentencesSize);
  for (int i = 0; i < sentencesSize; i++) {
    printf("%d. %s\n", i + 1, sentences[i]);
  }
  printf("The maximum number of words is %d\n",
         mostWordsFound(sentences, sentencesSize));
}

int main() {
  int size = 3;
  char **s1 = malloc(sizeof(char *) * size);
  s1[0] = "alice and bob love leetcode";
  s1[1] = "i think so too";
  s1[2] = "this is great thanks very much";
  output(s1, 3);
  printf("\n");
  char **s2 = malloc(sizeof(char *) * size);
  s2[0] = "please wait";
  s2[1] = "continue to fight";
  s2[2] = "continue to win";
  output(s2, 3);
  return 0;
}