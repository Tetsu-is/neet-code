#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // numsの個数のは2 <= nums.length <= 104
        unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); i++)
        {
            // 補数(相方)をcomplementとする
            int complement = target - nums[i];
            // find()は見つかればindexを見つからなければend()を返すので
            if (num_map.find(complement) != num_map.end())
            {
                return {num_map[complement], i};
            }
            num_map[nums[i]] = i;
        }
        return {};
    }
};