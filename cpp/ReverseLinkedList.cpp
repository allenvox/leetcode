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
  ListNode *reverseList(ListNode *head) {
    ListNode *prev = NULL, *cur = head;
    while (cur) {
      ListNode *nxt = cur->next;
      cur->next = prev;
      prev = cur;
      cur = nxt;
    }
    return prev;
  }

  void output(ListNode *head) {
    ListNode *temp = head;
    cout << "Reverse linked list:" << endl;
    while (temp != nullptr) {
      cout << temp->val << " -> ";
      temp = temp->next;
    }
    cout << "nullptr" << endl;
    temp = reverseList(head);
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
  s.output(l1);
  delete l1;

  ListNode *l2 = new ListNode(
      1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
  s.output(l2);
  delete l2;
  return 0;
}