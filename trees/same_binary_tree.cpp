#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == NULL && q == NULL) {
      return true;
    }
    if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
      return false;
    }
    bool l_ok = isSameTree(p->left, q->left);
    if (!l_ok)
      return false;
    bool r_ok = isSameTree(p->right, q->right);
    if (!r_ok)
      return false;

    if (p->val == q->val) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  TreeNode x1(1);
  x1.left = new TreeNode(2);
  x1.right = new TreeNode(3);

  TreeNode y1(1);
  y1.left = new TreeNode(2);
  y1.right = new TreeNode(3);

  TreeNode x2(4);
  x2.left = new TreeNode(7);

  TreeNode y2(4);
  y2.right = new TreeNode(7);

  Solution *s = new Solution();
  bool result = s->isSameTree(&x1, &y1);
  cout << result << endl;
  result = s->isSameTree(&x2, &y2);
  cout << result << endl;

  return 0;
}
