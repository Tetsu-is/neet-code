#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &heights)
    {
        int n = heights.size();
        int max = 0;
        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            int value = (right - left) * this->min(heights[left], heights[right]);
            if (value > max)
            {
                max = value;
            }
            if (this->min(heights[left], heights[right]) == heights[left])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return max;
    }
    int min(int x, int y)
    {
        if (x <= y)
        {
            return x;
        }
        else
        {
            return y;
        }
    }
};

int main()
{
    vector<int> inputs = {1, 7, 2, 5, 4, 7, 3, 6};
    Solution *s = new Solution();
    int output = s->maxArea(inputs);
    cout << output << endl;

    return 0;
}