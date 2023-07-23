/*
 * File: main.cpp
 * Project: 2215. Find the Difference of Two Arrays
 * File Created: Tuesday, 18th July 2023 7:46:06 am
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<int> r1;
        vector<int> r2;
        for (auto &it : s1)
        {
            if (s2.find(it) == s2.end())
            {
                r1.push_back(it);
            }
        }
        for (auto &it : s2)
        {
            if (s1.find(it) == s1.end())
            {
                r2.push_back(it);
            }
        }
        vector<vector<int>> result;
        result.push_back(r1);
        result.push_back(r2);
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}