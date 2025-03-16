// #include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // ソート済み文字列がkeyでstringのgroupがvalueになっているmapを作成
        unordered_map<string, vector<string>> res;
        for (const auto &s : strs) // vectorであるstrsの要素を参照&sを使ってイテレートしていく
        {
            // sをsortしたものをつくる
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            // sortedSは固有のkeyとなる。valueの部分に追加していく。
            res[sortedS].push_back(s);
        }
        // mapのままではreturnできないのでresultを作っていくよ
        vector<vector<string>> result;
        for( auto& pair : res) // mapの各要素に対してイテレートしていく
        {
            // pairはすでにvector<string>になっているので詰め込めば良い
            result.push_back(pair.second);
        }
        return result;
    }
};

int main()
{
    vector<string> strs = {"a"};
    Solution *sol = new Solution();
    vector<vector<string>> result = sol->groupAnagrams(strs);
    for (const auto &group : result)
    {
        for (const auto &word : group)
        {
            cout << word << " ";
        }
        cout << endl;
    }
}