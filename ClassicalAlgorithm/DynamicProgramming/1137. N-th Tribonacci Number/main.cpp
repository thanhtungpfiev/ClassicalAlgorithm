/*
 * File: main.cpp
 * Project: 1137. N-th Tribonacci Number
 * File Created: Thursday, 3rd August 2023 5:18:52 pm
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        int result = 0;
        vector<int> m(n + 1);
        if (n == 0) {
            result = 0;
        } else if (n == 1 || n == 2) {
            result = 1;
        } else {
            m[0] = 0;
            m[1] = 1;
            m[2] = 1;
            for (int i = 3; i <= n; ++i) {
                m[i] = m[i - 3] + + m[i - 2] + m[i - 1];
            }
            result = m[n];
        }

        return result;

    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}