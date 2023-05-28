#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *res = NULL, *cur, *prev;
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

int main() {
    struct ListNode *l1 = malloc(sizeof(struct ListNode));
    l1->val = 2;
    l1->next = malloc(sizeof(struct ListNode));
    l1->next->val = 4;
    l1->next->next = malloc(sizeof(struct ListNode));
    l1->next->next->val = 3;
    l1->next->next->next = NULL;

    struct ListNode *l2 = malloc(sizeof(struct ListNode));
    l2->val = 5;
    l2->next = malloc(sizeof(struct ListNode));
    l2->next->val = 6;
    l2->next->next = malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;

    struct ListNode *res = addTwoNumbers(l1, l2);
    while (res) {
        printf("%d ", res->val);
        res = res->next;
    }
    printf("\n");
    return 0;
}