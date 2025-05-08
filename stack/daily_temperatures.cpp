#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// brute force solution
// class Solution
// {
// public:
//     vector<int> dailyTemperatures(vector<int> &temperatures)
//     {
//         vector<int> result;
//         for (int i = 0; i < temperatures.size(); i++)
//         {
//             bool is_found = false;
//             for (int j = i + 1; j < temperatures.size(); j++)
//             {
//                 // printf("comp %d/%d -> %d/%d\n", i, j, temperatures[i], temperatures[j]);
//                 if (temperatures[i] < temperatures[j])
//                 {
//                     result.push_back(j - i);
//                     is_found = true;
//                     // cout << "found! " << i << ">" << j << endl;
//                     break;
//                 }
//             }
//             if (!is_found)
//             {
//                 result.push_back(0);
//             }
//         }
//         return result;
//     }
// };

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> result;
        stack<int> s;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> input = {30, 38, 30, 36, 35, 40, 28};
    vector<int> output = s->dailyTemperatures(input);
    for (auto e : output)
    {
        cout << e << endl;
    }
    return 0;
}