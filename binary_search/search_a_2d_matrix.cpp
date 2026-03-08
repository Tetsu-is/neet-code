#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//   bool searchMatrix(vector<vector<int>> &matrix, int target) {
//     int m = (int)matrix.size();
//     int n = (int)matrix[0].size();
//     for (int i = 0; i < m; i++) {
//       for (int j = 0; j < n; j++) {
//         if (matrix[i][j] == target)
//           return true;
//       }
//     };
//     return false;
//   };
// };

// first check which row target is in.
// 1. rowHead < target -> thisrow or later row
// 2. rowHead == target -> found
// 3. rowHead >= target -> earlier row or prevrow
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = (int)matrix.size();
    int n = (int)matrix[0].size();

    int ml = 0;
    int mr = m - 1;
    int mm = 0;
    while (ml < mr) {
      mm = (ml + mr) / 2;
      if (matrix[mm][0] <= target && target <= matrix[mm][n - 1]) {
        break;
      } else if (target < matrix[mm][0]) {
        mr = mm - 1;
      } else {
        ml = mm + 1;
      }
    }
    mm = (ml + mr) / 2;
    if (target < matrix[mm][0]) {
      return false;
    }
    if (target > matrix[mm][n - 1]) {
      return false;
    }
    int l = 0;
    int r = n - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (target == matrix[mm][mid]) {
        return true;
      } else if (target < matrix[mm][mid]) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    if (matrix[mm][l] == target) {
      return true;
    }
    return false;
  };
};

int main() {
  vector<vector<int>> matrix = {
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  int target = 13;
  Solution *s = new Solution();
  bool result = s->searchMatrix(matrix, target);
  printf("%s\n", result ? "true" : "false");
}
