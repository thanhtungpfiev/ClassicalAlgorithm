/*
 * File: main.cpp
 * Project: OccurrenceCountsInSortedArray
 * File Created: Wednesday, 1st June 2022 4:10:38 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findKeyCount(std::vector<int> &data, int key)
{
    return std::count(data.begin(), data.end(), key);
}

int findKeyCount2(std::vector<int> &data, int key)
{
    auto it_first = lower_bound(data.begin(), data.end(), key);
    auto it_last = upper_bound(data.begin(), data.end(), key);
    return it_last - it_first;
}

int main(int argc, char **argv)
{
    vector<int> data = {1, 2, 2, 2, 2, 2, 3, 4};
    cout << findKeyCount(data, 2) << endl;
    cout << findKeyCount2(data, 2) << endl;
    return 0;
}
