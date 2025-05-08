#include <vector>
#include <string>
#include <iostream>
#include <set>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        if (n == 0)
        {
            return vector<string>{""};
        }
        vector<string> result = generateParenthesis(n - 1);
        set<string> result_set;

        for (const auto parentheses : result)
        {
            if (parentheses.empty())
            {
                result_set.insert("()");
            }
            else
            {
                result_set.insert("()" + parentheses);
                result_set.insert("(" + parentheses + ")");
                result_set.insert(parentheses + "()");
            }
        }
        vector<string> new_result;
        for (const auto e : result_set)
        {
            new_result.push_back(e);
        }

        return new_result;
    }
};

int main()
{
    Solution *s = new Solution();
    int input = 3;
    vector<string> output = s->generateParenthesis(input);
    for (auto e : output)
    {
        cout << e << endl;
    }
    return 0;
}

// n = 2
// ()(), (())