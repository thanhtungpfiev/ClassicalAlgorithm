/*
 * File: main.cpp
 * Project: PathSumIII
 * File Created: Wednesday, 24th August 2022 11:02:04 am
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
    int res = 0, sum;
    unordered_map<int, int> seen;
    void dfs(TreeNode *root, int partialSum = 0)
    {
        // updating partialSum with the current node
        partialSum += root->val;
        // checking if we already found an interval summing up to that
        res += seen[partialSum - sum];
        // updating seen
        seen[partialSum]++;
        // searching potential left and right branches
        if (root->left)
            dfs(root->left, partialSum);
        if (root->right)
            dfs(root->right, partialSum);
        // clearing seen of the last value, for backtracking purposes
        seen[partialSum]--;
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        sum = targetSum;
        // seen set with initial value 0 will help us match from the root
        seen[0] = 1;
        if (!root)
            return res;
        dfs(root);
        return res;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
    // Output: 3
    // Explanation: The paths that sum to 8 are shown.

    // Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
    // Output: 3
    return 0;
}