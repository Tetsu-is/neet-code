// #include <bits/stdc++.h>
#include <vector>
#include "1.cpp"

using namespace std;

int main() {
    Solution* sol = new Solution();
    vector<int> nums = {-1,-2,-3,-4,-5};
    int target = -8;

    vector<int> result = sol->twoSum(nums, target);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
}