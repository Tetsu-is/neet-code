#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

class Interval {
public:
  int start, end;
  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class Solution {
public:
  bool canAttendMeetings(vector<Interval> &intervals) {
    sort(
        intervals.begin(), intervals.end(),
        [](const Interval &a, const Interval &b) { return a.start < b.start; });
    for (size_t i = 1; i < intervals.size(); i++) {
      if (intervals[i - 1].end > intervals[i].start) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  vector<pair<int, int>> inputs = {{0, 30}, {5, 10}, {15, 20}};
  vector<Interval> intervals;
  for (auto [start, end] : inputs) {
    Interval i = Interval(start, end);
    intervals.push_back(i);
  }
  Solution *s = new Solution();
  bool res = s->canAttendMeetings(intervals);
  cout << res << endl;
  return 0;
}
