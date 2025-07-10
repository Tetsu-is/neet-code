#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        stack<double> s;
        vector<pair<int, int>> cars;
        for (size_t i = 0; i < position.size(); i++)
        {
            cars.push_back({position[i], speed[i]});
            // printf("push back cars\n");
        }
        sort(cars.begin(), cars.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.first > b.first; });
        // printf("%d\n", position.size());
        for (const auto& car : cars) {
            cout << "(" << car.first << "," << car.second << ") ";
        }
        cout << endl;
        for (vector<pair<int,int>>::iterator it = cars.begin(); it != cars.end(); ++it)
        {
            double time = (double)(target - it->first) / it->second;
            printf("time = %f\n", time);
            if (it == cars.begin()) {
                s.push(time);
                continue;
                // printf("1 stack push %f\n", time);
            }
            if (!s.empty() && time > s.top())
            {
                printf("compare time > top (%f > %f)\n",time, s.top());
                s.push(time);
                printf("2 stack push %f\n", time);
            }
            printf("----\n");
        }

        return s.size();
    }
};

int main()
{
    Solution *s = new Solution();
    int target = 17;
    vector<int> position = {8,12,16,11,7};
    vector<int> speed = {6,9,10,9,7};
    int out = s->carFleet(target, position, speed);
    printf("%d\n", out);
}