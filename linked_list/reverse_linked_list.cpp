#include <bits/stdc++.h>
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
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *res = new ListNode(head->val);
    while (head->next != nullptr) {
      head = head->next;
      ListNode *ln = new ListNode(head->val, res);
      res = ln;
    }
    return res;
  };
};

void printLN(ListNode *head) {
  while (head->next != nullptr) {
    cout << head->val << endl;
    head = head->next;
  }
}

int main() {
  ListNode *x3 = new ListNode(3);
  ListNode *x2 = new ListNode(2, x3);
  ListNode *x1 = new ListNode(1, x2);
  ListNode *x0 = new ListNode(0, x1);

  printLN(x0);
  Solution *s = new Solution();
  ListNode *head = s->reverseList(x0);
  printLN(head);
  return 0;
}
