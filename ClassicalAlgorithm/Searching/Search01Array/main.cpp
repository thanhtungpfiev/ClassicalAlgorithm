/*
 * File: main.cpp
 * Project: Search01Array
 * File Created: Thursday, 2nd June 2022 5:07:16 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BinarySearch01(std::vector<int> &data)
{
    auto it = lower_bound(data.begin(), data.end(), 1);
    if (it == data.end())
    {
        return -1;
    }
    return distance(data.begin(), it);
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}
