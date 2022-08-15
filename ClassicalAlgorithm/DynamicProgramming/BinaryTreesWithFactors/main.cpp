/*
 * File: main.cpp
 * Project: BinaryTreesWithFactors
 * File Created: Tuesday, 9th August 2022 2:20:07 pm
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
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        int MOD = 1000000007;
        int N = arr.size();
        sort(arr.begin(), arr.end());
        vector<long> dp(N, 1);
        unordered_map<int, int> index;
        for (int i = 0; i < N; ++i)
        {
            index[arr[i]] = i;
        }
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < i; ++j)
            { // A[j] is left child
                if (arr[i] % arr[j] == 0)
                {
                    int right = arr[i] / arr[j];
                    if (index.find(right) != index.end())
                    {
                        dp[i] = (dp[i] + dp[j] * dp[index[right]]) % MOD;
                    }
                }
            }
        }
        long ans = 0;
        for (auto e : dp)
        {
            ans += e;
        }
        return (int)(ans % MOD);
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: arr = [2,4]
    // Output: 3
    // Explanation: We can make these trees: [2], [4], [4, 2, 2]

    // Input: arr = [2,4,5,10]
    // Output: 7
    // Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
    return 0;
}