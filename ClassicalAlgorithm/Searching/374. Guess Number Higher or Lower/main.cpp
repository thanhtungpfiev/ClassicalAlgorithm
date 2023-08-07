/*
 * File: main.cpp
 * Project: 374. Guess Number Higher or Lower
 * File Created: Tuesday, 1st August 2023 1:51:33 pm
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
 * -----
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        int start = 1;
        int end = n;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (guess(mid) == 0)
            {
                return mid;
            }
            else if (guess(mid) == -1)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}