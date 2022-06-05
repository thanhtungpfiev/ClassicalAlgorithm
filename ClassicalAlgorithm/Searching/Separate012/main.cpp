/*
 * File: main.cpp
 * Project: Separate012
 * File Created: Saturday, 4th June 2022 10:40:39 pm
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
    for (int i = 0; i < data.size(); i++)
    {
        if (i < count(data.begin(), data.end(), 0))
        {
            data[i] = 0;
        }
        else if (i >= count(data.begin(), data.end(), 0) && i < count(data.begin(), data.end(), 1))
        {
            data[i] = 1;
        }
        else
        {
            data[i] = 2;
        }
    }
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}