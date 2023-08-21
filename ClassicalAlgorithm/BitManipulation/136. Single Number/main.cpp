/*
 * File: main.cpp
 * Project: 136. Single Number
 * File Created: Wednesday, 16th August 2023 10:29:12 am
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
 * -----
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> ht;
        for (auto &e : nums) {
            ht[e]++;
        }
        for (auto &e : nums) {
            if (ht[e] == 1) {
                return e;
            }
        }
        return 1;

    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            result ^= nums[i];
        }
        return result;

    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}