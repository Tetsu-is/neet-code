#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        int longestRecord = 1;
        int currentStreak = 1;

        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        for (auto s : nums)
        {
            cout << s << endl;
        }

        auto prev_it = nums.begin();
        for (auto it = nums.begin() + 1; it != nums.end();)
        {
            printf("comp %d %d\n", *prev_it, *it);
            if (*it - *prev_it == 1)
            {
                currentStreak++;
                if (currentStreak >= longestRecord)
                {
                    longestRecord = currentStreak;
                }
            }
            else
            {
                currentStreak = 1;
            }
            prev_it = it++;
        }

        return longestRecord;
    }
};

int main()
{
    vector<int> input = {2, 20, 4, 10, 3, 4, 5};
    vector<int> input2 = {0, 3, 2, 5, 4, 6, 1, 1};
    Solution *s = new Solution();
    int output = s->longestConsecutive(input);
    cout << output << endl;
    return 0;
}

// sortして連続最高記録を残す？