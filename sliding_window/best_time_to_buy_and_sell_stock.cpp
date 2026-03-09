#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int x = prices[0];
    int profit = 0;
    for (int i = 1; i < prices.size(); i++) {
      int p = prices[i];
      if (x >= p) {
        x = p;
      } else {
        if (p - x >= profit) {
          profit = p - x;
        }
      }
    }
    return profit;
  }
};

int main() {
  // vector<int> prices = {10, 1, 5, 6, 7, 1};
  vector<int> prices = {10, 8, 7, 5, 2};
  Solution *s = new Solution();
  int res = s->maxProfit(prices);
  printf("res: %d\n", res);
  return 0;
}
