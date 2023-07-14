/*
 * File: main.cpp
 * Project: Find2ndLargestNumberInAnArray
 * File Created: Thursday, 2nd June 2022 6:22:32 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find2ndLargestNumber(vector<int> &data)
{
    make_heap(data.begin(), data.end());
    return data[1];
}

int main(int argc, char **argv)
{
    vector<int> data = {12, 35, 1, 10, 34, 1};
    cout << find2ndLargestNumber(data) << endl;
    data = {10, 5, 10};
    cout << find2ndLargestNumber(data) << endl;
    data = {10, 10, 10};
    cout << find2ndLargestNumber(data) << endl;
    return 0;
}