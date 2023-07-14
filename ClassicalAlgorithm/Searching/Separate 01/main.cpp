/*
 * File: main.cpp
 * Project: Separate01
 * File Created: Saturday, 4th June 2022 10:28:35 pm
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void move(vector<int> &data)
{
    sort(data.begin(), data.end());
}

void move2(vector<int> &data)
{
    int l = 0, r = data.size() - 1;
    while (l < r)
    {
        if (data[l] == 0)
        {
            l++;
        }
        else if (data[r] == 1)
        {
            r--;
        }
        else
        {
            swap(data[l], data[r]);
            l++;
            r--;
        }
    }
}

void move3(vector<int> &data)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (i < count(data.begin(), data.end(), 0))
        {
            data[i] = 0;
        }
        else
        {
            data[i] = 1;
        }
    }
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}