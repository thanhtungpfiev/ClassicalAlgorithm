/*
 * File: main.cpp
 * Project: FirstBadVersion
 * File Created: Wednesday, 27th July 2022 11:40:48 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        int left = 1;
        int right = n;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid) == false && isBadVersion(mid + 1) == true)
            {
                return mid + 1;
            }
            else if (isBadVersion(mid == true && isBadVersion(mid - 1) == false))
            {
                return mid;
            }
            else if (isBadVersion(mid) == false && isBadVersion(mid + 1) == false)
            {
                left = mid + 1;
            }
            else if (isBadVersion(mid) == true && isBadVersion(mid + 1) == true)
            {
                right = mid - 1;
            }
        }
        return n;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: n = 5, bad = 4
    // Output: 4
    // Explanation:
    // call isBadVersion(3) -> false
    // call isBadVersion(5) -> true
    // call isBadVersion(4) -> true
    // Then 4 is the first bad version.

    // Input: n = 1, bad = 1
    // Output: 1
    return 0;
}