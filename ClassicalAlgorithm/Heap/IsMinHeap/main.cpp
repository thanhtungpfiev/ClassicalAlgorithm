/*
 * File: main.cpp
 * Project: IsMinHeap
 * File Created: Wednesday, 20th July 2022 4:34:00 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>

using namespace std;

bool IsMinHeap(std::vector<int> &arr, int size)
{
    for (int i = 0; i <= (size - 2) / 2; i++)
    {
        if (2 * i + 1 < size)
        {
            if (arr[i] > arr[2 * i + 1])
            {
                return false;
            }
        }
        if (2 * i + 2 < size)
        {
            if (arr[i] > arr[2 * i + 2])
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}