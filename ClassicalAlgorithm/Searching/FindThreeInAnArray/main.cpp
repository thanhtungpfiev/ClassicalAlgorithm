/*
 * File: main.cpp
 * Project: FindThreeInAnArray
 * File Created: Friday, 3rd June 2022 4:11:14 pm
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int findThree(const vector<int> &v, int target)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            for (int k = j + 1; k < v.size(); k++)
            {
                if ((v[i] + v[j] + v[k]) == target)
                {
                    cout << v[i] << " " << v[j] << " " << v[k] << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

int findThree1(const vector<int> &v, int target)
{
    for (int i = 0; i < v.size() - 2; ++i)
    {
        int currSum = target - v[i];
        unordered_set<int> ht;
        for (int j = i + 1; j < v.size(); ++j)
        {
            if (ht.find(currSum - v[j]) != ht.end())
            {
                return true;
            }
            ht.insert(v[j]);
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    vector<int> v = {1, 2, 4, 3, 6};
    int target = 10;
    cout << findThree1(v, target) << endl;
    return 0;
}