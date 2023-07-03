#include <stdio.h>

int numJewelsInStones(char *jewels, char *stones) {
  int result = 0;
  for (int i = 0; stones[i] != '\0'; i++) {
    for (int j = 0; jewels[j] != '\0'; j++) {
      if (stones[i] == jewels[j]) {
        result += 1;
        break;
      }
    }
  }
  return result;
}

void output(char *jewels, char *stones) {
  printf("In stones \"%s\" are %d jewels (\"%s\")\n", stones,
         numJewelsInStones(jewels, stones), jewels);
}

int main() {
  output("aA", "aAAbbbb");
  output("z", "ZZ");
  return 0;
}