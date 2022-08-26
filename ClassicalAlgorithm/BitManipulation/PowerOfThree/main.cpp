/*
 * File: main.cpp
 * Project: PowerOfThree
 * File Created: Wednesday, 24th August 2022 11:08:44 am
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
    bool isPowerOfThree(int n)
    {
        while (n > 1)
        {
            if (n % 3)
            {
                return false;
            }
            n /= 3;
        }
        return n == 1;
    }
};

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        // 3^19 = 1162261467
        return n > 0 && 1162261467 % n == 0;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: n = 27
    // Output: true

    // Input: n = 0
    // Output: false

    // Input: n = 9
    // Output: true
    return 0;
}