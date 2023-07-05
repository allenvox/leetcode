#include <stdio.h>
#include <stdlib.h>

int countSeniors(char **details, int detailsSize) {
  int count = 0;
  for (int i = 0; i < detailsSize; i++) {
    if (details[i][11] > '6') {
      count++;
    } else if (details[i][11] == '6' && details[i][12] > '0')
      count++;
  }
  return count;
}

void output(char **details, int detailsSize) {
  printf("In array of citizens { ");
  for (int i = 0; i < detailsSize; i++) {
    printf("\"%s\" ", details[i]);
  }
  printf("} there are %d seniors\n", countSeniors(details, detailsSize));
}

int main() {
  int size = 3;
  char **d1 = malloc(sizeof(char *) * (unsigned long)size);
  d1[0] = "7868190130M7522";
  d1[1] = "5303914400F9211";
  d1[2] = "9273338290F4010";
  output(d1, size);
  free(d1);
  size = 2;
  char **d2 = malloc(sizeof(char *) * (unsigned long)size);
  d2[0] = "1313579440F2036";
  d2[1] = "2921522980M5644";
  output(d2, size);
  free(d2);
  return 0;
}