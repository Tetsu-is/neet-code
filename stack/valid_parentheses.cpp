#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stack;
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}};

        for (char c : s)
        {
            if (closeToOpen.count(c))
            {
                if (!stack.empty() && stack.top() == closeToOpen[c])
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};

int main()
{
    string input = "[(])";
    Solution *s = new Solution();
    bool output = s->isValid(input);
    cout << output << endl;
    return 0;
}