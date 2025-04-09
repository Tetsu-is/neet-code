#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        const int target = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < target)
                {
                    left++;
                }
                else if (sum > target)
                {
                    right--;
                }
                else
                {
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    result.push_back(temp);
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> input = {-1, 0, 1, 2, -1, -4};
    Solution *s = new Solution();
    vector<vector<int>> output = s->threeSum(input);
    for (const auto &vec : output)
    {
        for (int num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}