// #include <bits/stdc++.h>
#include <vector>
#include <cstdio>
#include <iostream>
#define MAX_HEIGHT 1000

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      int s_max = 0;
      for (vector<int>::iterator it = heights.begin(); it != heights.end(); it++)
	{
	  int s1 = *it; // スタート地点ごとの最大値。棒1本のときが初期値
	  if (s_max < s1)
	    {
	      s_max = s1;
	    }
	  // printf("s1 = %d\n", s1);
	  int min_height = *it;
	  for(vector<int>::iterator it2 = next(it); it2 != heights.end(); it2++)
	    {
	      // cout << "it1,ite2 = " << distance(heights.begin(), it) << distance(heights.begin(), it2) << endl;
	      int s2 = 0; // ゴール地点ごとの面積の値
	      int width = it2 - it + 1;
	      if (*it2 < min_height)
		{
		  min_height = *it2;
		}
	      s2 = min_height * width;
	      // printf("min_height * width = %d * %d\n", min_height, width);
	      // printf("s2 = %d\n", s2);
	      if (s1 < s2)
		{
		  s1 = s2;
		}
	      if (s_max < s1)
		{
		  s_max = s1;
		}
	    }
	}
      return s_max;
    };
};

int main(){
  // vector<int> heights = {7,1,7,2,2,4};
  // vector<int> heights = {1,3,7};
  vector<int> heights = {1,1};
  Solution *s = new Solution();
  int out = s->largestRectangleArea(heights);
  printf("%d\n",out);
  return 0;
};
