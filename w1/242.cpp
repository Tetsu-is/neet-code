#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int s_len = s.size();
        int t_len = t.size();
        int match_len = 0;

        for (int s_head = 0; s_head < s_len; s_head++)
        {
            for (int t_head = 0; t_head < t_len; t_head++)
            {
                if (s[s_head] == t[t_head]) {
                    match_len ++;
                }

                if (t_head != t_len - 1) {
                    continue;
                }
            }
        }

        if (match_len == t_len) {
            return true;
        }
        else {
            return false;
        }
    }
};