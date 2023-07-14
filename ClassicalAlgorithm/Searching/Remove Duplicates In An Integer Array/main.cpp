/*
 * File: main.cpp
 * Project: RemoveDuplicatesInAnIntegerArray
 * File Created: Friday, 3rd June 2022 3:52:47 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeDuplicates(std::vector<int> &data)
{
    if (data.size() == 0)
    {
        return 0;
    }
    int j = 0;
    sort(data.begin(), data.end());
    for (int i = 1; i < data.size(); i++)
    {
        if (data[i] != data[j])
        {
            j++;
            data[j] = data[i];
        }
    }
    return j + 1;
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}