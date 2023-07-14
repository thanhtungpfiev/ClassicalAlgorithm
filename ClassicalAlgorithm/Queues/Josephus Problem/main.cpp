/*
 * File: main.cpp
 * Project: JosephusProblem
 * File Created: Saturday, 25th June 2022 3:14:41 pm
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int safePos(int n, int k)
    {
        // code here
        vector<int> person;
        for (int i = 1; i <= n; ++i)
        {
            person.push_back(i);
        }
        int index = 0;
        while (person.size() != 1)
        {
            index = (index + k - 1) % person.size();
            person.erase(person.begin() + index);
        }
        return person[0];
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    int n = 2, k = 1;
    cout << sl.safePos(n, k) << endl;
    n = 4, k = 2;
    cout << sl.safePos(n, k) << endl;
    return 0;
}