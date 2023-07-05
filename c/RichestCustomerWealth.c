#include <stdio.h>
#include <stdlib.h>

int maximumWealth(int **accounts, int accountsSize, int *accountsColSize) {
  int max = 0;
  for (int i = 0; i < accountsSize; i++) {
    int local = 0;
    for (int j = 0; j < *accountsColSize; j++) {
      local += accounts[i][j];
    }
    if (local > max) max = local;
  }
  return max;
}

void output(int **accounts, int accountsSize, int *accountsColSize) {
  for (int i = 0; i < accountsSize; i++) {
    int local = 0;
    for (int j = 0; j < *accountsColSize; j++) {
      local += accounts[i][j];
    }
    printf("Customer %d has wealth = %d\n", i + 1, local);
  }
  printf("Richest customer wealth = %d\n",
         maximumWealth(accounts, accountsSize, accountsColSize));
}

int main() {
  int colsize1 = 3, asize1 = 2;
  int **a1 = malloc(sizeof(int *) * (unsigned long)asize1);
  a1[0] = malloc(sizeof(int) * (unsigned long)colsize1);
  a1[1] = malloc(sizeof(int) * (unsigned long)colsize1);
  a1[0][0] = 1;
  a1[0][1] = 2;
  a1[0][2] = 3;
  a1[1][0] = 3;
  a1[1][1] = 2;
  a1[1][2] = 2;
  output(a1, asize1, &colsize1);
  printf("\n");
  free(a1);

  int colsize2 = 2, asize2 = 3;
  int **a2 = malloc(sizeof(int *) * (unsigned long)asize2);
  a2[0] = malloc(sizeof(int) * (unsigned long)colsize2);
  a2[1] = malloc(sizeof(int) * (unsigned long)colsize2);
  a2[2] = malloc(sizeof(int) * (unsigned long)colsize2);
  a2[0][0] = 1;
  a2[0][1] = 5;
  a2[1][0] = 7;
  a2[1][1] = 3;
  a2[2][0] = 3;
  a2[2][1] = 5;
  output(a2, asize2, &colsize2);
  free(a2);
  return 0;
}