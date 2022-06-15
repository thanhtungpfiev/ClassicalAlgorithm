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
    return 0;
}
