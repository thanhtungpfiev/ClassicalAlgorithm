/*
 * File: main.cpp
 * Project: PartitioningIntoMinimumNumberOfDeci-BinaryNumbers
 * File Created: Monday, 27th June 2022 11:03:24 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minPartitions(string n)
    {
        int result = 0;
        for (int i = 0; i < n.size(); ++i)
        {
            if (n[i] - '0' > result)
            {
                result = n[i] - '0';
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    string n = "32";
    cout << sl.minPartitions(n) << endl;
    n = "82734";
    cout << sl.minPartitions(n) << endl;
    n = "27346209830709182346";
    cout << sl.minPartitions(n) << endl;
    return 0;
}