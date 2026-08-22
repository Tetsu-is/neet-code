#include <bits/stdc++.h>
using namespace std;

int calcSums(int n) {
  int sum = 0;
  while (n > 0) {
    int digit = n % 10;
    sum += digit * digit;
    n /= 10;
  }
  return sum;
}

class Solution {
public:
  bool isHappy(int n) {
    unordered_map<int, bool> seen;
    int sum = n;
    while (sum != 1 && seen.find(sum) == seen.end()) {
      seen[sum] = true;
      sum = calcSums(sum);
      cout << sum << endl;
    }
    return sum == 1;
  }
};

int main() {
  int n = 100;
  Solution *s = new Solution();
  bool answer = s->isHappy(n);
  cout << answer << endl;
  return 0;
}
