/**********************************************************************
 *
 * author vcs tung.dao@lge.com
 *
 * date 5/4/2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
***********************************************************************/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int value[amount + 1];
        int first[amount + 1];
        value[0] = 0;
        for (int x = 1; x <= amount; x++) {
            value[x] = INT_MAX - 1;
            for (auto c : coins) {
                if (x-c >= 0) {
                    if (value[x-c]+1 < value[x]) {
                        first[x] = c;
                    }
                    value[x] = min(value[x], value[x-c]+1);
                }
            }
        }

        if (value[amount] != INT_MAX - 1) {
            int result = value[amount];
            while (amount > 0) {
                cout << first[amount] << " ";
                amount -= first[amount];
            }
            cout << endl;
            return result;
        } else {
            return -1;
        }
    }

};

int main()
{
    Solution s;
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout << s.coinChange(coins, amount) << endl;
    coins = {2};
    amount = 3;
    cout << s.coinChange(coins, amount) << endl;
    coins = {1};
    amount = 0;
    cout << s.coinChange(coins, amount) << endl;
    return 0;
}
