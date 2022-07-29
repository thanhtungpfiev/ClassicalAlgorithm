/*
 * File: main.cpp
 * Project: FloodFill
 * File Created: Friday, 29th July 2022 11:06:02 am
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
    typedef pair<int, int> mPair;
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (image[sr][sc] == color)
        {
            return image;
        }
        int m = image.size();
        int n = image[0].size();
        vector<int> r = {-1, 0, 1, 0};
        vector<int> c = {0, 1, 0, -1};
        queue<mPair> q;
        q.push(make_pair(sr, sc));
        int oldColor = image[sr][sc];
        while (!q.empty())
        {
            mPair curr = q.front();
            q.pop();
            int currX = curr.first;
            int currY = curr.second;
            if (image[currX][currY] != color)
            {
                image[currX][currY] = color;
            }
            for (int i = 0; i < 4; ++i)
            {
                int newX = currX + r[i];
                int newY = currY + c[i];
                if (newX < 0 || newX >= m)
                    continue;
                if (newY < 0 || newY >= n)
                    continue;
                if (image[newX][newY] == oldColor)
                {
                    image[newX][newY] = color;
                    q.push(make_pair(newX, newY));
                }
            }
        }

        return image;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
    // Output: [[2,2,2],[2,2,0],[2,0,1]]
    // Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
    // Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

    // Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
    // Output: [[0,0,0],[0,0,0]]
    // Explanation: The starting pixel is already colored 0, so no changes are made to the image.
    return 0;
}