#include <bits/stdc++.h>
#include <string>
using namespace std;

class TimeMap {
private:
  unordered_map<string, vector<pair<int, string>>> data;

public:
  TimeMap() {}
  void set(string key, string value, int timestamp) {
    data[key].push_back({timestamp, value});
  }
  string get(string key, int timestamp) {
    auto itr = data.find(key);
    if (itr == data.end()) {
      return "";
    }
    vector<pair<int, string>> &vec = data[key];

    int n = (int)vec.size();
    int l = 0; // the left end of search range
    int r = n; // the next of the right end of search range
    string result = "";
    while (l < r) {
      int mid = (l + r) / 2;
      if (vec[mid].first == timestamp) {
        result = vec[mid].second;
        break;
      } else if (vec[mid].first < timestamp) {
        result = vec[mid].second;
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return result;
  }
};

int main() {
  TimeMap *timeMap = new TimeMap();
  timeMap->set("alice", "happy1", 1);
  timeMap->set("alice", "happy3", 3);
  string ret1 = timeMap->get("alice", 4);
  cout << ret1 << endl;
}
