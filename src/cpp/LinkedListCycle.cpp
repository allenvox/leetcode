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
  bool hasCycle(ListNode *head) {
    if (!head || !head->next) return false;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) return true;
    }
    return false;
  }

  void output(ListNode *head) {
    cout << "Linked list:" << endl;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
      cout << slow->val << " -> ";
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        cout << slow->val << " (cycle)";
        break;
      }
    }
    cout << endl << "has ";
    if (!hasCycle(head)) cout << "no ";
    cout << "cycle in it" << endl << endl;
  }
};

int main() {
  Solution s;
  ListNode *l1 = new ListNode(1, new ListNode(1, new ListNode(2)));
  l1->next->next->next = l1;
  s.output(l1);

  ListNode *l2 =
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3))));
  l2->next->next->next = l2->next;
  s.output(l2);

  ListNode *l3 = new ListNode(1, new ListNode(0));
  s.output(l3);
  delete l3;
  return 0;
}