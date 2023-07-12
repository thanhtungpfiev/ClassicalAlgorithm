/*
 * File: main.cpp
 * Project: MultiplyStrings
 * File Created: Thursday, 18th August 2022 3:48:59 pm
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
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        int m = num1.length();
        int n = num2.length();
        string result;
        vector<int> v(m + n - 1);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                v[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = v.size() - 1; i > 0; --i)
        {
            if (v[i] >= 10)
            {
                v[i - 1] += v[i] / 10;
                v[i] %= 10;
            }
        }
        if (v[0] >= 10)
        {
            int temp = v[0];
            v[0] %= 10;
            v.insert(v.begin(), temp / 10);
        }
        for (auto e : v)
        {
            result += to_string(e);
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: num1 = "2", num2 = "3"
    // Output: "6"

    // Input: num1 = "123", num2 = "456"
    // Output: "56088"
    return 0;
}