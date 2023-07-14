/*
 * File: main.cpp
 * Project: TransformArray
 * File Created: Thursday, 2nd June 2022 6:20:01 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>

using namespace std;

void transformArrayAB1(std::vector<int> &data)
{
    int size = data.size();
    int N = size / 2;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
            swap(data, N - i + 2 * j, N - i + 2 * j + 1);
    }
}

int main(int argc, char **argv)
{
    cout << "Hello World" << endl;
    return 0;
}