/*
 * File: main.cpp
 * Project: FibonacciNumber
 * File Created: Wednesday, 6th July 2022 2:57:32 pm
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
    int fibWithDP(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        dp[n] = fibWithDP(n - 1, dp) + fibWithDP(n - 2, dp);
        return dp[n];
    }
    int fib(int n)
    {
        vector<int> dp(n + 1, -1);
        return fibWithDP(n, dp);
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: n = 2
    // Output: 1
    // Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

    // Input: n = 3
    // Output: 2
    // Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

    // Input: n = 4
    // Output: 3
    // Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
    
    return 0;
}