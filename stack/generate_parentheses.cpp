#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        
    }
};

int main()
{
    Solution *s = new Solution();
    int input = 1;
    vector<string> output = s->generateParenthesis(input);
    for (auto e : output)
    {
        cout << e << endl;
    }
    return 0;
}

// n = 2
// ()(), (())