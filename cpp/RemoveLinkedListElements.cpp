#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *n) : val(x), next(n) {}
  ~ListNode() { delete next; }
};

class Solution {
 public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *cur = head, *prev = NULL, *newhead = cur;
    for (; cur != NULL; cur = cur->next) {
      if (cur->val == val) {
        if (newhead == cur) {
          newhead = cur->next;
        } else if (prev != NULL) {
          prev->next = cur->next;
        }
      } else {
        prev = cur;
      }
    }
    return newhead;
  }

  void output(ListNode *head, int val) {
    ListNode *temp = head;
    cout << "Delete elements \"" << val << "\" from linked list:\n";
    while (temp != nullptr) {
      cout << temp->val << " -> ";
      temp = temp->next;
    }
    cout << "nullptr" << endl;
    temp = removeElements(head, val);
    cout << "Result:" << endl;
    while (temp != nullptr) {
      cout << temp->val << " -> ";
      temp = temp->next;
    }
    cout << "nullptr\n\n";
  }
};

int main() {
  Solution s;
  ListNode *l1 = new ListNode(1, new ListNode(1, new ListNode(2)));
  s.output(l1, 1);
  delete l1;

  ListNode *l2 = new ListNode(
      1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
  s.output(l2, 2);
  delete l2;
  return 0;
}