// 文字列を含む、ではなくアナグラムだった

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size()) {
            return false;
        }

        map<char, int> m_s;
        map<char, int> m_t;

        for (int i = 0; i < t.size(); i++) {
            char c_t = t[i];
            m_t[c_t] ++;
            char c_s = s[i];
            m_s[c_s] ++;
        }


        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (m_s[c] == m_t[c]){
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }
};