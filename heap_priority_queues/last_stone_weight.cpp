#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  // int lastStoneWeight(vector<int> &stones) {
  //   // create MaxHeap with INF, then i=1 and i=2 are always two biggest
  //   // while(len > 1) {compare and delete}
  //   priority_queue<int, vector<int>> maxHeap;
  //   for (int s : stones) {
  //     maxHeap.push(s);
  //   }
  //
  //   while (maxHeap.size() > 1) {
  //     int first = maxHeap.top();
  //     cout << "f is " << first << endl;
  //     maxHeap.pop();
  //     int second = maxHeap.top();
  //     cout << "s is " << second << endl;
  //     maxHeap.pop();
  //
  //     if (first < second) {
  //       int diff = second - first;
  //       maxHeap.push(diff);
  //     } else if (second < first) {
  //       int diff = first - second;
  //       maxHeap.push(first - second);
  //     } else {
  //       continue;
  //     }
  //   }
  //
  //   if (maxHeap.size() == 0) {
  //     return 0;
  //   }
  //   int top = maxHeap.top();
  //   return top;
  // }
  int lastStoneWeight(vector<int> &stones) {
    int maxStone = 0;
    for (int stone : stones) {
      maxStone = max(stone, maxStone);
    }

    // new vector<int> consists of (maxStone+1) zeros.
    vector<int> bucket(maxStone + 1, 0);
    for (int stone : stones) {
      bucket[stone]++;
    }

    int first = maxStone, second = maxStone;
    while (first > 0) {
      // if the count at this weight is even, all stones cancel in pairs
      if (bucket[first] % 2 == 0) {
        first--;
        continue;
      }
      // --- if the count at maxStone is odd ---
      int j = min(first - 1, second);
      while (j > 0 && bucket[j] == 0) {
        j--;
      }

      if (j == 0) {
        return first;
      }

      second = j;
      bucket[first]--;
      bucket[second]--;
      bucket[first - second]++;
      first = max(first - second, second);
    }
    return 0;
  };
};

int main() {
  vector<int> stones = {2, 3, 6, 2, 4};
  // vector<int> stones = {2, 2};
  Solution *s = new Solution();
  int r = s->lastStoneWeight(stones);
  cout << r << endl;
  return 0;
};
