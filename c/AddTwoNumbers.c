#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

void deleteList(struct ListNode *l) {
  if (l->next != NULL) deleteList(l->next);
  free(l);
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  struct ListNode *res = NULL, *cur, *prev = NULL;
  int value = 0;
  while (l1 != NULL || l2 != NULL || value != 0) {
    cur = malloc(sizeof(struct ListNode));
    if (l1) {
      value += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      value += l2->val;
      l2 = l2->next;
    }
    cur->val = value % 10;
    cur->next = NULL;
    value /= 10;
    if (!res) {
      res = cur;
    }
    if (prev) {
      prev->next = cur;
    }
    prev = cur;
  }
  return res;
}

void output(struct ListNode *l1, struct ListNode *l2) {
  struct ListNode *temp = l1, *res = addTwoNumbers(l1, l2);
  char s[64] = "\n";
  while (temp) {
    char buff[5];
    sprintf(buff, "%d ", temp->val);
    strcat(s, buff);
    temp = temp->next;
  }
  strcat(s, "+ ");
  temp = l2;
  while (temp) {
    char buff[5];
    sprintf(buff, "%d ", temp->val);
    strcat(s, buff);
    temp = temp->next;
  }
  strcat(s, "= ");
  temp = res;
  while (temp) {
    char buff[5];
    sprintf(buff, "%d ", temp->val);
    strcat(s, buff);
    temp = temp->next;
  }
  for (int i = strlen(s); i >= 0; i--) {
    printf("%c", s[i]);
  }
  deleteList(res);
}

int main() {
  struct ListNode *l1 = malloc(sizeof(struct ListNode));
  l1->val = 2;
  l1->next = malloc(sizeof(struct ListNode));
  l1->next->val = 4;
  l1->next->next = malloc(sizeof(struct ListNode));
  l1->next->next->val = 4;
  l1->next->next->next = NULL;

  struct ListNode *l2 = malloc(sizeof(struct ListNode));
  l2->val = 5;
  l2->next = malloc(sizeof(struct ListNode));
  l2->next->val = 6;
  l2->next->next = malloc(sizeof(struct ListNode));
  l2->next->next->val = 4;
  l2->next->next->next = NULL;

  output(l1, l2);
  deleteList(l1);
  deleteList(l2);
  return 0;
}
