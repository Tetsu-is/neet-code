#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

// TODO: check answer
class Solution
{
public:
    // i番目に「i番目以外の積が入ったvector」を返す
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int non_zero_all_product = 1;
        vector<int> result;
        bool include_zero = false;
        bool include_double_zero = false;
        for (auto &i : nums)
        {
            if (i != 0)
            {
                non_zero_all_product *= i;
            }
            else
            {
                if (include_zero == true)
                {
                    include_double_zero = true;
                }
                include_zero = true;
            }
        }
        for (auto &i : nums)
        {
            if (include_double_zero)
            {
                result.push_back(0);
            }
            else {
                if (include_zero)
                {
                    if (i == 0)
                    {
                        result.push_back(non_zero_all_product);
                    }
                    else 
                    {
                        result.push_back(0);
                    }
                }
                else {
                    result.push_back(non_zero_all_product/i);
                }
            }
            
        }
        return result;
    }
};

int main()
{
    Solution *sol = new Solution();
    vector<int> nums = {-1,0,1,2,3};
    vector<int>res = sol->productExceptSelf(nums);
    for (auto &i :res)
    {
        cout << i << endl;
    }
    return 0;
}