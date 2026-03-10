#include <bits/stdc++.h>
#include <cstddef>
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

// Depth First Search with recursive call
void dfsR(TreeNode *root) {
  if (root == NULL) {
    return;
  }
  // cout << root->val << endl; PREORDER
  dfsR(root->left);
  // cout << root->val << endl; INORDER
  dfsR(root->right);
  cout << root->val << endl; // POSTORDER
}

// Depth First Search with Stack
void dfsStackPre(TreeNode *root) {
  if (!root)
    return;
  stack<TreeNode *> s;
  s.push(root);

  while (!s.empty()) {
    TreeNode *node = s.top();
    s.pop();
    cout << node->val << endl;
    if (node->right)
      s.push(node->right);
    if (node->left)
      s.push(node->left);
  }
}

void dfsStackIn(TreeNode *root) {
  stack<TreeNode *> s;
  TreeNode *cur = root;
  while (cur || !s.empty()) {
    while (cur) {
      s.push(cur);
      cur = cur->left;
    }
    cur = s.top();
    s.pop();
    cout << cur->val << endl;
    cur = cur->right;
  }
}

void dfsStackPost(TreeNode *root) {
  if (!root)
    return;

  stack<TreeNode *> s;
  stack<TreeNode *> result;

  s.push(root);

  while (!s.empty()) {
    TreeNode *node = s.top();
    s.pop();
    result.push(node);

    if (node->left)
      s.push(node->left);
    if (node->right)
      s.push(node->right);
  }

  while (!result.empty()) {
    TreeNode *node = result.top();
    result.pop();
    cout << node->val << endl;
  }
}

int main() {
  TreeNode x4(4);
  TreeNode x3(3, &x4, NULL);
  TreeNode x2(2);
  TreeNode x1(1, &x2, &x3);
  cout << "postRec" << endl;
  dfsR(&x1);
  cout << "pre" << endl;
  dfsStackPre(&x1);
  cout << "in" << endl;
  dfsStackIn(&x1);
  cout << "post" << endl;
  dfsStackPost(&x1);

  return 0;
}
