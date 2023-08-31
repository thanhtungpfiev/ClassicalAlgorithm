/*
 * File: main.cpp
 * Project: 1207. Unique Number of Occurrences
 * File Created: Wednesday, 30th August 2023 9:43:12 am
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        bool result = true;
        unordered_map<int, int> ht;
        for (auto e : arr) {
            ht[e]++;
        }
        unordered_set<int> s;
        for (auto e : ht) {
            if (s.find(e.second) != s.end()) {
                result = false;
                break;
            }
            s.insert(e.second);
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}