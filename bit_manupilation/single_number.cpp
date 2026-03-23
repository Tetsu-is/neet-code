#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int res = 0;
    for (int num : nums) {
      printf("%d ^= %d -> %d\n", res, num, res ^ num);
      res ^= num;
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution *s = new Solution;
  vector<int> nums = {4, 5, 6, 7, 4, 6, 5};
  cout << s->singleNumber(nums) << endl;
  return 0;
}
