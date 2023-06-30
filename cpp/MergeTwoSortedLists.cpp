#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *dummy, *temp;
        dummy = new ListNode();
        temp = dummy;
        while(list1 && list2) {
            if(list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if(list1) temp->next = list1;
        if(list2) temp->next = list2;
        return dummy->next;
    }

    void output(ListNode *list1, ListNode *list2) {
        ListNode *temp = list1;
        cout << "Merging two sorted lists:\n";
        while(temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "nullptr\n";
        temp = list2;
        while(temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "nullptr\nResult:\n";
        temp = mergeTwoLists(list1, list2);
        while(temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "nullptr\n";
    }
};

int main() {
    Solution solution;
    ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(7)));
    ListNode *l2 = new ListNode(0, new ListNode(3, new ListNode(6)));
    solution.output(l1, l2);
    return 0;
}