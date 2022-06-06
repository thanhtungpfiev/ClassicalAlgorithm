/*
 * File: main.cpp
 * Project: SeparateEvenAndOddNumbersInArray
 * File Created: Wednesday, 1st June 2022 4:32:39 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void seperateEvenAndOdd(std::vector<int> &data)
{
    int left = 0, right = data.size() - 1;
    while (left < right)
    {
        if (data[left] % 2 == 0)
        {
            left++;
        }
        else if (data[right] % 2 == 1)
        {
            right--;
        }
        else
        {
            swap(data[left], data[right]);
            left++;
            right--;
        }
    }
    sort(data.begin(), data.begin() + left);
    sort(data.begin() + left, data.end());
}

int main(int argc, char **argv)
{
    return 0;
}
