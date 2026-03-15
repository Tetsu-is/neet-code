#include <bits/stdc++.h>
#include <ostream>
using namespace std;

template <typename T> struct Node {
  T data;
  Node *next;
  Node(const T &d) : data(d), next(nullptr) {}
};

template <typename T> class LinkedList {
private:
  Node<T> *head;

public:
  LinkedList() : head(nullptr) {}
  void push_front(const T &data) {
    Node<T> *newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
  }
  void display() const {
    Node<T> *current = head;
    while (current) {
      cout << current->data << " -> ";
      current = current->next;
    }
    cout << "nullptr" << endl;
  }
  ~LinkedList() {
    while (head) {
      Node<T> *temp = head;
      head = head->next;
      delete temp;
    }
  }
};

struct KV {
  string key;
  string value;
  friend ostream &operator<<(ostream &os, const KV &kv) {
    return os << "[ key = " << kv.key << ", value = " << kv.value << " ]";
  }
};

int main() {
  LinkedList<int> intList;
  intList.push_front(10);
  intList.push_front(20);
  intList.display();

  LinkedList<KV> kvList;
  kvList.push_front({"x", "X"});
  kvList.push_front({"y", "Y"});
  kvList.display();
  return 0;
}
