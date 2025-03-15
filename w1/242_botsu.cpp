// 文字列を含む、ではなくアナグラムだった

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int s_len = s.size();
        int t_len = t.size();
        int s_head = 0;
        int t_head = 0;
        int match_len = 0;

        while (t_head < t_len && s_head < s_len) {
            if (t[t_head] != s[s_head]) {
                s_head++;
                continue;
            }
            else {
                t_head ++;
                s_head++;
                match_len++;
                continue;
            }
        }

        // printf("mlen: %d, tlen: %d\n", match_len, t_len);
        if (match_len == t_len)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};