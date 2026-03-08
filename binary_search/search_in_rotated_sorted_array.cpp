#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int l = 0;
    int n = (int)nums.size();
    int r = n - 1;

    while (l < r) {
      int m = (l + r) / 2;
      if (nums[m] > nums[r]) {
        l = m + 1;
      } else {
        r = m;
      }
    }

    int pivot = l;

    int result = binarySearch(nums, target, 0, pivot - 1);
    if (result != -1) {
      return result;
    }

    return binarySearch(nums, target, pivot, n - 1);
  };

  int binarySearch(vector<int> &nums, int target, int left, int right) {
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }
};

int main() {
  vector<int> nums = {3, 4, 5, 6, 1, 2};
  // vector<int> nums = {3, 4, 1, 2};
  int target = 1;

  Solution *s = new Solution();
  int reuslt = s->search(nums, target);
  printf("%d\n", reuslt);
}
