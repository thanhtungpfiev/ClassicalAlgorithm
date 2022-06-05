/*
 * File: main.cpp
 * Project: UnboundedBinarySearch
 * File Created: Sunday, 5th June 2022 8:15:25 am
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(int low, int high, const vector<int> &data)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (data[mid] > 0 && (mid == low || data[mid] < 0))
        {
            return mid;
        }
        if (data[mid] < 0)
        {
            return binarySearch(mid + 1, high, data);
        }
        else
        {
            return binarySearch(low, mid - 1, data);
        }
    }
    return -1;
}

int findFirstPositive(vector<int> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] > 0)
        {
            return i;
        }
    }
    return -1;
}

int findFirstPositive1(vector<int> &data)
{
    if (data[0] > 0)
    {
        return 0;
    }
    int i = 1;
    while (data[i] < 0)
    {
        i *= 2;
    }

    return binarySearch(i / 2, i, data);
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}