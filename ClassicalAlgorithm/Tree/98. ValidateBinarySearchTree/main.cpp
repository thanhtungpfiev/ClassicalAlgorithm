/*
 * File: main.cpp
 * Project: ValidateBinarySearchTree
 * File Created: Thursday, 28th July 2022 8:58:54 am
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
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode *node, long long min, long long max)
    {
        if (node == nullptr)
        {
            return true;
        }
        if (node->val <= min || node->val >= max)
        {
            return false;
        }
        return (isValidBST(node->left, min, node->val) && isValidBST(node->right, node->val, max));
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: root = [2,1,3]
    // Output: true
    // Input: root = [5,1,4,null,null,3,6]
    // Output: false
    // Explanation: The root node's value is 5 but its right child's value is 4.
    return 0;
}