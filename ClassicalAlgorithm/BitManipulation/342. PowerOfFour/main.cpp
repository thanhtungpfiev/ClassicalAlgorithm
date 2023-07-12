/*
 * File: main.cpp
 * Project: PowerOfFour
 * File Created: Monday, 22nd August 2022 10:54:02 am
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
    bool isPowerOfFour(int num)
    {
        if (num < 0)
            return false;
        int no_of_one = 0, pos = 1, ones_pos = 0;
        while (num)
        {
            if (num & 1)
                no_of_one += 1, one_pos = pos;
            num >>= 1, pos += 1;
        }
        return no_of_one == 1 && one_pos & 1;
    }
};

class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        if (num < 0)
            return false;
        for (int i = 0; i < 32; i += 2)
            if (num == 1 << i)
                return true;
        return false;
    }
};

class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        vector<int> Cup = {1, 4, 16, 64, 256, 1024, 4096, 16384, 65536, 262144, 1048576, 4194304, 16777216, 67108864, 268435456, 1073741824};
        for (int no : Cup)
            if (num == no)
                return true;
        return false;
    }
};

class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        while (num > 1)
        {
            if (num % 4)
                return false;
            num /= 4;
        }
        return num == 1;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: n = 16
    // Output: true

    // Input: n = 5
    // Output: false

    // Input: n = 1
    // Output: true
    return 0;
}