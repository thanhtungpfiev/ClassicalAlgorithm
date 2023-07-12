/*
 * File: main.cpp
 * Project: FlattenBinaryTreeToLinkedList
 * File Created: Wednesday, 27th July 2022 1:26:50 pm
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
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        stack<TreeNode *> st;
        st.push(root);
        vector<TreeNode *> v;
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            if (node != nullptr)
            {
                v.push_back(node);
                st.push(node->right);
                st.push(node->left);
            }
        }
        for (int i = 0; i < v.size() - 1; ++i)
        {
            v[i]->right = v[i + 1];
            v[i]->left = nullptr;
        }
    }
};

class Solution
{
public:
    TreeNode *prev = nullptr;
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;

        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};

int main(int argc, char **argv)
{
    Solution sl;
    // Input: root = [1,2,5,3,4,null,6]
    // Output: [1,null,2,null,3,null,4,null,5,null,6]
    // Input: root = []
    // Output: []
    // Input: root = [0]
    // Output: [0]
    return 0;
}