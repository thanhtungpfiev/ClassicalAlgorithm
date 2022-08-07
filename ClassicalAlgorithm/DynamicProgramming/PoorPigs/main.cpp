/*
 * File: main.cpp
 * Project: PoorPigs
 * File Created: Saturday, 6th August 2022 11:53:58 am
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int pig = 0;
        while (pow((minutesToTest / minutesToDie + 1), pig) < buckets)
        {
            ++pig;
        }
        return pig;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: buckets = 1000, minutesToDie = 15, minutesToTest = 60
    // Output: 5
    // Input: buckets = 4, minutesToDie = 15, minutesToTest = 15
    // Output: 2
    // Input: buckets = 4, minutesToDie = 15, minutesToTest = 30
    // Output: 2
    return 0;
}