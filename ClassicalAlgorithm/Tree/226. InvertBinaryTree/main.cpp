/*
 * File: main.cpp
 * Project: InvertBinaryTree
 * File Created: Tuesday, 23rd August 2022 4:56:15 pm
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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
            // invert left and right pointers
            swap(node->left, node->right);
        }
        return root;
    }
};

int main(int argc, char **argv)
{
    Solution sl;

    // Input: root = [4,2,7,1,3,6,9]
    // Output: [4,7,2,9,6,3,1]

    // Input: root = [2,1,3]
    // Output: [2,3,1]

    // Input: root = []
    // Output: []
    return 0;
}