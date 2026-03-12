// In Progress! There should be better ways!

#include <bits/stdc++.h>
#include <string>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {};
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {};
};

class Solution {
public:
  string serialize(TreeNode *root) {
    if (root == NULL) {
      return "$#";
    }
    return "$" + to_string(root->val) + serialize(root->left) +
           serialize(root->right);
  }

  vector<int> z_function(string s) {
    vector<int> z(s.length());
    int l = 0, r = 0, n = s.length();
    for (int i = 0; i < n; i++) {
      if (i <= r) {
        z[i] = min(r - i + 1, z[i - l]);
      }
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
        z[i]++;
      }
      if (i + z[i] - 1 > r) {
        l = i;
        r = i + z[i] - 1;
      }
    }
    return z;
  }

  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    string serialized_root = serialize(root);
    string serialized_subRoot = serialize(subRoot);
    string combined = serialized_subRoot + "|" + serialized_root;

    vector<int> z_values = z_function(combined);
    int sub_len = serialized_subRoot.length();

    for (int i = sub_len + 1; i < combined.length(); i++) {
      if (z_values[i] == sub_len) {
        return true;
      }
    }
    return false;
  }
};
// テスト用ヘルパー関数
void printResult(const string &testName, bool result) {
  cout << testName << ": " << (result ? "✓ true" : "✗ false") << endl;
}

int main() {
  Solution sol;

  cout << "====== Subtree of Another Tree テスト ======\n" << endl;

  // テストケース1: 完全に同じ木
  cout << "【テスト1】完全に同じ木" << endl;
  TreeNode *root1 = new TreeNode(3);
  root1->left = new TreeNode(4);
  root1->right = new TreeNode(5);
  root1->left->left = new TreeNode(1);
  root1->left->right = new TreeNode(2);

  TreeNode *subRoot1 = new TreeNode(3);
  subRoot1->left = new TreeNode(4);
  subRoot1->right = new TreeNode(5);
  subRoot1->left->left = new TreeNode(1);
  subRoot1->left->right = new TreeNode(2);

  bool result1 = sol.isSubtree(root1, subRoot1);
  printResult("同じ木がサブツリーか", result1);
  cout << "期待値: true\n" << endl;

  // テストケース2: 左の部分木がサブツリー
  cout << "【テスト2】左の部分木がサブツリー" << endl;
  TreeNode *root2 = new TreeNode(3);
  root2->left = new TreeNode(4);
  root2->right = new TreeNode(5);
  root2->left->left = new TreeNode(1);
  root2->left->right = new TreeNode(2);

  TreeNode *subRoot2 = new TreeNode(4);
  subRoot2->left = new TreeNode(1);
  subRoot2->right = new TreeNode(2);

  bool result2 = sol.isSubtree(root2, subRoot2);
  printResult("左の部分木がサブツリーか", result2);
  cout << "期待値: true\n" << endl;

  // テストケース3: サブツリーではない
  cout << "【テスト3】サブツリーではない場合" << endl;
  TreeNode *root3 = new TreeNode(3);
  root3->left = new TreeNode(4);
  root3->right = new TreeNode(5);
  root3->left->left = new TreeNode(1);
  root3->left->right = new TreeNode(2);

  TreeNode *subRoot3 = new TreeNode(4);
  subRoot3->left = new TreeNode(1);
  subRoot3->right = new TreeNode(3); // 異なる値

  bool result3 = sol.isSubtree(root3, subRoot3);
  printResult("異なる構造がサブツリーか", result3);
  cout << "期待値: false\n" << endl;

  // テストケース4: 単一ノード
  cout << "【テスト4】単一ノード同士" << endl;
  TreeNode *root4 = new TreeNode(1);

  TreeNode *subRoot4 = new TreeNode(1);

  bool result4 = sol.isSubtree(root4, subRoot4);
  printResult("単一ノードがサブツリーか", result4);
  cout << "期待値: true\n" << endl;

  // テストケース5: 値は同じだが構造が異なる
  cout << "【テスト5】値は同じだが構造が異なる場合" << endl;
  TreeNode *root5 = new TreeNode(1);
  root5->left = new TreeNode(1);

  TreeNode *subRoot5 = new TreeNode(1);
  subRoot5->right = new TreeNode(1);

  bool result5 = sol.isSubtree(root5, subRoot5);
  printResult("構造が異なるツリーがサブツリーか", result5);
  cout << "期待値: false\n" << endl;

  // テストケース6: より複雑な木
  cout << "【テスト6】複雑な木構造" << endl;
  TreeNode *root6 = new TreeNode(1);
  root6->left = new TreeNode(2);
  root6->right = new TreeNode(3);
  root6->left->left = new TreeNode(4);
  root6->left->right = new TreeNode(5);
  root6->right->left = new TreeNode(6);
  root6->right->right = new TreeNode(7);

  TreeNode *subRoot6 = new TreeNode(2);
  subRoot6->left = new TreeNode(4);
  subRoot6->right = new TreeNode(5);

  bool result6 = sol.isSubtree(root6, subRoot6);
  printResult("複雑な木の部分ツリーがサブツリーか", result6);
  cout << "期待値: true\n" << endl;

  // テストケース7: NULL チェック
  cout << "【テスト7】空のサブツリー" << endl;
  TreeNode *root7 = new TreeNode(1);
  root7->left = new TreeNode(2);

  TreeNode *subRoot7 = NULL;

  bool result7 = sol.isSubtree(root7, subRoot7);
  printResult("NULLがサブツリーか", result7);
  cout << "期待値: true (空の木はすべての木のサブツリー)\n" << endl;

  cout << "====== テスト完了 ======" << endl;

  return 0;
}
