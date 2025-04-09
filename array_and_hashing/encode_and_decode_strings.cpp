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
        string header = "";
        string header_end = "_@@@";
        string payload = "";
        for (auto &s : strs)
        {
            int length = s.length();
            if (&s != &strs.back())
            {
                header += to_string(length) + "_";
            }
            else
            {
                header += to_string(length) + header_end;
            }
            payload += s;
        }
        return header + payload;
    }

    vector<string> decode(string s)
    {
        string del = "_";
        string end = "@@@";
        vector<string> result;
        size_t pos = s.find(end);
        if (pos == string::npos)
        {
            cout << "ersr" << endl;
        }

        string header = s.substr(0, pos);
        // cout << "header: " << header << endl;
        s.erase(0, pos + end.length());
        string payload = s;
        // cout << "payload: " << payload << endl;

        while(header.find(del)!=string::npos)
        {
            size_t del_pos = header.find(del);
            string count = header.substr(0, del_pos);
            size_t count_pos = stoi(count);
            header.erase(0, del_pos+del.length());
            // cout << "count: " << count << " erased_header: " << header << endl;
            string token = payload.substr(0, count_pos);
            // cout << token << endl;
            payload.erase(0, count_pos);
            result.push_back(token);
        }
        return result;
    }
};

int main()
{

    Solution *sol = new Solution();
    vector<string> strs = {"neet", "code", "love", "you"};
    string encoded = sol->encode(strs);
    // cout << "encode result --------- " << encoded << endl;
    vector<string> decoded = sol->decode(encoded);
    // cout << "decode result-----------" << endl;
    // for (auto &e : decoded)
    // {
    //     cout << e << ", " << endl;
    // }
    return 0;
}
