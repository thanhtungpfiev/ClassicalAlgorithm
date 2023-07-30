/*
 * File: main.cpp
 * Project: 1926. Nearest Exit from Entrance in Maze
 * File Created: Saturday, 29th July 2023 6:07:53 pm
 * Author: thanhtungpfiev (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int result = -1;
        vector<int> r = {0, -1, 0, 1};
        vector<int> c = {-1, 0, 1, 0};
        int height = maze.size();
        int width = maze[0].size();
        vector<vector<bool>> visited(height, vector<bool>(width, false));
        queue<vector<int>> q;
        visited[entrance[0]][entrance[1]] = true;
        vector<int> entrance_with_distance(entrance);
        entrance_with_distance.push_back(0);
        q.push(entrance_with_distance);
        while (!q.empty())
        {
            vector<int> u = q.front();
            q.pop();
            int d = u[2];
            // cout << "X: " << u[0] << " Y: " << u[1] << endl;
            for (int i = 0; i < r.size(); ++i)
            {
                int newX = u[0] + r[i];
                int newY = u[1] + c[i];

                if (newX < 0 || newX >= height)
                {
                    continue;
                }
                if (newY < 0 || newY >= width)
                {
                    continue;
                }
                if (visited[newX][newY])
                {
                    continue;
                }
                if (maze[newX][newY] == '+')
                {
                    continue;
                }

                // cout << "newX: " << newX << " " << "newY: " << newY << endl;
                if ((newX == 0 || newX == height - 1 || newY == 0 || newY == width - 1) && maze[newX][newY] == '.')
                {
                    result = d + 1;
                    return result;
                }

                visited[newX][newY] = true;
                q.push({newX, newY, d + 1});
            }
            // cout << "--------------------" << endl;
        }

        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}