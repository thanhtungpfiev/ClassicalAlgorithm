/*
 * File: main.cpp
 * Project: 872. Leaf-Similar Trees
 * File Created: Monday, 18th September 2023 3:41:21 pm
 * Author: Dao Thanh Tung (MS/EDA101-XC) (thanhtungpfiev@gmail.com)
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
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1, res2;
        dfs(root1, res1);
        dfs(root2, res2);
        return res1 == res2;
    }

    void dfs(TreeNode* root, vector<int> &r) {
        if (root == nullptr) {
            return;
        }
        if (!root->left && !root->right) {
            r.push_back(root->val);
            return;
        }
        if (root->left) {
            dfs(root->left, r);
        }
        if (root->right) {
            dfs(root->right, r);
        }
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    return 0;
}