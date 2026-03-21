#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<int> memo;

public:
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    memo.assign(n, -1);
    int ret = 0 + min(dfs(0, cost), dfs(1, cost));
    return ret;
  }
  int dfs(int i, vector<int> &cost) {
    int len = (int)cost.size();
    if (i >= len)
      return 0;
    if (memo[i] != -1) {
      return memo[i];
    }
    int res = cost[i] + min(dfs(i + 1, cost), dfs(i + 2, cost));
    memo[i] = res;
    return res;
  }
};

int main() {
  vector<int> cost = {1, 2, 3};
  Solution *s = new Solution();
  cout << s->minCostClimbingStairs(cost) << endl;
  return 0;
}

// dfs + memo: 2ms, 147.5MB
//
