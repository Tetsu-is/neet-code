#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> num_freq;
        for (auto &n : nums)
        {
            num_freq[n]++;
        }
        vector<pair<int, int>> freq_vec(num_freq.begin(), num_freq.end());
        sort(freq_vec.begin(), freq_vec.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return b.second < a.second;
        });
        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            auto freq = freq_vec[i];
            result.push_back(freq.first);
        }
        return result;
    }
};

int main() {
    Solution *s = new Solution;
    vector<int> nums = {1,2,2,3,3,3};
    int k = 2;
    auto res = s->topKFrequent(nums, k);
    for (auto &n : res)
    {
        cout << n << "," << endl;
    }
    return 0;
}
