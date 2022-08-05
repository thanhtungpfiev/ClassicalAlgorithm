/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/5/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 ***********************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> table(amount + 1);
        table[0] = 1;
        for (int i = 0; i < coins.size(); ++i)
        {
            for (int j = coins[i]; j <= amount; ++j)
            {
                table[j] += table[j - coins[i]];
            }
        }
        return table[amount];
    }
};

class Solution
{
public:
    typedef pair<int, int> mPair;
    int change(int amount, vector<int> &coins)
    {
        map<mPair, int> cache;
        return change(amount, 0, coins, cache);
    }
    int change(int amount, int start, vector<int> &coins, map<mPair, int> &cache)
    {
        if (amount < 0)
        {
            return 0;
        }

        if (amount == 0)
        {
            return 1;
        }

        mPair key = make_pair(amount, start);
        if (cache.find(key) != cache.end())
        {
            return cache[key];
        }

        int count = 0;
        for (int i = start; i < coins.size(); ++i)
        {
            count += change(amount - coins[i], i, coins, cache);
        }

        cache[key] = count;
        return count;
    }
};

int main()
{
    Solution sl;
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    cout << sl.change(amount, coins) << endl;
    amount = 3;
    coins = {2};
    cout << sl.change(amount, coins) << endl;
    amount = 10;
    coins = {10};
    cout << sl.change(amount, coins) << endl;

    // Input: amount = 5, coins = [1,2,5]
    // Output: 4
    // Explanation: there are four ways to make up the amount:
    // 5=5
    // 5=2+2+1
    // 5=2+1+1+1
    // 5=1+1+1+1+1

    // Input: amount = 3, coins = [2]
    // Output: 0
    // Explanation: the amount of 3 cannot be made up just with coins of 2.

    // Input: amount = 10, coins = [10]
    // Output: 1
    return 0;
}
