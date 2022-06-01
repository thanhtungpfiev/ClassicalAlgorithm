/*
 * File: main.cpp
 * Project: TwoElementsWhoseWumIsClosestToZero
 * File Created: Wednesday, 1st June 2022 2:54:43 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

void minabsSumPair2(std::vector<int> &data)
{
    sort(data.begin(), data.end();) int minSum, sum, minFirst, minSecond;
    int l = 0;
    int r = data.size() - 1;
    minFirst = l;
    minSecond = r;
    minSum = abs(data[minFirst] + data[minSecond]);
    while (l < r)
    {
        sum = data[l] + data[r];
        if (abs(sum) < minSum)
        {
            minSum = abs(sum);
            minFirst = l;
            minSum = r;
        }
        if (sum < 0)
        {
            l++;
        }
        else if (sum > 0)
        {
            r--;
        }
        else
        {
            break;
        }
    }
    cout << minFirst << " " << minSecond << endl;
}

int main(int argc, char **argv)
{
}
