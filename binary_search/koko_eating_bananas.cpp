#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int m = 0;
    for (int p : piles)
      m = max(m, p);

    int l = 1;
    int r = m;
    int result = m;
    while (l <= r) {
      int k = (l + r) / 2;
      long long total = 0;
      for (int p : piles) {
        total += (p + k - 1) / k;
      }
      if (total <= h) {
        result = k;
        r = k - 1;
      } else {
        l = k + 1;
      }
    }
    return result;
  };
};

int main() {
  vector<int> piles = {3, 6, 7, 11};
  int h = 8;

  Solution *s = new Solution();
  int reuslt = s->minEatingSpeed(piles, h);
  printf("%d\n", reuslt);
}
