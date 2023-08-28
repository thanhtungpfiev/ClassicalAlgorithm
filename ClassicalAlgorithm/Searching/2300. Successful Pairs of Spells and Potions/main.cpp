/*
 * File: main.cpp
 * Project: 2300. Successful Pairs of Spells and Potions
 * File Created: Wednesday, 23rd August 2023 11:17:51 am
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
 * -----
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result;
        sort(potions.begin(), potions.end());
        for (int i = 0; i < spells.size(); ++i) {
            int index = lower_bound(potions.begin(), potions.end(), success * 1.0 / spells[i]) - potions.begin();
            result.push_back(potions.size() - index);
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}