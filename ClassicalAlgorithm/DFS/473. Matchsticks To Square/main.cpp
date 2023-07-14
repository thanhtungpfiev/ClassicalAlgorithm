/*
 * File: main.cpp
 * Project: MatchsticksToSquare
 * File Created: Tuesday, 7th June 2022 2:56:17 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool makesquare(vector<int> &matchsticks)
    {
        if (matchsticks.size() == 0)
        {
            return false;
        }
        int length = 0;
        for (int i = 0; i < matchsticks.size(); ++i)
        {
            length += matchsticks[i];
        }
        int sumLength = length / 4;
        if (sumLength * 4 != length)
        {
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> sum(4);
        return dfs(0, matchsticks, sum, sumLength);
    }

    bool dfs(int index, vector<int> &matchsticks, vector<int> &sum, int sumLength)
    {
        if (index == matchsticks.size())
        {
            return sum[0] == sum[1] && sum[1] == sum[2] && sum[2] == sum[3];
        }
        int element = matchsticks[index];
        for (int i = 0; i < 4; ++i)
        {
            if (sum[i] + element <= sumLength)
            {
                sum[i] += element;
                if (dfs(index + 1, matchsticks, sum, sumLength))
                {
                    return true;
                }
                sum[i] -= element;
            }
        }
        return false;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<int> matchsticks = {1,1,2,2,2};
    cout << sl.makesquare(matchsticks) << endl;
    matchsticks = {3, 3, 3, 3, 4};
    cout << sl.makesquare(matchsticks) << endl;
    return 0;
}