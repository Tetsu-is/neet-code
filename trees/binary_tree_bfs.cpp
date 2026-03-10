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

// Depth First Search with recursive call
void bfs(TreeNode *root) {}

int main() {
  TreeNode x4(4);
  TreeNode x3(3, &x4, NULL);
  TreeNode x2(2);
  TreeNode x1(1, &x2, &x3);
  bfs(&x1);
  return 0;
}
