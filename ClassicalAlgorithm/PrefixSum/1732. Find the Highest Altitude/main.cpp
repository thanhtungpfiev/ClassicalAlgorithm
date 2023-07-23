/*
 * File: main.cpp
 * Project: 1732. Find the Highest Altitude
 * File Created: Monday, 17th July 2023 7:24:55 am
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
    int largestAltitude(vector<int> &gain)
    {
        int result = 0;
        int temp = 0;
        for (int i = 0; i < gain.size(); ++i)
        {
            temp += gain[i];
            if (temp > result)
            {
                result = temp;
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}