/*
 * File: main.cpp
 * Project: 933. Number of Recent Calls
 * File Created: Thursday, 20th July 2023 1:15:31 pm
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
 * -----
 */

#include <iostream>
#include <vector>
#include <algorithm>

class RecentCounter
{
public:
    queue<int> q;
    RecentCounter()
    {
    }

    int ping(int t)
    {
        q.push(t);
        while (q.front() < t - 3000)
        {
            q.pop();
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

using namespace std;

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}