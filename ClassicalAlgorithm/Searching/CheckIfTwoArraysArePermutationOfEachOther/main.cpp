/*
 * File: main.cpp
 * Project: CheckIfTwoArraysArePermutationOfEachOther
 * File Created: Friday, 3rd June 2022 3:26:38 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool checkPermutation(std::vector<int> &data1, std::vector<int> &data2)
{
    int size1 = data1.size();
    int size2 = data2.size();
    if (size1 != size2)
        return false;
    sort(data1.begin(), data1.end());
    sort(data2.begin(), data2.end());
    for (int i = 0; i < size1; i++)
    {
        if (data1[i] != data2[i])
            return false;
    }
    return true;
}

bool checkPermutation2(std::vector<int> &data1, std::vector<int> &data2)
{
    int size1 = data1.size();
    int size2 = data2.size();
    if (size1 != size2)
        return false;
    std::vector<int> al;
    for (int i = 0; i < size1; i++)
        al.push_back(data1[i]);
    for (int i = 0; i < size2; i++)
    {
        if (std::find(al.begin(), al.end(), data2[i]) != al.end() == false)
            return false;
        al.erase(al.begin() + data2[i]);
    }
    return true;
}

bool checkPermutation3(std::vector<int> &data1, std::vector<int> &data2)
{
    if (data1.size() != data2.size())
    {
        return false;
    }
    map<int, int> ht;
    for (int i = 0; i < data1.size(); ++i)
    {
        ht[data1[i]]++;
    }
    for (int i = 0; i < data2.size(); ++i)
    {
        if (ht[data2[i]] == 0)
        {
            return false;
        }
        ht[data2[i]]--;
    }
    return true;
}

int main(int argc, char **argv)
{
    vector<int> arr1 = {2, 1, 3, 5, 4, 3, 2};
    vector<int> arr2 = {3, 2, 2, 4, 5, 3, 1};
    cout << checkPermutation3(arr1, arr2) << endl;
    arr1 = {2, 1, 3, 5};
    arr2 = {3, 2, 2, 4};
    cout << checkPermutation3(arr1, arr2) << endl;
    return 0;
}