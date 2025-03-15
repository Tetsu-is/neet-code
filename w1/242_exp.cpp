// 文字列を含む、ではなくアナグラムだった

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram_hash(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        unordered_map<char, int> countS;
        unordered_map<char, int> countT;

        for (int i = 0; i < s.length(); i++)
        {
            countS[s[i]]++;
            countT[t[i]]++;
        }
        return countS == countT;
    }

    bool isAnagram_sort(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main()
{
    string s = "anagram";
    string t = "nagaram";
    Solution *sol = new Solution();
    bool result = sol->isAnagram_hash(s,t);
    printf("result:%d\n", result);

    bool result2 = sol->isAnagram_sort(s,t);
    printf("result:%d\n", result2);
    return 0;
}