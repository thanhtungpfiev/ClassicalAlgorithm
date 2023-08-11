/*
 * File: main.cpp
 * Project: 435. Non-overlapping Intervals
 * File Created: Wednesday, 9th August 2023 1:57:23 pm
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static bool compare2Intervals(vector<int> &i1, vector<int> &i2)
    {
        return i1[1] < i2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int result = 0;
        int k = INT_MIN;
        sort(intervals.begin(), intervals.end(), compare2Intervals);
        for (auto interval : intervals)
        {
            if (interval[0] >= k)
            {
                k = interval[1];
            }
            else
            {
                result++;
            }
        }
        return result;
    }
};

using namespace std;

int main(int argc, char **argv)
{
    Solution sl;
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << sl.eraseOverlapIntervals(intervals) << endl;
    return 0;
}