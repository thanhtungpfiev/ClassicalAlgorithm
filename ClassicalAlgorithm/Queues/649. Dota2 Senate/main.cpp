/*
 * File: main.cpp
 * Project: 649. Dota2 Senate
 * File Created: Wednesday, 6th September 2023 1:17:27 pm
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rIndices;
        queue<int> dIndices;
        int n = senate.size();
        for (int i = 0; i < senate.size(); ++i) {
            if (senate[i] == 'R') {
                rIndices.push(i);
            } else {
                dIndices.push(i);
            }
        }
        while (!rIndices.empty() && !dIndices.empty()) {
            int rIndex = rIndices.front();
            rIndices.pop();
            int dIndex = dIndices.front();
            dIndices.pop();
            if (rIndex < dIndex) {
                rIndices.push(rIndex + n);
            } else {
                dIndices.push(dIndex + n);
            }
        }
        return !rIndices.empty() ? "Radiant" : "Dire";

    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}