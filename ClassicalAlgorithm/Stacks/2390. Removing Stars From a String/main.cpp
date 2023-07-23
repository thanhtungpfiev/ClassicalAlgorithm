/*
 * File: main.cpp
 * Project: 2390. Removing Stars From a String
 * File Created: Wednesday, 19th July 2023 1:11:31 pm
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
    string removeStars(string s)
    {
        string result;
        for (auto c : s)
        {
            if (c == '*')
            {
                result.pop_back();
            }
            else
            {
                result.push_back(c);
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