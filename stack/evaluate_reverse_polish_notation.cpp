#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
  public:
    int evalRPN(vector<string>& tokens)
    {
      stack<int> s;
      for (const string& t : tokens)
      {
        if (t == "+")
        {
          int x = s.top();
          s.pop();
          int y = s.top();
          s.pop();
          int result = y + x;
          s.push(result);
        }
        else if (t == "-"){
          int x = s.top();
          s.pop();
          int y = s.top();
          s.pop();
          int result = y - x;
          s.push(result);
        }
        else if (t == "*"){
          int x = s.top();
          s.pop();
          int y = s.top();
          s.pop();
          int result = y * x;
          s.push(result);
        }
        else if (t == "/"){
          int x = s.top();
          s.pop();
          int y = s.top();
          s.pop();
          int result = y / x;
          s.push(result);
        }
        else {
          int v = stoi(t);
          s.push(v);
        }
      }

      return s.top();
    }
};

int main()
{
  Solution *s = new Solution();
  vector<string> tokens = {"1", "2", "+", "3", "*", "4", "-"};
  int out = s->evalRPN(tokens);
  cout << out << endl;
  return 0;
}