/*
 * File: main.cpp
 * Project: KeysAndRooms
 * File Created: Tuesday, 2nd August 2022 2:13:31 pm
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
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vector<bool> visited(rooms.size(), false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            auto room = rooms[node];
            for (auto &key : room)
            {
                if (visited[key] == false)
                {
                    visited[key] = true;
                    q.push(key);
                }
            }
        }
        for (int i = 0; i < visited.size(); ++i)
        {
            if (visited[i] == false)
            {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: rooms = [[1],[2],[3],[]]
    // Output: true
    // Explanation:
    // We visit room 0 and pick up key 1.
    // We then visit room 1 and pick up key 2.
    // We then visit room 2 and pick up key 3.
    // We then visit room 3.
    // Since we were able to visit every room, we return true.

    // Input: rooms = [[1,3],[3,0,1],[2],[0]]
    // Output: false
    // Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.
    // return 0;
}