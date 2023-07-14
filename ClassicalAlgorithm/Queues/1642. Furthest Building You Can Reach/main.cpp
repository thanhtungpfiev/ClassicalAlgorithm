/*
 * File: main.cpp
 * Project: FurthestBuildingYouCanReach
 * File Created: Tuesday, 21st June 2022 1:57:06 pm
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
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int i = 0;
        int currentJumpHeight; // buoc nhay tu toa nha hien tai toi toa nha tiep theo
        priority_queue<int, vector<int>, greater<int>> pq;

        // Uu tien thang cho nhung buoc nhay lon nhat
        while (i < heights.size() - 1 && ladders > 0)
        {
            currentJumpHeight = heights[i + 1] - heights[i];
            if (currentJumpHeight > 0)
            {
                pq.push(currentJumpHeight);
                --ladders;
            }
            ++i;
        }

        // Thay the dan nhung buoc nhay nho nhat da su thang bang gach va thang cho buoc nhay lon hon
        while (i < heights.size() - 1)
        {
            currentJumpHeight = heights[i + 1] - heights[i];
            if (currentJumpHeight > 0)
            {
                if (!pq.empty() && currentJumpHeight > pq.top())
                {
                    bricks -= pq.top();
                    pq.pop();
                    pq.push(currentJumpHeight);
                }
                else // buoc nhay nay la nho nhat, bat buoc su dung gach
                {
                    bricks -= currentJumpHeight;
                }
                if (bricks < 0)
                {
                    return i;
                }
            }
            ++i;
        }
        return i;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}