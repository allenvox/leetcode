#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *interpret(char *command) {
  char *buff = (char *)calloc(strlen(command) + 1, 1);
  if (!buff) {
    return NULL;
  }
  int curchar = 0;
  for (int i = 0; command[i] != '\0'; i++) {
    if (command[i] == 'G') {
      buff[curchar] = 'G';
      curchar++;
    } else if (command[i] == '(') {
      if (command[i + 1] == ')') {
        buff[curchar] = 'o';
        curchar++;
      } else {
        buff[curchar] = 'a';
        buff[curchar + 1] = 'l';
        curchar += 2;
      }
    }
  }
  return buff;
}

void output(char *command) {
  printf("%s\t--(parser)->\t%s\n", command, interpret(command));
}

int main() {
  output("G()(al)");
  output("G()()()()(al)");
  output("(al)G(al)()()G");
  return 0;
}