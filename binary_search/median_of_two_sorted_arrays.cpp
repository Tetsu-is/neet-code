#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = (int)nums1.size();
    int n = (int)nums2.size();
    vector<int> a = nums1;
    vector<int> b = nums2;
    if (m > n) {
      a = nums2;
      b = nums1;
      int tmp = m;
      m = n;
      n = tmp;
    }
    int l = 0;
    int r = (int)a.size();
    while (l <= r) {
      // image: leftA and leftB | rightA and rightB
      // take i elements from A, take j elements from B. j = (n+m)/2
      int i = (l + r) / 2;
      int j = (m + n) / 2 - i;
      int maxLeftA = (i > 0) ? a[i - 1] : -1e6;
      int minRightA = (i < m) ? a[i] : 1e6;

      int maxLeftB = (j > 0) ? b[j - 1] : -1e6;
      int minRightB = (j < n) ? b[j] : 1e6;
      if (maxLeftA > minRightB) {
        r = i;
      } else if (maxLeftB > minRightA) {
        l = i + 1;
      } else {
        if ((m + n) % 2 == 1) {
          cout << "odd" << endl;
          return min(minRightA, minRightB);
        } else {
          cout << "even" << endl;
          printf(
              "maxLeftA = %d, minRightA = %d, maxLeftB = %d, minRightB = %d\n",
              maxLeftA, minRightA, maxLeftB, minRightB);
          return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
        }
      }
    }
    return 8;
  }
};

int main() {
  vector<int> nums1 = {1, 2};
  vector<int> nums2 = {3, 4};
  Solution *s = new Solution();
  double result = s->findMedianSortedArrays(nums1, nums2);
  printf("result %f\n", result);
  return 0;
}
