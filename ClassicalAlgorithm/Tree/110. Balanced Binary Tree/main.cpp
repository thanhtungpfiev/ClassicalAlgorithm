/*
 * File: main.cpp
 * Project: BalancedBinaryTree
 * File Created: Tuesday, 23rd August 2022 5:15:37 pm
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
    int dfsHeight(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftHeight = dfsHeight(root->left);
        if (leftHeight == -1)
            return -1;
        int rightHeight = dfsHeight(root->right);
        if (rightHeight == -1)
            return -1;
        if (abs(leftHeight - rightHeight) > 1)
            return -1;
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        return dfsHeight(root) != -1;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: root = [3,9,20,null,null,15,7]
    // Output: true

    // Input: root = [1,2,2,3,3,null,null,4,4]
    // Output: false

    // Input: root = []
    // Output: true
    return 0;
}