#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        // if empty
        if (strs.empty())
            return "";

        // create a vector to store sizes
        vector<int> sizes;
        // result
        string res = "";

        // store each size of words 
        for (string &s : strs)
        {
            sizes.push_back(s.size());
        }

        // stringify sizes and create header
        for (int sz : sizes)
        {
            res += to_string(sz) + ',';
        }

        // end of header
        res += '#';
        for (string &s : strs)
        {
            res += s;
        }
        return res;
    }

    vector<string> decode(string s)
    {
        if (s.empty())
            return {};
        vector<int> sizes;
        vector<string> res;
        // tracking reading position
        int i = 0;
        // loop if current char is not "#"
        while (s[i] != '#')
        {
            string cur = "";
            // loop if current char is not ","
            while (s[i] != ',')
            {
                // adding chars in order
                cur += s[i];
                i++;
            }
            // recreate size-vector
            sizes.push_back(stoi(cur));
            i++;
        }
        // incr the tracking point to go to payload
        i++;
        for (int sz : sizes)
        {
            res.push_back(s.substr(i, sz));
            i += sz;
        }
        return res;
    }
};

int main()
{

    Solution *sol = new Solution();
    vector<string> strs = {"neet", "code", "love", "you"};
    string encoded = sol->encode(strs);
    cout << encoded << endl;
    vector<string> decoded = sol->decode(encoded);
    for (auto &s : decoded)
    {
        cout << s << endl;
    }

    return 0;
}
