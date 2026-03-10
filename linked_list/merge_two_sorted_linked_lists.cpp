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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *h1 = list1;
    ListNode *h2 = list2;
    ListNode dummy(0);
    ListNode *current = &dummy;

    while (h1 != nullptr && h2 != nullptr) {
      if (h1->val <= h2->val) {
        cout << "h1<=h2 add " << h1->val << endl;
        current->next = h1;
        current = current->next;
        h1 = h1->next;
      } else {
        cout << "h1>h2 add " << h2->val << endl;
        current->next = h2;
        current = current->next;
        h2 = h2->next;
      }
    }
    while (h1 != nullptr) {
      current->next = h1;
      current = current->next;
      h1 = h1->next;
    }
    while (h2 != nullptr) {
      current->next = h2;
      current = current->next;
      h2 = h2->next;
    }
    return dummy.next;
  }
};

void printLN(ListNode *head) {
  while (head != nullptr) {
    cout << head->val << endl;
    head = head->next;
  }
}

ListNode *vectorToLN(vector<int> vec) {
  if (vec.empty()) {
    return nullptr;
  }
  ListNode dummy(0);
  ListNode *current = &dummy;
  for (int v : vec) {
    current->next = new ListNode(v);
    current = current->next;
  }
  return dummy.next;
}

int main() {
  vector<int> v1 = {1, 2, 4};
  vector<int> v2 = {1, 3, 5};
  ListNode *l1 = vectorToLN(v1);
  ListNode *l2 = vectorToLN(v2);
  // printLN(l1);
  // printLN(l2);

  Solution *s = new Solution();
  ListNode *res = s->mergeTwoLists(l1, l2);
  printLN(res);
  return 0;
}
