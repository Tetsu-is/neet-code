#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        // unordered_set<int> appear;
        unordered_map<int, int> appear;

        // row
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char char_n = board[i][j];
                if (char_n == '.')
                {
                    continue;
                }
                int int_n = char_n - '0';
                appear[int_n]++;
            }
            for (int k = 1; k < 10; k++)
            {
                if (appear[k] != 1 && appear[k] != 0)
                {
                    return false;
                }
            }
            appear.clear();
        }

        // col
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char char_n = board[j][i];
                if (char_n == '.')
                {
                    continue;
                }
                int int_n = char_n - '0';
                appear[int_n]++;
            }
            for (int k = 1; k < 10; k++)
            {
                if (appear[k] != 1 && appear[k] != 0)
                {
                    return false;
                }
            }
            appear.clear();
        }

        // box
        // start pos -> 0,0 0,3 0,6 3,0 3,3 3,6 ...
        // check -> 0,0, 0,1 0,2, 1,0, 1,1 1,2 2,0 2,1 2,2....
        // printf("box check\n");
        for (int i = 0; i < 9; i++)
        {
            // i = 0,1,2...,8のとき x = 0,0,0,3,3,3,6,6,6
            //                     y = 0,3,6,0,3,6,0,3,6
            int startx = i / 3 * 3;
            int starty = i % 3 * 3;
            // printf("sx:%d, sy:%d\n", startx, starty);
            for (int j = 0; j < 9; j++)
            {
                int offsetx = j / 3;
                int offsety = j % 3;
                int x = startx + offsetx;
                int y = starty + offsety;
                char char_n = board[x][y];

                if (char_n == '.')
                {
                    continue;
                }
                int int_n = char_n - '0';
                // printf("(%d, %d) = %d\n", startx + offsetx, starty + offsety, int_n);
                appear[int_n]++;
            }
            for (int k = 1; k < 10; k++)
            {
                if (appear[k] != 1 && appear[k] != 0)
                {
                    return false;
                }
            }
            appear.clear();
        }

        return true;
    }
};

int main()
{
    vector<vector<char>> input1 = {
        {'1', '2', '.', '.', '3', '.', '.', '.', '.'},
        {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '.', '3'},
        {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
        {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    vector<vector<char>> input2 = {
        {'1', '2', '.', '.', '3', '.', '.', '.', '.'},
        {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
        {'.', '9', '1', '.', '.', '.', '.', '.', '3'},
        {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
        {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    vector<vector<char>> input3 = {
        {'1', '2', '.', '.', '3', '.', '.', '.', '.'},
        {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
        {'.', '9', '1', '.', '.', '.', '.', '.', '3'},
        {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
        {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution *s = new Solution();
    bool res = s->isValidSudoku(input2);
    cout << "res = " << res << endl;
    return 0;
}

// memo
// rowの検査をしたい場合はi=x, j=yのときにyを0-8まで動かせば良い
// cosの検査をしたい場合はi=x, j=yのときにxを0-8まで動かせば良い
// ハコを検査したい場合は少し特殊になる
// 0,0 0,1 0,2
// 1,0 1,1 1,2
// 2,0 2,1 2,2