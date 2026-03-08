#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int l = 0;
    int r = (int)nums.size() - 1;
    int res = 0;
    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] < nums[r]) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return nums[l];
  }
};

int main() {
  vector<int> nums = {3, 4, 5, 6, 1, 2};
  // vector<int> nums = {4, 5, 0, 1, 2, 3};
  Solution *s = new Solution();
  int result = s->findMin(nums);
  printf("%d\n", result);
}
