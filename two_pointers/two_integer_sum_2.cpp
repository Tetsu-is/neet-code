#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// pass with this
// class Solution
// {
// public:
//     vector<int> twoSum(vector<int> &numbers, int target)
//     {
//         // key=xのときtarge-xをvalueに入れる
//         unordered_map<int, vector<int>::iterator> complement_idx;
//         for (auto it = numbers.begin(); it != numbers.end(); it++)
//         {
//             if (complement_idx.find(*it) != complement_idx.end())
//             {
//                 // printf("complement found for %d: it->%d, comp->%d\n", target, *it, *complement_idx[*it]);
//                 int it_to_int = distance(numbers.begin(), complement_idx[*it]);
//                 int current_to_int = distance(numbers.begin(), it);
//                 return {it_to_int + 1, current_to_int + 1};
//             }
//             complement_idx[target - *it] = it;
//         }
//         return {};
//     }
// };

// arrange ver.
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        unordered_map<int, int> complement_idx; // Store index directly
        for (int i = 0; i < numbers.size(); ++i)
        {
            int current_number = numbers[i];
            if (complement_idx.count(current_number))
            {
                return {complement_idx[current_number] + 1, i + 1};
            }
            complement_idx[target - current_number] = i;
        }
        return {};
    }
};

int main()
{
    vector<int> numbers = {1, 2, 3, 4};
    int target = 3;
    Solution *s = new Solution();
    auto output = s->twoSum(numbers, target);
    for (int num : output)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}