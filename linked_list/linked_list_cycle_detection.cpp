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
  bool hasCycle(ListNode *head) {
    ListNode *p1 = head;
    ListNode *p2 = head;

    while (p2 != nullptr && p2->next != nullptr) {
      p1 = p1->next;
      p2 = p2->next->next;
      // judge
      if (p1 != head && p1 == p2) {
        return true;
      }
    }
    return false;
  }
};

void printLN(ListNode *head) {
  while (head != nullptr) {
    cout << head->val << endl;
    head = head->next;
  }
}

int main() {
  ListNode x1(1);
  ListNode x2(2);
  x1.next = &x2;
  ListNode x3(3);
  x2.next = &x3;
  ListNode x4(4, &x2);
  x3.next = &x4;
  // printLN(&x1);
  // ListNode x1(1);
  // ListNode x2(2);
  // x1.next = &x2;

  Solution *s = new Solution();
  bool res = s->hasCycle(&x1);
  cout << res << endl;
  return 0;
}
