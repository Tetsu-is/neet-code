#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int min = 0;
        int sum = 0;
        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = height[0];
        suffix[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++) // 0~n-1番目の要素がある。i=1~n-1
        {
            // prefix[i]を決める時は0~i-1までのmaxが欲しい
            if (prefix[i - 1] <= height[i - 1])
            {
                prefix[i] = height[i - 1];
            }
            else
            {
                prefix[i] = prefix[i - 1];
            }

            // suffix[i]を決める時はi+1~n-1までのmaxがほしい
            int j = n - i - 1;
            if (suffix[j + 1] <= height[j + 1])
            {
                suffix[j] = height[j + 1];
            }
            else
            {
                suffix[j] = suffix[j + 1];
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (prefix[i] <= suffix[i])
            {
                min = prefix[i];
            }
            else
            {
                min = suffix[i];
            }

            int value = min - height[i];
            if (value > 0)
            {
                sum += value;
            }
        }

        return sum;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> input = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int output = s->trap(input);
    cout << output << endl;
    return 0;
}