#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize) {
  char *prefix = malloc(sizeof(char) * 200);
  strcpy(prefix, strs[0]);
  for (int i = 1; i < strsSize; i++) {
    for (int j = 0; prefix[j] != '\0'; j++) {
      if (prefix[j] != strs[i][j]) {
        prefix[j] = '\0';
        break;
      }
    }
  }
  return prefix;
}

void output(char **strs, int strsSize) {
  printf("Common prefix of { ");
  for (int i = 0; i < strsSize; i++) {
    printf("\"%s\" ", strs[i]);
  }
  char *res = longestCommonPrefix(strs, strsSize);
  printf("} is \"%s\"\n", res);
  free(res);
}

int main() {
  char **strs1 = malloc(sizeof(char) * 3 * 10);
  strs1[0] = "flower";
  strs1[1] = "flow";
  strs1[2] = "flight";
  output(strs1, 3);
  free(strs1);

  char **strs2 = malloc(sizeof(char) * 3 * 10);
  strs2[0] = "dog";
  strs2[1] = "racecar";
  strs2[2] = "car";
  output(strs2, 3);
  free(strs2);
  return 0;
}