#include <bits/stdc++.h>
#include <stdexcept>
#include <utility>
using namespace std;

class MinHeap {
private:
  vector<int> arr;
  void heapifyDown(int idx) {
    int size = this->size();
    while (true) {
      int smallest = idx;
      int left = 2 * idx + 1;
      int right = 2 * idx + 2;
      if (left < size && arr[left] < arr[smallest]) {
        smallest = left;
      }
      if (right < size && arr[right] < arr[smallest]) {
        smallest = right;
      }

      if (smallest == idx)
        break;

      swap(arr[idx], arr[smallest]);
      idx = smallest;
    }
  }

public:
  MinHeap() {};
  void push(int value) {
    arr.push_back(value);
    int idx = arr.size() - 1;
    int parentIdx = (idx - 1) / 2;
    while (idx > 0 && arr[parentIdx] > arr[idx]) {
      swap(arr[parentIdx], arr[idx]);
      idx = parentIdx;
      parentIdx = (idx - 1) / 2;
    }
  }
  int pop() {
    if (isEmpty()) {
      throw runtime_error("empty");
    }
    int root = arr[0];
    arr[0] = arr.back();
    arr.pop_back();

    if (!isEmpty()) {
      heapifyDown(0);
    }
    return root;
  }
  int top() {
    if (arr.size() == 0)
      return 0;
    return arr[0];
  }
  bool isEmpty() { return arr.size() == 0; }
  int size() { return arr.size(); }
};

int main() {
  MinHeap *mh = new MinHeap();
  vector<int> testData = {45, 20, 10, 31, 7, 11, 13, 2, 18};
  for (const auto &val : testData) {
    mh->push(val);
  }
  for (int i = 0; i < testData.size(); i++) {
    cout << i << "START" << endl;
    cout << "top = " << mh->top() << endl;
    mh->pop();
    cout << i << "END" << endl;
  }
  return 0;
}
