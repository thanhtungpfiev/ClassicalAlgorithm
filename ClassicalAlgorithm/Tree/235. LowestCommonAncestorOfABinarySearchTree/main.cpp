/*
 * File: main.cpp
 * Project: LowestCommonAncestorOfABinarySearchTree
 * File Created: Thursday, 28th July 2022 9:02:40 am
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->val > p->val && root->val > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (root->val < p->val && root->val < q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
    // Output: 6
    // Explanation: The LCA of nodes 2 and 8 is 6.
    // Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
    // Output: 2
    // Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
    // Input: root = [2,1], p = 2, q = 1
    // Output: 2
    return 0;
}