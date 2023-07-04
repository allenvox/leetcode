#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *n) : val(x), next(n) {}
};

class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *current = head;
    while (current && current->next) {
      if (current->val == current->next->val)
        current->next = current->next->next;
      else
        current = current->next;
    }
    return head;
  }

  void output(ListNode *head) {
    ListNode *temp = head;
    cout << "Sorted linked list:\n";
    while (temp != nullptr) {
      cout << temp->val << " -> ";
      temp = temp->next;
    }
    cout << "nullptr\n";
    temp = deleteDuplicates(head);
    cout << "Without duplicates:\n";
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
  ListNode *l2 = new ListNode(
      1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
  s.output(l2);
  return 0;
}