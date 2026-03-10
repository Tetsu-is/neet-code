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
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr)
      return nullptr;
    TreeNode *res = new TreeNode(root->val);
    if (root->right != nullptr) {
      res->left = invertTree(root->right);
    }
    if (root->left != nullptr) {
      res->right = invertTree(root->left);
    }
  }
};

int main() {
  TreeNode x4(4);
  TreeNode x5(5);
  TreeNode x6(6);
  TreeNode x7(7);
  TreeNode x2(2, &x4, &x5);
  TreeNode x3(3, &x6, &x7);
  TreeNode x1(1, &x2, &x3);

  Solution *s = new Solution();
  TreeNode *res = s->invertTree(&x1);

  return 0;
}
