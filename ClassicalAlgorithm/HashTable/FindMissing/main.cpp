/*
 * File: main.cpp
 * Project: FindMissing
 * File Created: Tuesday, 26th July 2022 3:56:03 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>

using namespace std;

int findMissing(std::vector<int> &arr, int start, int end)
{
    std::unordered_set<int> hs;
    for (auto i : arr)
    {
        hs.insert(i);
    }
    for (int curr = start; curr <= end; curr++)
    {
        if (hs.find(curr) == hs.end())
        {
            return curr;
        }
    }
    return std::numeric_limits<int>::max();
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}