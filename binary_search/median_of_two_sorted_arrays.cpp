#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int s1 = (int)nums1.size();
    int s2 = (int)nums2.size();
    vector<int> &a = nums1;
    vector<int> &b = nums2;
    if (s1 > s2) {
      a = nums2;
      b = nums1;
    }
    int l = 0;
    int r = (int)a.size();
    while (l < r) {
      // take i elements from A, take j elements from B. j = (n+m)/2
      // maxLeftA = a[i-1] if i > 0
      // minLeftA = a[i] if i < lenA
      //
    }
  }
};

int main() {
  vector<int> nums1 = {1, 2};
  vector<int> nums2 = {3};
  Solution *s = new Solution();
  int result = s->findMedianSortedArrays(nums1, nums2);
  printf("result %d\n", result);
  return 0;
}
