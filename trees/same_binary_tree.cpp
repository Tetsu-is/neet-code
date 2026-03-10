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
    stack<pair<TreeNode *, TreeNode *>> stk;
    stk.push({p, q});

    while (!stk.empty()) {
      auto [node1, node2] = stk.top();
      stk.pop();

      if (!node1 && !node2)
        continue;
      if (!node1 || !node2 || node1->val != node2->val)
        return false;

      stk.push({node1->right, node2->right});
      stk.push({node1->left, node2->left});
    }

    return true;
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
