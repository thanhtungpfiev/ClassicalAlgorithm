/*
 * File: main.cpp
 * Project: ReplaceElementsInAnArray
 * File Created: Sunday, 5th June 2022 11:55:01 am
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations)
    {
        map<int, int> ht;
        for (int i = 0; i < nums.size(); ++i)
        {
            ht[nums[i]] = i;
        }
        for (int i = 0; i < operations.size(); ++i)
        {
            int number1 = operations[i][0];
            int number2 = operations[i][1];
            int index = ht[number1];
            nums[index] = number2;
            ht[number1] = -1;
            ht[number2] = index;
        }
        return nums;
    }
    void print(const vector<int> &arr) const
    {
        for (const auto &i : arr)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    vector<int> nums = {1, 2, 4, 6};
    vector<vector<int>> operations = {{1, 3},
                                      {4, 7},
                                      {6, 1}};
    sl.print(sl.arrayChange(nums, operations));
    nums = {1, 2};
    operations = {{1, 3}, {2, 1}, {3, 2}};
    sl.print(sl.arrayChange(nums, operations));
    return 0;
}