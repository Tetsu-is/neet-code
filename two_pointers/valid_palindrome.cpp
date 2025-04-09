#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int length = s.length();

        string charsToDelete = " ,.?':";
        for (char c : charsToDelete)
        {
            s.erase(remove(s.begin(), s.end(), c), s.end());
        }
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        for (auto it_head = s.begin(), it_tail = s.end() - 1; it_head < it_tail; ++it_head, --it_tail)
        {
            if (*it_head != *it_tail)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string input = "Madam, in Eden, I'm Adam";
    Solution *s = new Solution();
    bool output = s->isPalindrome(input);
    if (output)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}