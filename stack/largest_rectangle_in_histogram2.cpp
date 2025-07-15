#include <bits/stdc++.h>
using namespace std;

template<typename T>
void ps(stack<T> s)
{
  cout << "stack: [";
  while (!s.empty()) {
    cout << s.top() << ", ";
    s.pop();
  }
  cout << "]" << endl;
}

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      heights.push_back(0); // 番兵
      stack<int> st;
      int max_area = 0;

      for (int i = 0; i < heights.size(); i++)
	{
	  printf("i=%d\n", i);
	  while (!st.empty() && heights[i] < heights[st.top()])
	    {
	      printf("!st.empty() && heights[%d] < heights[%d] -> ", i, st.top());
	      printf("%d && %d < %d\n", !st.empty(), heights[i], heights[st.top()]);
	      int h = heights[st.top()];
	      printf("h << %d\n", h);
	      st.pop();
	      printf("popped ");
	      ps(st);
	      int w = st.empty() ? i : i - st.top() - 1;
	      printf("w << %d\n", w);
	      max_area = max(max_area, h*w);
	      printf("ma=%d\n", max_area);
	    }
	  st.push(i);
	  printf("push(%d) ", i);
	  ps(st);
	  printf("----------------------------\n");
	}
      return max_area;
    };
};


int main(){
  vector<int> heights = {7,1,7,2,2,4};
  // vector<int> heights = {1,3,7};
  // vector<int> heights = {1,1};
  Solution *s = new Solution();
  int out = s->largestRectangleArea(heights);
  printf("%d\n",out);
  return 0;
};
