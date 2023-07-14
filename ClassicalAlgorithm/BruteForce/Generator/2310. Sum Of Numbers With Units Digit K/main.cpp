/*
 * File: main.cpp
 * Project: SumOfNumbersWithUnitsDigitK
 * File Created: Sunday, 19th June 2022 1:39:44 pm
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minimumNumbers(int num, int k)
    {
        if (num == 0)
        {
            return 0;
        }
        int cnt = 0;
        for (int i = 1; i <= 10; ++i)
        {
            if ((i * k) % 10 == (num % 10) && (i * k <= num))
            {
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    int num = 58, k = 9;
    cout << sl.minimumNumbers(num, k) << endl;
    num = 37, k = 2;
    cout << sl.minimumNumbers(num, k) << endl;
    num = 0, k = 7;
    cout << sl.minimumNumbers(num, k) << endl;
    return 0;
}