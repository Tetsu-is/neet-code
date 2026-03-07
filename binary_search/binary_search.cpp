#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int l = 0;
    int r = (int)nums.size() - 1;
    int result = -1;
    while (l < r) {
      int m = (l + r) / 2;
      if (nums[m] == target) {
        return m;
      } else if (target < nums[m]) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    if (nums[l] == target) {
      return l;
    }
    return -1;
  }
};

int main() {
  vector<int> input = {-1, 0, 2, 4, 6, 8};
  int target = 3;
  Solution *s = new Solution();
  int result = s->search(input, target);
  printf("result %d\n", result);
  return 0;
}
