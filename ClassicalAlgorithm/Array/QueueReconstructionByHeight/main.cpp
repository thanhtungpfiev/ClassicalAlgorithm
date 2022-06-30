/*
 * File: main.cpp
 * Project: QueueReconstructionByHeight
 * File Created: Wednesday, 29th June 2022 10:53:06 am
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
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        vector<vector<int>> queue;
        sort(people.begin(), people.end(), [](const vector<int> &people1, const vector<int> &people2)
             {
            if (people1[0] == people2[0]) {
                return people1[1] < people2[1];
            }
            return people1[0] > people2[0]; });
        for (int i = 0; i < people.size(); ++i)
        {
            queue.insert(queue.begin() + people[i][1], people[i]);
        }
        return queue;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
    // Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
    // Input: people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
    // Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
    return 0;
}