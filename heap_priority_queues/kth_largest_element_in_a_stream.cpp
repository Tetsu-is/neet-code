#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

class KthLargest {
private:
  priority_queue<int, vector<int>, greater<int>> minHeap;
  int k;

public:
  // o(n) space
  // KthLargest(int k, vector<int> &nums) {
  //   this->k = k;
  //   this->nums = nums;
  //   sort(this->nums.rbegin(), this->nums.rend());
  // }
  // O(nlogn) time complexity , cuz sort() takes nlogn
  // int add(int val) {
  //   this->nums.push_back(val);
  //   sort(this->nums.rbegin(), this->nums.rend());
  //   cout << this->nums[this->k - 1] << endl;
  //   return this->nums[this->k - 1];
  // }
  KthLargest(int k, vector<int> &nums) {
    this->k = k;
    for (int num : nums) {
      minHeap.push(num);
      if (minHeap.size() > k) {
        minHeap.pop();
      }
    }
  }
  int add(int val) {
    minHeap.push(val);
    if (minHeap.size() > k) {
      minHeap.pop();
    }
    return minHeap.top();
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 3};
  KthLargest *kthLargest = new KthLargest(3, nums);
  cout << kthLargest->add(3) << endl;
  cout << kthLargest->add(5) << endl;
  cout << kthLargest->add(6) << endl;
  cout << kthLargest->add(7) << endl;
  cout << kthLargest->add(8) << endl;
  return 0;
}
