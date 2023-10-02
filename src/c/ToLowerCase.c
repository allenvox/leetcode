#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *toLowerCase(char *s) {
  int size = strlen(s) + 1;
  char *buff = malloc(sizeof(char) * (unsigned long)size);
  for (int i = 0; s[i] != '\0'; i++) {
    buff[i] = tolower(s[i]);
  }
  buff[size - 1] = '\0';
  return buff;
}

void output(char *s) {
  char *res = toLowerCase(s);
  printf("\"%s\" to lower case is \"%s\"\n", s, res);
  free(res);
}

int main() {
  char s1[] = "Hello";
  output(s1);
  char s2[] = "here";
  output(s2);
  char s3[] = "LOVELY";
  output(s3);
  return 0;
}