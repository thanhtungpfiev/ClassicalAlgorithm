/*
 * File: main.cpp
 * Project: DiameterOfBinaryTree
 * File Created: Wednesday, 24th August 2022 9:12:44 am
 * Author: tung.dao (thanhtungpfiev@gmail.com)
 * -----
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int result = 0;
        maxDepth(root, result);
        return result;
    }
    int maxDepth(TreeNode *root, int &result)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = maxDepth(root->left, result);
        int right = maxDepth(root->right, result);
        result = max(result, left + right);
        return max(left, right) + 1;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: root = [1,2,3,4,5]
    // Output: 3
    // Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

    // Input: root = [1,2]
    // Output: 1
    return 0;
}